
#include "Transaction.hpp"

namespace Eth{

Transaction::Transaction(const Json::Value &data) : _data(data)
{}

std::string Transaction::getHash() const
{
    return _data["hash"].asString();
}

uint64_t Transaction::getAmount() const
{
    return _data["value"].asUInt64();
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
    return _data["nonce"].asUInt64();
}

uint64_t Transaction::getGas() const
{
    return _data["gas"].asUInt64();
}

uint64_t Transaction::getGasPrice() const
{
    return _data["gasPrice"].asUInt64();
}

size_t Transaction::getBlockNumber() const
{
    return _data["blockNumber"].asUInt64();
}

size_t Transaction::getTransactionIndex() const
{
    return _data["transactionIndex"].asUInt64();
}

std::string Transaction::getBlockHash() const
{
    return _data["blockHash"].asString();
}


}
