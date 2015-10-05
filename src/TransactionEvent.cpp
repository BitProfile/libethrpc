#include "TransactionEvent.hpp"

#include <stdlib.h>

namespace Eth{

TransactionEvent::TransactionEvent(const Json::Value &data) : _data(data)
{}

std::string TransactionEvent::getType() const
{
    return _data["type"].asString();
}

std::string TransactionEvent::getTransactionHash() const
{
    return _data["transactionHash"].asString();
}

std::string TransactionEvent::getAddress() const
{
    return _data["address"].asString();
}

std::string TransactionEvent::getBlockHash() const
{
    return _data["blockHash"].asString();
}

uint64_t TransactionEvent::getTransactionIndex() const
{
    return strtoull(_data["transactionIndex"].asCString(), NULL, 16);
}

uint64_t TransactionEvent::getBlockIndex() const
{
    return strtoull(_data["blockNumber"].asCString(), NULL, 16);
}


}
