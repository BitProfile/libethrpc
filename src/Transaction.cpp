
#include "Transaction.hpp"

#include <stdlib.h>

namespace Ethereum{namespace Connector{

Transaction::Transaction(const Json::Value &data) : _data(data)
{}

std::string Transaction::getHash() const
{
    return _data["hash"].asString();
}

BigInt Transaction::getAmount() const
{
    return unhex<BigInt>(_data["value"].asCString());
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
    return unhex<size_t>(_data["nonce"].asCString());
}

BigInt Transaction::getGas() const
{
    return unhex<BigInt>(_data["gas"].asCString());
}

BigInt Transaction::getGasPrice() const
{
    return unhex<BigInt>(_data["gasPrice"].asCString());
}

size_t Transaction::getBlockNumber() const
{
    return unhex<size_t>(_data["blockNumber"].asCString());
}

size_t Transaction::getIndex() const
{
    return unhex<size_t>(_data["transactionIndex"].asCString());
}

std::string Transaction::getBlockHash() const
{
    return _data["blockHash"].asString();
}

std::string Transaction::getInput() const
{
    return _data["input"].asString();
}

}}
