
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
    std::cout<<"index = "<<block.getIndex()<<"\n";
    std::cout<<"timestamp = "<<block.getTimestamp()<<"\n";
    std::cout<<"nonce = "<<block.getNonce()<<"\n";
    std::cout<<"difficulty = "<<block.getDifficulty()<<"\n";
    std::cout<<"size = "<<block.getSize()<<"\n";
    std::cout<<"gas used = "<<block.getGasUsed()<<"\n";
    std::cout<<"gas limit = "<<block.getGasLimit()<<"\n";

    Collection<std::string> uncles = block.getUncles();
    std::cout<<"uncles: ";
    for(Collection<std::string>::Iterator it = uncles.begin(), end = uncles.end(); it!= end; ++it)
    {
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";

    Collection<std::string> transactions = block.getTransactions();
    std::cout<<"transactions : ";
    for(Collection<std::string>::Iterator it = transactions.begin(), end = transactions.end(); it!= end; ++it)
    {
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";

    return 0;
}
