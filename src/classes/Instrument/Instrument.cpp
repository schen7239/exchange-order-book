#include "../../include/Instrument/Instrument.h"

Instrument::Instrument(const std::string &asset, const EquityInstrumentType& instrumentType, const std::string &ticker) : asset(asset), instrumentType(instrumentType), ticker(ticker), orderBook(std::make_unique<OrderBook>()) {};

Instrument::Instrument(const Instrument& other) {
    this->asset = other.asset;
    this->instrumentType = other.instrumentType;
    this->ticker = other.ticker;
    this->orderBook = std::make_unique<OrderBook>(*other.orderBook);
};
// Instrument::~Instrument() {};

OrderBook* Instrument::getOrderBook() const {
    return this->orderBook.get();
}

std::string Instrument::getAsset() const {
    return this->asset;
};

EquityInstrumentType Instrument::getInstrumentType() const {
    return this->instrumentType;
};

std::string Instrument::getTicker() const {
    return this->ticker;
};