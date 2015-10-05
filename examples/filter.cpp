
#include "BlockChain.hpp"

using namespace Eth;


int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    BlockChain blockchain(provider);

    uint64_t id = blockchain.setNewFilter("0x580992b51e3925e23280efb93d3047c82f17e038");
    std::cout<<"filter id "<<id<<"\n";
    
    Collection<TransactionEvent> events = blockchain.getEvents(id);
    
    std::cout<<"events ("<<events.size()<<") : \n";
    
    for(Collection<TransactionEvent>::Iterator it = events.begin(), end= events.end(); it!= end; ++it)
    {
        std::cout<<"type: "<<it->getType()<<", transaction "<<it->getTransactionHash()<<" ("<<it->getTransactionIndex()<<") "<<" block "<<it->getBlockHash()<<" ("<<it->getBlockIndex()<<") \n";
    }

    return 0;
}

