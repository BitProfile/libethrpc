#pragma once

#include <json/value.h>
#include <cstdlib>

#include "detail/hex.hpp"

namespace Ethereum{namespace Connector{

class FilterLog
{
    public:

        FilterLog(const Json::Value &data);
        std::string getType() const;
        size_t getTransactionIndex() const;
        std::string getTransactionHash() const;
        std::string getAddress() const;
        std::string getBlockHash() const;
        size_t getBlockIndex() const;

    private:
        Json::Value _data;
};



}}
