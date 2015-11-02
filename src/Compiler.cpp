
#include "Compiler.hpp"

namespace Eth{

Compiler::Compiler(Provider &provider) :
    _provider(provider)
{}

inline std::string Compiler::compile(const char *alg, const char *code)
{

    Json::Value result;
    if(!_provider.request(alg, Arguments(code), result))
    {
        throw std::runtime_error("failed to compile");
    }
    return result.asString();
}

inline std::string Compiler::compile(const char *alg, const std::string &code)
{
    return compile(alg, code.c_str());
}

inline bool Compiler::compile(const char *alg, const char *code, std::string &result)
{
    Json::Value response;
    if(!_provider.request(alg, Arguments(code), response))
    {
        return false;
    }
    result = response.asString();
    return true;
}

inline bool Compiler::compile(const char *alg, const std::string &code, std::string &result)
{
    return compile(alg, code.c_str(), result);
}


std::string Compiler::compileLLL(const char *code)
{
    return compile("eth_compileLLL", code);
}

std::string Compiler::compileLLL(const std::string &code)
{
    return compile("eth_compileLLL", code);
}

bool Compiler::compileLLL(const char *code, std::string &result)
{
    return compile("eth_compileLLL", code, result);
}

bool Compiler::compileLLL(const std::string &code, std::string &result)
{
    return compile("eth_compileLLL", code, result);
}

std::string Compiler::compileSerpent(const char *code)
{
    return compile("eth_compileSerpent", code);
}

std::string Compiler::compileSerpent(const std::string &code)
{
    return compile("eth_compileSerpent", code);
}

bool Compiler::compileSerpent(const char *code, std::string &result)
{
    return compile("eth_compileSerpent", code, result);
}

bool Compiler::compileSerpent(const std::string &code, std::string &result)
{
    return compile("eth_compileSerpent", code, result);
}

std::string Compiler::compileSolidity(const char *code)
{
    return compile("eth_compileSolidity", code);
}

std::string Compiler::compileSolidity(const std::string &code)
{
    return compile("eth_compileSolidity", code);
}

bool Compiler::compileSolidity(const char *code, std::string &result)
{
    return compile("eth_compileSolidity", code, result);
}

bool Compiler::compileSolidity(const std::string &code, std::string &result)
{
    return compile("eth_compileSolidity", code, result);
}

}
