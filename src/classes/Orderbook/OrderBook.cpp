#include "../../include/OrderBook/OrderBook.h"
#include "../../common/utils.cpp"

OrderBook::OrderBook(){};

OrderBook::OrderBook(const OrderBook &other)
{
    for (const auto &pair : other.bid)
    {
        this->bid[pair.first] = pair.second;
    }

    for (const auto &pair : other.ask)
    {
        this->ask[pair.first] = pair.second;
    }

    for (const auto &pair : other.orderLookupTable)
    {
        std::unique_ptr<OrderReferences> lookupRef = std::make_unique<OrderReferences>(*(pair.second));
        this->orderLookupTable[pair.first] = std::move(lookupRef);
    }
}

OrderBook::~OrderBook(){};

void OrderBook::printOrderBook()
{
    std::cout << "BIDS" << std::endl;
    for (const auto &pair : this->bid)
    {
        std::cout << pair.first << std::endl;
        for (const float &order : pair.second)
        {
            std::cout << order << std::endl;
        }
    }

    std::cout << "ASKS" << std::endl;
    for (const auto &pair : this->ask)
    {
        std::cout << pair.first << std::endl;
        for (const float &order : pair.second)
        {
            std::cout << order << std::endl;
        }
    }
}

void OrderBook::buy(const OrderType &orderType, const float &price, const uint32_t &quantity)
{
    if (!PointerHelper<std::unique_ptr<OrderReferences>>::isNullPtr(this->orderLookupTable[price]) && this->orderLookupTable[price]->bidReference != this->bid.end()) {
        this->orderLookupTable[price]->bidReference->second.emplace_back(quantity);
        return;
    }

    this->bid[price].emplace_back(quantity);
    std::map<float, std::deque<uint32_t>>::iterator buyIter = this->bid.find(price);
    this->updateOrderLookupTable(price, buyIter, this->ask.end());
};

void OrderBook::sell(const OrderType &orderType, const float &price, const uint32_t &quantity)
{
    if (!PointerHelper<std::unique_ptr<OrderReferences>>::isNullPtr(this->orderLookupTable[price]) && this->orderLookupTable[price]->askReference != this->ask.end()) {
        this->orderLookupTable[price]->askReference->second.emplace_back(quantity);
        return;
    }
    this->ask[price].emplace_back(quantity);
    std::map<float, std::deque<uint32_t>>::iterator sellIter = this->ask.find(price);
    this->updateOrderLookupTable(price, this->bid.end(), sellIter);
};

void OrderBook::updateOrderLookupTable(const float &price, const std::map<float, std::deque<uint32_t>>::iterator &buyIter, const std::map<float, std::deque<uint32_t>>::iterator &sellIter)
{

    // if nullptr, we need to assign a new unique ptr to lookup data obj
    if (PointerHelper<std::unique_ptr<OrderReferences>>::isNullPtr(this->orderLookupTable[price]))
    {
        OrderReferences orderRef = OrderReferences(buyIter, sellIter);
        std::unique_ptr<OrderReferences> orderRefPtr = std::make_unique<OrderReferences>(orderRef);
        this->orderLookupTable.insert_or_assign(price, std::move(orderRefPtr));
        return;
    }
    OrderReferences *orderRef = this->orderLookupTable[price].get();

    if (buyIter != this->bid.end() && buyIter != orderRef->bidReference)
    {
        orderRef->bidReference = buyIter;
    }

    if (sellIter != this->ask.end() && sellIter != orderRef->askReference)
    {
        orderRef->askReference = sellIter;
    }
}