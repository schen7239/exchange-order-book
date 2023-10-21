#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <map>
#include <unordered_map>
#include <deque>
#include <memory>
#include <iostream>
#include <cstdint>

enum OrderType {
    AT_MARKET,
    LIMIT,
    STOP
};

struct OrderReferences {
    std::map<float, std::deque<uint32_t>  >::iterator bidReference;
    std::map<float, std::deque<uint32_t>  >::iterator askReference;
    OrderReferences(const std::map<float, std::deque<uint32_t>  >::iterator& bidReference, const std::map<float, std::deque<uint32_t> >::iterator& askReference) {
        this->bidReference = bidReference;
        this->askReference = askReference;
    }
};


class OrderBook {
    public:
        OrderBook();
        OrderBook(const OrderBook& other);
        ~OrderBook();
        void buy(const OrderType& orderType, const float& price, const uint32_t& quantity);
        void sell(const OrderType& orderType, const float& price, const uint32_t& quantity);
        void printOrderBook();
        void updateOrderLookupTable(const float &price, const std::map<float, std::deque<uint32_t>>::iterator &buyIter, const std::map<float, std::deque<uint32_t>>::iterator &sellIter);
        
    private:
        std::map<float, std::deque<uint32_t> > bid;
        std::map<float, std::deque<uint32_t> > ask;
        std::unordered_map<float, std::unique_ptr<OrderReferences> > orderLookupTable;
};

#endif // ORDERBOOK_H