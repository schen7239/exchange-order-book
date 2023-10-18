#include <iostream>

#include "./include/Instrument/Instrument.h"
#include "./include/Exchange/Exchange.h"



int main() {
    std::string name = "Steve's Exchange";
    Exchange::initializeExchange(name);
    std::unique_ptr<Exchange> e = Exchange::getExchange();
};