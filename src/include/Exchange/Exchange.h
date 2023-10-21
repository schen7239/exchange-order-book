#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>
#include "../Instrument/Instrument.h"

class Exchange {
    private:
        Exchange(const std::string& name);
        // ~Exchange();
        std::string name;
        std::unordered_map<std::string, std::unique_ptr<Instrument>> instrumentExchange;
        static std::unique_ptr<Exchange> exchange;
    
    public:
        Exchange(const Exchange& other);
        static std::pair<bool, std::string> startInstrumentTrading(std::unique_ptr<Instrument>& instrument);
        static std::pair<bool, std::string> removeInstrumentTrading(const std::string& ticker);
        static void initializeExchange(const std::string& name);
        static Exchange* getExchange();
        std::string getName() const;
};

#endif