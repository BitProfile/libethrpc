
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
    return unhex<uint64_t>(_data["value"].asCString());
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
    return unhex<uint64_t>(_data["nonce"].asCString());
}

uint64_t Transaction::getGas() const
{
    return unhex<uint64_t>(_data["gas"].asCString());
}

uint64_t Transaction::getGasPrice() const
{
    return unhex<uint64_t>(_data["gasPrice"].asCString());
}

size_t Transaction::getBlockNumber() const
{
    return unhex<uint64_t>(_data["blockNumber"].asCString());
}

size_t Transaction::getTransactionIndex() const
{
    return unhex<uint64_t>(_data["transactionIndex"].asCString());
}

std::string Transaction::getBlockHash() const
{
    return _data["blockHash"].asString();
}


}
