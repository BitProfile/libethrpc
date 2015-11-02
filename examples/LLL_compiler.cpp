
#include <iostream>

#include "Provider.hpp"
#include "Compiler.hpp"

int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    Compiler compiler(provider);
    std::string code = compiler.compileLLL("(returnlll (suicide (caller)))");
    std::cout<<"code: "<<code<<std::endl;
    return 0;
}

