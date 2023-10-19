#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <unordered_map>
#include <deque>
#include <memory>
#include <iostream>

enum OrderType {
    AT_MARKET,
    LIMIT,
    STOP
};

struct OrderReferences {
    std::map<double, std::unique_ptr<std::deque<double> > >::iterator bidReference;
    std::map<double, std::unique_ptr<std::deque<double> > >::iterator askReference;
};


class OrderBook {
    public:
        OrderBook();
        OrderBook(const OrderBook& other);
        ~OrderBook();
        void buy(const OrderType& orderType, const double& price, const int& quantity);
        void sell(const OrderType& orderType, const double& price, const int& quantity);
        void printOrderBook();
    private:
        std::unique_ptr<std::map<double, std::unique_ptr<std::deque<double> > > > bid;
        std::unique_ptr<std::map<double, std::unique_ptr<std::deque<double> > > > ask;
        std::unique_ptr<std::unordered_map<double, std::unique_ptr<OrderReferences> > > orderLookupTable;
};

#endif // ORDERBOOK_H