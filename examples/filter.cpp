
#include "Provider.hpp"
#include "FilterBuilder.hpp"
#include "Filter.hpp"

using namespace Eth;


int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");

    FilterBuilder builder(provider);

    builder.setAddress("0x1194e966965418c7d73a42cceeb254d875860356");

    Filter filter1 = builder.build();
    builder.reset();
    Filter filter2 = builder.build();
    

    std::cout<<"filter id "<<filter1.getId()<<"\n";
    std::cout<<"filter id "<<filter2.getId()<<"\n";

    sleep(2);
    Collection<FilterLog> events = filter1.getChanges();
    
    std::cout<<"events ("<<events.size()<<") : \n";
    
    for(Collection<FilterLog>::Iterator it = events.begin(), end= events.end(); it!= end; ++it)
    {
        std::cout<<"type: "<<it->getType()<<", transaction "<<it->getTransactionHash()<<" ("<<it->getTransactionIndex()<<") "<<" block "<<it->getBlockHash()<<" ("<<it->getBlockIndex()<<") \n";
    }

    return 0;
}

