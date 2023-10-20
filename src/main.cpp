#include <iostream>
#include <utility>

#include "./include/Instrument/Instrument.h"
#include "./include/Exchange/Exchange.h"



int main() {
    std::string name = "Steve's Exchange";
    Exchange::initializeExchange(name);
    Exchange* e = Exchange::getExchange();
    std::unique_ptr<Instrument> TSLA = std::make_unique<Instrument>("TSLA", EquityInstrumentType::STOCK, "TSLA");
    std::pair<bool, std::string> isTradableTicker = e->startInstrumentTrading(TSLA);
    assert(isTradableTicker.first);
    std::pair<bool, std::string> isTickerRemoved = e->removeInstrumentTrading("TSLA");
    assert(isTickerRemoved.first);
    std::unique_ptr<Instrument> TSLA2 = std::make_unique<Instrument>("TSLA2", EquityInstrumentType::STOCK, "TSLA");
    std::pair<bool, std::string> isTradableTicker2 = e->startInstrumentTrading(TSLA2);
    assert(isTradableTicker2.first);
};