#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 

#include "Provider.hpp"
#include "FilterBuilder.hpp"
#include "Filter.hpp"

using namespace Ethereum::Connector;

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        std::cout<<"usage : filter [address]"<<std::endl;
        return 1;
    }

    Provider provider; 
    provider.connect();//using default geth path

    FilterBuilder builder(provider);

    builder.setAddress(argv[1]);

    Filter filter1 = builder.build();
    builder.reset();
    Filter filter2 = builder.build();
    

    std::cout<<"filter id "<<filter1.getId()<<"\n";
    std::cout<<"filter id "<<filter2.getId()<<"\n";

    boost::this_thread::sleep(boost::posix_time::milliseconds(2000));
    Collection<FilterLog> events = filter1.getChanges();
    
    std::cout<<"events ("<<events.size()<<") : \n";
    
    for(Collection<FilterLog>::Iterator it = events.begin(), end= events.end(); it!= end; ++it)
    {
        std::cout<<"type: "<<it->getType()<<", transaction "<<it->getTransactionHash()<<" ("<<it->getTransactionIndex()<<") "<<" block "<<it->getBlockHash()<<" ("<<it->getBlockIndex()<<") \n";
    }

    return 0;
}

