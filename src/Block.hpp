#pragma once

#include <json/value.h>
#include <string>

#include "Collection.hpp"



namespace Eth{


class Block
{
    public:
        Block(const Json::Value &data);

        unsigned getIndex() const;
        std::string getHash() const;
        uint64_t getNonce() const;
        uint64_t getDifficulty() const;
        size_t getSize() const;
        time_t getTimestamp() const;

        uint64_t getGasLimit() const;
        uint64_t getGasUsed() const;

        Collection<std::string> getTransactions() const;
        Collection<std::string> getUncles() const;

    private:
        Json::Value _data;
};


}
