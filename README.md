
# Financial Asset Exchange and Order Book

Before financial assets can be traded, there must be an exchange in place to facilitate transactions between buyers and sellers. The singleton exchange class ensures that there is only one authoritative source for the order books of all tradable assets on the exchange. All orders and trades are conducted within this centralized exchange, preventing inconsistencies and discrepancies in order book information.

## Table of Contents

- [About](#about)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
- [Usage](#usage)

## About

I've started working on this Financial Asset Exchange and Order Book repository because I've always had an interest in financial markets. Leveraging my knowledge in Object-Oriented Programming, Operating Systems, Data Structures, and Algorithms, I'm implementing a common data structure used by market participants when investing in or trading assets.


## Getting Started


Currently, the code can only be executed in your local terminal. I have plans to deploy it on an AWS EC2 instance once I've refined the code and added all the necessary functionality. This repository serves as the groundwork for an idea I have for a future financial trading mocking tool. 

To begin, follow these steps: 
1. Obtain access to a C++ compiler, such as Clang or G++. 
2. Compile the code using the provided MakeFile. 
3. Experiment with the functionality by using the `main.cpp` file located in the `src` folder.

### Prerequisites

Currently, the repository solely relies on the C++ Standard Library.

## Usage

```
#include  <iostream>
#include  <utility>
#include  "./include/Instrument/Instrument.h"
#include  "./include/Exchange/Exchange.h"

int  main() {

std::string  name  =  "Steve's Exchange";

Exchange::initializeExchange(name); // initializes the singleton exchange

Exchange*  e  =  Exchange::getExchange(); // get the pointer to the exchange

std::unique_ptr<Instrument>  TSLA  =  
	std::make_unique<Instrument>("TSLA", EquityInstrumentType::STOCK, "TSLA");

std::pair<bool, std::string>  isTradableTicker  =  e->startInstrumentTrading(TSLA);

assert(isTradableTicker.first); // TSLA is now trading on the exchange

std::pair<bool, std::string>  isTickerRemoved  =  e->removeInstrumentTrading("TSLA");

assert(isTickerRemoved.first); // TSLA has stopped trading on the exchange

std::unique_ptr<Instrument>  TSLA2  =  
	std::make_unique<Instrument>("TSLA2", EquityInstrumentType::STOCK, "TSLA");

std::pair<bool, std::string>  isTradableTicker2  =  e->startInstrumentTrading(TSLA2);

assert(isTradableTicker2.first); // TSLA is now trading again

}; 
```
