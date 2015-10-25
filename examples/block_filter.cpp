
#include "Provider.hpp"
#include "BlockFilterBuilder.hpp"
#include "Filter.hpp"

using namespace Eth;


int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");

    BlockFilterBuilder builder(provider);
    Filter filter = builder.build();
    

    std::cout<<"filter id "<<filter.getId()<<"\n";

    sleep(2);
    Collection<FilterLog> events = filter.getChanges();
    
    std::cout<<"events ("<<events.size()<<") : \n";
    
    for(Collection<FilterLog>::Iterator it = events.begin(), end= events.end(); it!= end; ++it)
    {
        std::cout<<"type: "<<it->getType()<<", transaction "<<it->getTransactionHash()<<" ("<<it->getTransactionIndex()<<") "<<" block "<<it->getBlockHash()<<" ("<<it->getBlockIndex()<<") \n";
    }

    return 0;
}

