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

size_t FilterLog::getTransactionIndex() const
{
    return unhex<size_t>(_data["transactionIndex"].asCString());
}

size_t FilterLog::getBlockIndex() const
{
    return unhex<size_t>(_data["blockNumber"].asCString());
}


}}
