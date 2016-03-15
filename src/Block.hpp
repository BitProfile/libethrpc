#pragma once

#include <json/value.h>
#include <string>

#include "Collection.hpp"
#include "Transaction.hpp"
#include "detail/hex.hpp"


namespace Ethereum{namespace Connector{

class Block
{
    public:
        Block(const Json::Value &data);

        size_t getIndex() const;
        std::string getHash() const;
        std::string getMiner() const;
        size_t getNonce() const;
        size_t getDifficulty() const;
        size_t getSize() const;
        time_t getTimestamp() const;

        size_t getGasLimit() const;
        size_t getGasUsed() const;

        Collection<std::string> getTransactionsHashes() const;
        Collection<Transaction> getTransactions() const;
        Collection<std::string> getUnclesHashes() const;
        Collection<Block> getUncles() const;

    private:
        Json::Value _data;
};


}}
