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
    std::map<double, std::deque<double>  >::iterator bidReference;
    std::map<double, std::deque<double>  >::iterator askReference;
    OrderReferences(const std::map<double, std::deque<double>  >::iterator& bidReference, const std::map<double, std::deque<double> >::iterator& askReference) {
        this->bidReference = bidReference;
        this->askReference = askReference;
    }
};


class OrderBook {
    public:
        OrderBook();
        OrderBook(const OrderBook& other);
        ~OrderBook();
        void buy(const OrderType& orderType, const double& price, const int& quantity);
        void sell(const OrderType& orderType, const double& price, const int& quantity);
        void printOrderBook();
        void updateOrderLookupTable(const double &price, const std::map<double, std::deque<double>>::iterator &buyIter, const std::map<double, std::deque<double>>::iterator &sellIter);
        
    private:
        std::map<double, std::deque<double> > bid;
        std::map<double, std::deque<double> > ask;
        std::unordered_map<double, std::unique_ptr<OrderReferences> > orderLookupTable;
};

#endif // ORDERBOOK_H