#pragma once

#include <string>
#include "Provider.hpp"


namespace Ethereum{namespace Connector{

class Compiler
{
    public:

        Compiler(Provider &);

        std::string compileLLL(const char *);
        std::string compileSolidity(const char *);
        std::string compileSerpent(const char *);

        std::string compileLLL(const std::string &);
        std::string compileSolidity(const std::string &);
        std::string compileSerpent(const std::string &);

    private:

        std::string compile(const char *alg, const char *code);
        std::string compile(const char *alg, const std::string &);


    private:
        Provider &_provider;
};


}}
