#pragma once

#include "Provider.hpp"
#include "Block.hpp"
#include "Transaction.hpp"
#include "Collection.hpp"
#include "FilterLog.hpp"

namespace Ethereum{namespace Connector{

class BlockChain
{

    public:

        BlockChain(Provider &);

        bool isSyncing();
        size_t getHeight();

        Block getBlock(int);
        Block getBlock(const char *);
        Block getUncle(const char *, int);
        Block getUncle(int, int);

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

        Collection<FilterLog> getFilterChanges(unsigned id);
        Collection<FilterLog> getFilterLogs(unsigned id);

        void retrieveBlockDetails(bool);


    private:
        Provider &_provider;
        bool _fetchBlockDetails;
};


}}
