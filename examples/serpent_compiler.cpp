
#include <iostream>

#include "Provider.hpp"
#include "Compiler.hpp"

using namespace Ethereum::Connector;

int main()
{
    Provider provider;
    provider.connect(Test_Net); //using default geth path

    Compiler compiler(provider);
    std::string code = compiler.compileSerpent("/* some serpent */");
    std::cout<<"code: "<<code<<std::endl;
    return 0;
}

