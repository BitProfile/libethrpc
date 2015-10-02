#include "Block.hpp"


namespace Eth{

Block::Block(const Json::Value &data) : _data(data)
{}

unsigned Block::getIndex() const
{
    return _data["number"].asUInt64();
}

std::string Block::getHash() const
{
    return _data["hash"].asString();
}

uint64_t Block::getNonce() const
{
    return _data["nonce"].asUInt64();
}

uint64_t Block::getDifficulty() const
{
    return _data["difficulty"].asUInt64();
}

size_t Block::getSize() const
{
    return _data["size"].asUInt64();
}

time_t Block::getTimestamp() const
{
    return _data["timestamp"].asUInt64();
}

uint64_t Block::getGasLimit() const
{
    return _data["gasLimit"].asUInt64();
}

uint64_t Block::getGasUsed() const
{
    return _data["gasUsed"].asUInt64();
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
