
#include <iostream>

#include "Provider.hpp"
#include "Compiler.hpp"

using namespace Ethereum::Connector;

int main()
{
    DefaultGethPath path;
    Provider provider(path);
    Compiler compiler(provider);
    std::string code = compiler.compileLLL("(returnlll (suicide (caller)))");
    std::cout<<"code: "<<code<<std::endl;
    return 0;
}

