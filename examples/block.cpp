
#include <iostream>

#include "BlockChain.hpp"
#include "Provider.hpp"

using namespace Eth;

int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    BlockChain blockchain(provider);
    Block block = blockchain.getBlock(1);
    std::cout<<"hash = "<<block.getHash()<<"\n";

    return 0;
}
