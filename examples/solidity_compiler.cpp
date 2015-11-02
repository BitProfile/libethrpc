
#include <iostream>

#include "Provider.hpp"
#include "Compiler.hpp"

int main()
{
    Provider provider("ipc://home/vic/.ethereum/geth.ipc");
    Compiler compiler(provider);
    std::string code = compiler.compileSolidity("contract test { function multiply(uint a) returns(uint d) {   return a * 7;   } }");
    std::cout<<"code: "<<code<<std::endl;
    return 0;
}

