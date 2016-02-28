#include "Block.hpp"

#include <stdlib.h>

namespace Ethereum{namespace Connector{

Block::Block(const Json::Value &data) : _data(data)
{}


size_t Block::getIndex() const
{
    return unhex<size_t>(_data["number"].asCString());
}

std::string Block::getHash() const
{
    return _data["hash"].asString();
}

std::string Block::getMiner() const
{
    return _data["miner"].asString();
}

size_t Block::getNonce() const
{
    return unhex<size_t>(_data["nonce"].asCString());
}

size_t Block::getDifficulty() const
{
    return unhex<size_t>(_data["difficulty"].asCString());
}

size_t Block::getSize() const
{
    return unhex<size_t>(_data["size"].asCString());
}

time_t Block::getTimestamp() const
{
    return unhex<size_t>(_data["timestamp"].asCString());
}

size_t Block::getGasLimit() const
{
    return unhex<size_t>(_data["gasLimit"].asCString());
}

size_t Block::getGasUsed() const
{
    return unhex<size_t>(_data["gasUsed"].asCString());
}

Collection<Transaction> Block::getTransactions() const
{
    return Collection<Transaction>(_data["transactions"]);
}

Collection<Block> Block::getUncles() const
{
    return Collection<Block>(_data["uncles"]);
}


Collection<std::string> Block::getTransactionsHashes() const
{
    return Collection<std::string>(_data["transactions"]);
}

Collection<std::string> Block::getUnclesHashes() const
{
    return Collection<std::string>(_data["uncles"]);
}


}}
