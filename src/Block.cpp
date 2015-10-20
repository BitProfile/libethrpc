#include "Block.hpp"

#include <stdlib.h>

namespace Eth{

Block::Block(const Json::Value &data) : _data(data)
{}


unsigned Block::getIndex() const
{
    return unhex<uint32_t>(_data["number"].asCString());
}

std::string Block::getHash() const
{
    return _data["hash"].asString();
}

uint64_t Block::getNonce() const
{
    return unhex<uint64_t>(_data["nonce"].asCString());
}

uint64_t Block::getDifficulty() const
{
    return unhex<uint64_t>(_data["difficulty"].asCString());
}

size_t Block::getSize() const
{
    return unhex<uint32_t>(_data["size"].asCString());
}

time_t Block::getTimestamp() const
{
    return unhex<uint64_t>(_data["timestamp"].asCString());
}

uint64_t Block::getGasLimit() const
{
    return unhex<uint64_t>(_data["gasLimit"].asCString());
}

uint64_t Block::getGasUsed() const
{
    return unhex<uint64_t>(_data["gasUsed"].asCString());
}

Collection<std::string> Block::getTransactions() const
{
    return Collection<std::string>(_data["transactions"]);
}

Collection<std::string> Block::getUncles() const
{
    return Collection<std::string>(_data["uncles"]);
}

}
