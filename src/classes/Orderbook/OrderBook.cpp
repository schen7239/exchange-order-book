#include "../../include/OrderBook/OrderBook.h"
#include "../../common/utils.cpp"

OrderBook::OrderBook() : bid(std::make_unique<std::map<double, std::unique_ptr<std::deque<double>>>>()), ask(std::make_unique<std::map<double, std::unique_ptr<std::deque<double>>>>()), orderLookupTable(std::make_unique<std::unordered_map<double, std::unique_ptr<OrderReferences>>>()){};

OrderBook::OrderBook(const OrderBook &other)
{
    this->bid = std::make_unique<std::map<double, std::unique_ptr<std::deque<double>>>>();
    this->ask = std::make_unique<std::map<double, std::unique_ptr<std::deque<double>>>>();
    this->orderLookupTable = std::make_unique<std::unordered_map<double, std::unique_ptr<OrderReferences>>>();

    for (const auto &pair : *(other.bid))
    {
        std::unique_ptr<std::deque<double>> newDeque = std::make_unique<std::deque<double>>(*(pair.second));
        (*this->bid)[pair.first] = std::move(newDeque);
    }

    for (const auto &pair : *(other.ask))
    {
        std::unique_ptr<std::deque<double>> newDeque = std::make_unique<std::deque<double>>(*(pair.second));
        (*this->ask)[pair.first] = std::move(newDeque);
    }

    for (const auto &pair : *(other.orderLookupTable))
    {
        std::unique_ptr<OrderReferences> lookupRef = std::make_unique<OrderReferences>(*(pair.second));
        (*this->orderLookupTable)[pair.first] = std::move(lookupRef);
    }
}

OrderBook::~OrderBook(){};

void OrderBook::printOrderBook()
{
    std::cout << "BIDS" << std::endl;
    for (const auto &pair : *(this->bid))
    {
        std::cout << pair.first << std::endl;
        for (const double &order : *pair.second)
        {
            std::cout << order << std::endl;
        }
    }

    std::cout << "ASKS" << std::endl;
    for (const auto &pair : *(this->ask))
    {
        std::cout << pair.first << std::endl;
        for (const double &order : *pair.second)
        {
            std::cout << order << std::endl;
        }
    }
}

void OrderBook::buy(const OrderType &orderType, const double &price, const int &quantity)
{

    // in nullptr, you need to get the iterator to store in the lookup table
    if (PointerHelper<std::unique_ptr<std::deque<double>>>::isNullPtr((*this->bid)[price]))
    {
        std::deque<double> deque;
        deque.emplace_back(quantity);
        std::unique_ptr<std::deque<double>> dequePtr = std::make_unique<std::deque<double>>(deque);
        const auto [buyIter, isInsertionSuccessful] = this->bid->insert_or_assign(price, std::move(dequePtr));
    }
    
};

void OrderBook::sell(const OrderType &orderType, const double &price, const int &quantity){
    // add quantity to the ask
    // (*(*this->ask)[price])
};