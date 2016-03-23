#include "ContractFactory.hpp"


namespace Ethereum{namespace Connector{


ContractFactory::ContractFactory(Provider &provider) :  
    _provider(provider),
    _watcher(provider)
{}



Contract ContractFactory::at(const std::string &address)
{
    return Contract(_provider, address);
}


Contract ContractFactory::deploy(const std::string &from, const std::string &code)
{
    std::string tx = sendTransaction(from, code);
    return _watcher.watch(tx);
}


Contract ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args)
{
    return deploy(from, code+args.toHex());
}


std::string ContractFactory::sendTransaction(const std::string &from, const std::string &code)
{
    GasEstimator estimator(_provider);
    Json::Value request;
    request["from"] = from;
    request["data"] = code;

    Json::Value estimation = _provider.request("eth_estimateGas", request);
    request["gas"] = estimation.asString();
    Json::Value tx = _provider.request("eth_sendTransaction", request);

    return tx.asString();
}


}}
