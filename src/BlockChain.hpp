#pragma once

#include "Provider.hpp"
#include "Block.hpp"
#include "Transaction.hpp"
#include "Collection.hpp"
#include "TransactionEvent.hpp"

namespace Eth{


class BlockChain
{

    public:

        BlockChain(Provider &);

        bool isSyncing();
        size_t getHeight();

        Block getBlock(size_t);
        Block getBlock(const char *);
        Block getUncle(const char *, size_t);
        Block getUncle(size_t, size_t);

        Transaction getTransaction(const char *);
        Transaction getBlockTransaction(const char *, size_t);
        Transaction getBlockTransaction(size_t, size_t);

        size_t getBlockTransactionsCount(size_t blockNumber);
        size_t getBlockTransactionsCount(const char *blockHash);
        size_t getTransactionsCount(const char *address);
        size_t getBlockUnclesCount(size_t blockNumber);
        size_t getBlockUnclesCount(const char *blockHash);

        unsigned setNewFilter(const char *address, size_t fromBlock=0, size_t toBlock=0);
        void removeFilter(unsigned id);

        Collection<TransactionEvent> getEvents(unsigned id);


    private:
        Provider &_provider;
};


}
