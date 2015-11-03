#include "FilterLog.hpp"

namespace Ethereum{namespace Connector{

FilterLog::FilterLog(const Json::Value &data) : _data(data)
{}

std::string FilterLog::getType() const
{
    return _data["type"].asString();
}

std::string FilterLog::getTransactionHash() const
{
    return _data["transactionHash"].asString();
}

std::string FilterLog::getAddress() const
{
    return _data["address"].asString();
}

std::string FilterLog::getBlockHash() const
{
    return _data["blockHash"].asString();
}

uint64_t FilterLog::getTransactionIndex() const
{
    return strtoull(_data["transactionIndex"].asCString(), NULL, 16);
}

uint64_t FilterLog::getBlockIndex() const
{
    return strtoull(_data["blockNumber"].asCString(), NULL, 16);
}


}}
