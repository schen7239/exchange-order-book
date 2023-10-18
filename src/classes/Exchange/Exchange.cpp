#include "../../include/Exchange/Exchange.h"

Exchange::Exchange(const std::string &name) : name(name){};

Exchange::Exchange(const Exchange &other)
{
    this->name = other.name;
    for (const auto &pair : other.instrumentExchange)
    {
        this->instrumentExchange[pair.first] = std::make_unique<Instrument>(*pair.second);
    }
}

std::unique_ptr<Exchange> Exchange::exchange = nullptr;

std::unique_ptr<Instrument> Exchange::startInstrumentTrading(std::unique_ptr<Instrument> &instrument)
{
    return std::move(instrument);
};

void Exchange::initializeExchange(std::string &name)
{
    if (Exchange::exchange)
        return;
    Exchange exchange = Exchange(name);
    Exchange::exchange = std::make_unique<Exchange>(exchange);
};

std::unique_ptr<Exchange> Exchange::getExchange()
{
    if (!Exchange::exchange) return nullptr;
    return std::move(Exchange::exchange);
};

std::string Exchange::getName() const
{
    return this->name;
}