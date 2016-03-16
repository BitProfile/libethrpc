
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Ethereum::Connector;

int main(int argc, char **argv)
{
    if(argc<2)
    {
        std::cout<<"usage: block [blockNumber]"<<std::endl;
        exit(1);
    }
    Provider provider;
    provider.connect(Test_Net); //using default geth path

    BlockChain blockchain(provider);
    Block block = blockchain.getBlock(atoll(argv[1]));

    std::cout<<"hash = "<<block.getHash()<<"\n";
    std::cout<<"index = "<<block.getIndex()<<"\n";
    std::cout<<"timestamp = "<<block.getTimestamp()<<"\n";
    std::cout<<"nonce = "<<block.getNonce()<<"\n";
    std::cout<<"difficulty = "<<block.getDifficulty()<<"\n";
    std::cout<<"size = "<<block.getSize()<<"\n";
    std::cout<<"gas used = "<<block.getGasUsed()<<"\n";
    std::cout<<"gas limit = "<<block.getGasLimit()<<"\n";

    Collection<std::string> uncles = block.getUnclesHashes();
    std::cout<<"uncles: ";
    for(Collection<std::string>::Iterator it = uncles.begin(), end = uncles.end(); it!= end; ++it)
    {
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";

    Collection<std::string> transactions = block.getTransactionsHashes();
    std::cout<<"transactions : ";
    for(Collection<std::string>::Iterator it = transactions.begin(), end = transactions.end(); it!= end; ++it)
    {
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";

    return 0;
}
