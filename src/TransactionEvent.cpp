#include "TransactionEvent.hpp"


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
    return _data["transactionIndex"].asUInt64();
}

uint64_t TransactionEvent::getBlockIndex() const
{
    return _data["blockNumber"].asUInt64();
}


}
