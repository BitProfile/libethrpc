
#include <iostream>

#include "Wallet.hpp"
#include "Provider.hpp"

using namespace Ethereum::Connector;

int main()
{
    Provider provider;
    provider.connect(Test_Net); //using default geth path

    Wallet wallet(provider);
    Collection<std::string> accounts = wallet.getAccounts();
    for(Collection<std::string>::Iterator it=accounts.begin(); it!=accounts.end(); ++it)
    {
        std::cout<<"account : "<<*it<<std::endl;
    }
    

    return 0;
}
