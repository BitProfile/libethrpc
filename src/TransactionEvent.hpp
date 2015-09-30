#pragma once

#include <json/value.h>
#include <stdint.h>

namespace Eth{


class TransactionEvent
{
    public:

        TransactionEvent(const Json::Value &data);
        std::string getType() const;
        uint64_t getTransactionIndex() const;
        std::string getTransactionHash() const;
        std::string getAddress() const;
        std::string getBlockHash() const;
        uint64_t getBlockIndex() const;

    private:
        Json::Value _data;
};



}
