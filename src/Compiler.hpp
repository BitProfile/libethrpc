#pragma once

#include <string>
#include "Provider.hpp"


namespace Eth{


class Compiler
{
    public:

        Compiler(Provider &);

        std::string compileLLL(const char *);
        std::string compileSolidity(const char *);
        std::string compileSerpent(const char *);


        bool compileLLL(const char *, std::string &);
        bool compileSolidity(const char *, std::string &);
        bool compileSerpent(const char *, std::string &);


        bool compileLLL(const std::string &, std::string &);
        bool compileSolidity(const std::string &, std::string &);
        bool compileSerpent(const std::string &, std::string &);


        std::string compileLLL(const std::string &);
        std::string compileSolidity(const std::string &);
        std::string compileSerpent(const std::string &);

    private:

        std::string compile(const char *alg, const char *code);
        std::string compile(const char *alg, const std::string &);

        bool compile(const char *alg, const char *code, std::string &result);
        bool compile(const char *alg, const std::string &code, std::string &result);

    private:
        Provider &_provider;
};


}
