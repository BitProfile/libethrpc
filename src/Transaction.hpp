#pragma once

#include <json/value.h>
#include <string>
#include <stdint.h>

#include "BigInt.hpp"

#include "hex.hpp"


namespace Ethereum{namespace Connector{


class Transaction
{
    public:
        Transaction(const Json::Value &);
        std::string getHash() const;
        BigInt getAmount() const;
        std::string getSender() const;
        std::string getReceiver() const;
        size_t getNonce() const;
        uint64_t getGas() const;
        uint64_t getGasPrice() const;
        
        size_t getBlockNumber() const;
        size_t getIndex() const;
        std::string getBlockHash() const;

        std::string getInput() const;

    private:
        Json::Value _data;
};


}}
