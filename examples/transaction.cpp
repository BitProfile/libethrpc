
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Ethereum::Connector;

int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    BlockChain blockchain(provider);
    Transaction transaction = blockchain.getBlockTransaction(329513, 1);

    std::cout<<"hash : "<<transaction.getHash()<<std::endl;
    std::cout<<"nonce : "<<transaction.getNonce()<<std::endl;
    std::cout<<"from : "<<transaction.getSender()<<std::endl;
    std::cout<<"to : "<<transaction.getReceiver()<<std::endl;
    std::cout<<"amount : "<<transaction.getAmount()<<std::endl;
    std::cout<<"gas : "<<transaction.getGas()<<std::endl;
    std::cout<<"gas price : "<<transaction.getGasPrice()<<std::endl;

    return 0;
}
