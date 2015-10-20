#pragma once

#include <json/value.h>
#include <string>
#include <stdint.h>
#include "hex.hpp"

namespace Eth{



class Transaction
{
    public:
        Transaction(const Json::Value &);
        std::string getHash() const;
        uint64_t getAmount() const;
        std::string getSender() const;
        std::string getReceiver() const;
        size_t getNonce() const;
        uint64_t getGas() const;
        uint64_t getGasPrice() const;
        
        size_t getBlockNumber() const;
        size_t getTransactionIndex() const;
        std::string getBlockHash() const;

    private:
        Json::Value _data;
};


}
