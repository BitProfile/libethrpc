#pragma once

#include <json/value.h>
#include <string>

#include "Collection.hpp"
#include "Transaction.hpp"
#include "hex.hpp"


namespace Ethereum{namespace Connector{

class Block
{
    public:
        Block(const Json::Value &data);

        unsigned getIndex() const;
        std::string getHash() const;
        std::string getMiner() const;
        uint64_t getNonce() const;
        uint64_t getDifficulty() const;
        size_t getSize() const;
        time_t getTimestamp() const;

        uint64_t getGasLimit() const;
        uint64_t getGasUsed() const;

        Collection<std::string> getTransactionsHashes() const;
        Collection<Transaction> getTransactions() const;
        Collection<std::string> getUnclesHashes() const;
        Collection<Block> getUncles() const;

    private:
        Json::Value _data;
};


}}
