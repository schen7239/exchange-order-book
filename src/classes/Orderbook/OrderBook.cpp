#include "../../include/OrderBook/OrderBook.h"

OrderBook::OrderBook() : orders(std::make_unique<std::unordered_map<int, std::unique_ptr<std::queue<int> > > >()) {} ;

OrderBook::OrderBook(const OrderBook& other) {
    this->orders = std::make_unique<std::unordered_map<int, std::unique_ptr<std::queue<int> > > >();
    
    for (const auto& pair : *other.orders) {
        std::unique_ptr<std::queue<int>> newQueue = std::make_unique<std::queue<int>>(*(pair.second));
        (*this->orders)[pair.first] = std::move(newQueue);
    }
}

OrderBook::~OrderBook() {};

void OrderBook::buy(const OrderType& orderType, const int& price, const int& quantity) {
    return;
};

void OrderBook::sell(const OrderType& orderType, const int& price, const int& quantity) {
    return;
};