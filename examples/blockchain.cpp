
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Ethereum::Connector;

int main()
{
    Provider provider;
    provider.connect(Test_Net);  //using default geth path

    BlockChain blockchain(provider);
    size_t height = blockchain.getHeight();

    std::cout<<"blockchain height : "<<height<<std::endl;

    std::string address = "0x0214df0a79136dc37009906a00483592f6c7e212";

    for(int i=height; i>=0; i--)
    {
        size_t totalTransactions = blockchain.getBlockTransactionsCount(i);
        for(size_t j=0; j<totalTransactions; j++)
        {
            Transaction transaction = blockchain.getBlockTransaction(i, j);
            std::string sender = transaction.getSender();
            std::string receiver = transaction.getReceiver();
            std::cout<<'.';

            if(sender==address || receiver==address)
            {
                std::cout<<std::endl;
                std::cout<<"transaction "<<j<<std::endl;
                std::cout<<"sender : "<<sender<<std::endl;
                std::cout<<"amount : "<<transaction.getAmount()<<std::endl;
                std::cout<<"hash : "<<transaction.getHash()<<std::endl;
                std::cout<<"receiver : "<<receiver<<std::endl;
                std::cout<<"input : "<<transaction.getInput()<<std::endl;
            }
        }
    }

    return 0;
}
