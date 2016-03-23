#include "Contract.hpp"

#ifdef __ABI_ENABLED__

namespace Ethereum{namespace Connector{


Contract::Contract(Provider &provider, const std::string &address) : 
    Base(address, ContractInvoker(provider))
{}


ContractInvoker::ContractInvoker(Provider &provider) : 
    _provider(provider)
{}


std::string ContractInvoker::execute(const std::string &to, const std::string &code)
{
    return execute(getDefaultAddress(), to, code);
}


std::string ContractInvoker::execute(const std::string &from, const std::string &to, const std::string &code)
{
    GasEstimator estimator(_provider);
    BigInt gas = estimator.estimate(from, to, BigInt(0), code);
    Json::Value result = _provider.request("eth_sendTransaction", TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), gas, 0));
    return result.asString();
}

std::string ContractInvoker::execute(const std::string &to, const std::string &code, const BigInt &gas)
{
    return execute(getDefaultAddress(), to, code, gas);
}


std::string ContractInvoker::execute(const std::string &from, const std::string &to, const std::string &code, const BigInt &gas)
{
    Json::Value result = _provider.request("eth_sendTransaction", TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), gas, 0));
    return result.asString();
}


std::string ContractInvoker::call(const std::string &to, const std::string &code)
{
    return call(getDefaultAddress(), to, code);
}


std::string ContractInvoker::call(const std::string &from, const std::string &to, const std::string &code)
{
    Json::Value result = _provider.request("eth_call", TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), 0));
    return result.asString();
}


std::string ContractInvoker::getDefaultAddress()
{
    Json::Value result = _provider.request("eth_coinbase");
    return result.asString();
}



}}

#endif
