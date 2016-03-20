
#include "Compiler.hpp"

namespace Ethereum{namespace Connector{

Compiler::Compiler(Provider &provider) :
    _provider(provider)
{}

inline std::string Compiler::compile(const char *alg, const char *code)
{

    Json::Value result = _provider.request(alg, Arguments(code));
    return result.asString();
}

inline std::string Compiler::compile(const char *alg, const std::string &code)
{
    return compile(alg, code.c_str());
}



std::string Compiler::compileLLL(const char *code)
{
    return compile("eth_compileLLL", code);
}

std::string Compiler::compileLLL(const std::string &code)
{
    return compile("eth_compileLLL", code);
}

std::string Compiler::compileSerpent(const char *code)
{
    return compile("eth_compileSerpent", code);
}

std::string Compiler::compileSerpent(const std::string &code)
{
    return compile("eth_compileSerpent", code);
}

std::string Compiler::compileSolidity(const char *code)
{
    return compile("eth_compileSolidity", code);
}

std::string Compiler::compileSolidity(const std::string &code)
{
    return compile("eth_compileSolidity", code);
}


}}
