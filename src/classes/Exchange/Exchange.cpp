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

std::shared_ptr<Exchange> Exchange::exchange = nullptr;

std::pair<bool, std::string> Exchange::startInstrumentTrading(std::unique_ptr<Instrument> &instrument)
{
    std::shared_ptr<Exchange> exchange = Exchange::getExchange();
    if (!instrument)
    {
        // instrument is null
        return std::make_pair<bool, std::string>(false, "Instrument is null");
    }
    if (!exchange)
    {
        // exchange is null
        return std::make_pair<bool, std::string>(false, "Exchange is null");
    }

    const std::string &ticker = instrument->getTicker();
    if (exchange->instrumentExchange.find(ticker) != exchange->instrumentExchange.end())
    {
        // An instrument with the same ticker already exists in the exchange
        return std::make_pair<bool, std::string>(false, "Instrument with the same ticker already exists");
    }
    exchange->instrumentExchange[ticker] = std::move(instrument);
    return std::make_pair(true, ticker);
};

std::pair<bool, std::string> Exchange::removeInstrumentTrading(const std::string &ticker)
{
    std::shared_ptr<Exchange> exchange = Exchange::getExchange();
    if (exchange->instrumentExchange.find(ticker) == exchange->instrumentExchange.end())
        return std::make_pair(false, ticker);
    exchange->instrumentExchange.erase(ticker);
    return std::make_pair(true, "Ticker " + ticker + " removed!");
};

void Exchange::initializeExchange(const std::string &name)
{
    if (Exchange::exchange)
        return;
    Exchange exchange = Exchange(name);
    Exchange::exchange = std::make_unique<Exchange>(exchange);
};

std::shared_ptr<Exchange> Exchange::getExchange()
{
    if (!Exchange::exchange)
        return nullptr;
    return Exchange::exchange;
};

std::string Exchange::getName() const
{
    return this->name;
}