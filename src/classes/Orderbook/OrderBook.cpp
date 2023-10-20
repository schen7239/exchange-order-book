#include "../../include/OrderBook/OrderBook.h"

OrderBook::OrderBook() : bid(std::make_unique<std::map<double, std::unique_ptr<std::deque<double> > > >()), ask(std::make_unique<std::map<double, std::unique_ptr<std::deque<double> > > >()), orderLookupTable(std::make_unique<std::unordered_map<double, std::unique_ptr<OrderReferences> > >()) {} ;

OrderBook::OrderBook(const OrderBook& other) {
    this->bid = std::make_unique<std::map<double, std::unique_ptr<std::deque<double> > > >();
    this->ask = std::make_unique<std::map<double, std::unique_ptr<std::deque<double> > > >();
    this->orderLookupTable = std::make_unique<std::unordered_map<double, std::unique_ptr<OrderReferences> > >();

    for (const auto& pair : *(other.bid)) {
        std::unique_ptr<std::deque<double>> newDeque = std::make_unique<std::deque<double>>(*(pair.second));
        (*this->bid)[pair.first] = std::move(newDeque);
    }

    for (const auto& pair : *(other.ask)) {
        std::unique_ptr<std::deque<double>> newDeque = std::make_unique<std::deque<double>>(*(pair.second));
        (*this->ask)[pair.first] = std::move(newDeque);
    }

    for (const auto& pair : *(other.orderLookupTable)) {
        std::unique_ptr<OrderReferences> lookupRef = std::make_unique<OrderReferences>(*(pair.second));
        (*this->orderLookupTable)[pair.first] = std::move(lookupRef);
    }

}

OrderBook::~OrderBook() {};

void OrderBook::printOrderBook() {
    std::cout << "BIDS" << std::endl;

    for (const auto& pair : *(this->bid)) {
        
    }
}

void OrderBook::buy(const OrderType& orderType, const double& price, const int& quantity) {
    return;
};

void OrderBook::sell(const OrderType& orderType, const double& price, const int& quantity) {
    return;
};