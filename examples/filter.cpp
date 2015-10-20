
#include "BlockChain.hpp"

using namespace Eth;


int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    BlockChain blockchain(provider);

    uint64_t id = blockchain.setNewFilter("0x1194e966965418c7d73a42cceeb254d875860356", 1);
    std::cout<<"filter id "<<id<<"\n";

    sleep(2);
    Collection<FilterLog> events = blockchain.getFilterChanges(id);
    
    std::cout<<"events ("<<events.size()<<") : \n";
    
    for(Collection<FilterLog>::Iterator it = events.begin(), end= events.end(); it!= end; ++it)
    {
        std::cout<<"type: "<<it->getType()<<", transaction "<<it->getTransactionHash()<<" ("<<it->getTransactionIndex()<<") "<<" block "<<it->getBlockHash()<<" ("<<it->getBlockIndex()<<") \n";
    }

    return 0;
}

