#include <iostream>
#include <utility>
#include <memory>

#include "./include/Instrument/Instrument.h"
#include "./include/Exchange/Exchange.h"
#include "./common/utils.cpp"



int main() {
    std::string exchangeName = "Steve";
    Exchange::initializeExchange(exchangeName);
    Exchange* e = Exchange::getExchange();
    std::unique_ptr<Instrument> TSLA = std::make_unique<Instrument>("TSLA", EquityInstrumentType::ETF, "TSLA");
    OrderBook* o = TSLA->getOrderBook();
    o->buy(OrderType::AT_MARKET, 20, 20);
    o->sell(OrderType::AT_MARKET, 20, 40);
    o->buy(OrderType::AT_MARKET, 20, 40);
    o->printOrderBook();
}