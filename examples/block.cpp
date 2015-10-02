
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Eth;

int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    BlockChain blockchain(provider);
    Block block = blockchain.getBlock(94);
    std::cout<<"hash = "<<block.getHash()<<"\n";
    Collection<std::string> uncles = block.getUncles();
    std::cout<<"uncles: ";
    for(Collection<std::string>::Iterator it = uncles.begin(), end = uncles.end(); it!= end; ++it)
    {
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";
    return 0;
}
