
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Ethereum::Connector;

int main(int argc, char **argv)
{
    if(argc < 3)
    {
        std::cout<<"usage : transaction [block] [index]"<<std::endl;
        exit(1);
    }

    Provider provider;
    provider.connect();  //using default geth path

    BlockChain blockchain(provider);
    Transaction transaction = blockchain.getBlockTransaction(atol(argv[1]), atol(argv[2]));

    std::cout<<"hash : "<<transaction.getHash()<<std::endl;
    std::cout<<"nonce : "<<transaction.getNonce()<<std::endl;
    std::cout<<"from : "<<transaction.getSender()<<std::endl;
    std::cout<<"to : "<<transaction.getReceiver()<<std::endl;
    std::cout<<"amount : "<<transaction.getAmount()<<std::endl;
    std::cout<<"gas : "<<transaction.getGas()<<std::endl;
    std::cout<<"gas price : "<<transaction.getGasPrice()<<std::endl;

    return 0;
}
