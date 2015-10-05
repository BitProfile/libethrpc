
#include "Transaction.hpp"

#include <stdlib.h>

namespace Eth{

Transaction::Transaction(const Json::Value &data) : _data(data)
{}

std::string Transaction::getHash() const
{
    return _data["hash"].asString();
}

uint64_t Transaction::getAmount() const
{
    return strtoull(_data["value"].asCString(), NULL, 16);
}

std::string Transaction::getSender() const
{
    return _data["from"].asString();
}

std::string Transaction::getReceiver() const
{
    return _data["to"].asString();
}

size_t Transaction::getNonce() const
{
    return strtoul(_data["nonce"].asCString(), NULL, 16);
}

uint64_t Transaction::getGas() const
{
    return strtoull(_data["gas"].asCString(), NULL, 16);
}

uint64_t Transaction::getGasPrice() const
{
    return strtoull(_data["gasPrice"].asCString(), NULL, 16);
}

size_t Transaction::getBlockNumber() const
{
    return strtoul(_data["blockNumber"].asCString(), NULL, 16);
}

size_t Transaction::getTransactionIndex() const
{
    return strtoul(_data["transactionIndex"].asCString(), NULL, 16);
}

std::string Transaction::getBlockHash() const
{
    return _data["blockHash"].asString();
}


}
