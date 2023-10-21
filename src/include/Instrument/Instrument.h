#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <map>
#include <stdio.h>
#include <memory>

#include "../../include/OrderBook/OrderBook.h"

enum EquityInstrumentType {
    FUTURES,
    STOCK,
    OPTIONS,
    ETF,
};

class Instrument {
    private:
        std::string asset;
        EquityInstrumentType instrumentType;
        std::string ticker;
        std::unique_ptr<OrderBook> orderBook;
    public:
        Instrument(const std::string& asset, const EquityInstrumentType& instrumentType, const std::string& ticker);
        Instrument(const Instrument& other);
        // ~Instrument();
        std::string getAsset() const;
        EquityInstrumentType getInstrumentType() const;
        std::string getTicker() const;
        OrderBook* getOrderBook() const;
};

#endif // INSTRUMENT_H