#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <unordered_map>
#include <queue>
#include <memory>

#include "../../common/types/OrderBook.cpp"

class OrderBook {
    public:
        OrderBook();
        OrderBook(const OrderBook& other);
        ~OrderBook();
        void buy(const OrderType& orderType, const int& price, const int& quantity);
        void sell(const OrderType& orderType, const int& price, const int& quantity);
    private:
        std::unique_ptr<std::unordered_map<int, std::unique_ptr<std::queue<int> > > > orders;
};

#endif // ORDERBOOK_H