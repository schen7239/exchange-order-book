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
    std::cout << std::boolalpha << isTradableTicker.first << " " << isTradableTicker.second << std::endl;
    std::pair<bool, std::string> isTickerRemoved = e->removeInstrumentTrading("TSLA");
    std::cout << std::boolalpha << isTickerRemoved.first << " " << isTickerRemoved.second << std::endl;
    std::unique_ptr<Instrument> TSLA2 = std::make_unique<Instrument>("TSLA2", EquityInstrumentType::STOCK, "TSLA");
    std::pair<bool, std::string> isTradableTicker2 = e->startInstrumentTrading(TSLA2);
    std::cout << std::boolalpha << isTradableTicker2.first << " " << isTradableTicker2.second << std::endl;
};