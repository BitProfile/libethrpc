#include "Block.hpp"

#include <stdlib.h>

namespace Eth{

Block::Block(const Json::Value &data) : _data(data)
{}


unsigned Block::getIndex() const
{
    return strtoul(_data["number"].asCString(), NULL, 16);
}

std::string Block::getHash() const
{
    return _data["hash"].asString();
}

uint64_t Block::getNonce() const
{
    return strtoull(_data["nonce"].asCString(), NULL, 16);
}

uint64_t Block::getDifficulty() const
{
    return strtoull(_data["difficulty"].asCString(),NULL, 16);
}

size_t Block::getSize() const
{
    return strtoul(_data["size"].asCString(),NULL, 16);
}

time_t Block::getTimestamp() const
{
    return strtoull(_data["timestamp"].asCString(), NULL, 16);
}

uint64_t Block::getGasLimit() const
{
    return strtoull(_data["gasLimit"].asCString(), NULL, 16);
}

uint64_t Block::getGasUsed() const
{
    return strtoull(_data["gasUsed"].asCString(), NULL, 16);
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
