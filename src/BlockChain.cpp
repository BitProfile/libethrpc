
#include "BlockChain.hpp"

namespace Eth{


BlockChain::BlockChain(Provider &provider) :
    _provider(provider)
{}

bool BlockChain::isSyncing()
{
    Json::Value result = _provider.request("eth_isSyncing");
    if(result.isBool())
    {
        return result.asBool();
    }
    return true;
}

size_t BlockChain::getHeight()
{
    Json::Value result = _provider.request("eth_blockNumber");
    return result.asUInt();
}

Block BlockChain::getBlock(size_t number)
{
    return Block(_provider.request("eth_getBlockByNumber", Arguments(hex(number), false)));
}


Block BlockChain::getBlock(const char *hash)
{
    return Block(_provider.request("eth_getBlockByHash", Arguments(hash, false)));
}

Block BlockChain::getUncle(const char *blockHash, size_t index)
{
    return Block(_provider.request("eth_getUncleByBlockHashAndIndex", Arguments(blockHash, hex(index))));
}

Block BlockChain::getUncle(size_t blockNumber, size_t index)
{
    return Block(_provider.request("eth_getUncleByBlockNumberAndIndex", Arguments(hex(blockNumber), hex(index))));
}

Transaction BlockChain::getTransaction(const char *hash)
{
    return Transaction(_provider.request("eth_getTransactionByHash", Arguments(hash)));
}

Transaction BlockChain::getBlockTransaction(const char *blockHash, size_t index)
{
    return Transaction(_provider.request("eth_getTransactionByBlockHashAndIndex", Arguments(blockHash, hex(index))));
}

Transaction BlockChain::getBlockTransaction(size_t blockNumber, size_t index)
{
    return Transaction(_provider.request("eth_getTransactionByBlockNumberAndIndex", Arguments(hex(blockNumber), hex(index))));
}

size_t BlockChain::getBlockTransactionsCount(size_t blockNumber)
{
    Json::Value result = _provider.request("eth_getBlockTransactionCountByNumber", Arguments(hex(blockNumber)));
    return result.asUInt();
}

size_t BlockChain::getBlockTransactionsCount(const char *hash)
{
    Json::Value result = _provider.request("eth_getBlockTransactionCountByHash", Arguments(hash));
    return result.asUInt();
}

size_t BlockChain::getBlockUnclesCount(size_t blockNumber)
{
    Json::Value result = _provider.request("eth_getUncleCountByBlockNumber", Arguments(hex(blockNumber)));
    return result.asUInt();
}

size_t BlockChain::getBlockUnclesCount(const char *hash)
{
    Json::Value result = _provider.request("eth_getUncleCountByBlockHash", Arguments(hash));
    return result.asUInt();
}


size_t BlockChain::getTransactionsCount(const char *address)
{
    Json::Value result = _provider.request("eth_getTransactionCount", Arguments(address));
    return result.asUInt();
}



}
