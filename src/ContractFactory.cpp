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


Contract ContractFactory::deploy(const std::string &from, const std::string &code, const std::string &password)
{
    std::string tx = sendTransaction(from, code, password);
    return _watcher.watch(tx);
}


Contract ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const std::string &password)
{
    return deploy(from, code+args.toHex(), password);
}


Contract ContractFactory::deploy(const std::string &code, const std::string &password)
{
    return deploy(getDefaultAddress(), code, password);
}


Contract ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const std::string &password)
{
    return deploy(getDefaultAddress(), code, args, password);
}


Contract ContractFactory::deploy(const std::string &from, const std::string &code, const BigInt &gas, const std::string &password)
{
    std::string tx = sendTransaction(from, code, gas, password);
    return _watcher.watch(tx);
}


Contract ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const std::string &password)
{
    return deploy(from, code+args.toHex(), gas, password);
}


Contract ContractFactory::deploy(const std::string &code, const BigInt &gas, const std::string &password)
{
    return deploy(getDefaultAddress(), code, gas, password);
}


Contract ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const std::string &password)
{
    return deploy(getDefaultAddress(), code, args, gas, password);
}


std::string ContractFactory::sendTransaction(const std::string &from, const std::string &code, const std::string &password)
{
    GasEstimator estimator(_provider);
    Json::Value request;
    request["from"] = from;
    request["data"] = code;

    Json::Value estimation = _provider.request("eth_estimateGas", request);
    request["gas"] = estimation;
    Json::Value tx = _provider.request("personal_signAndSendTransaction", Arguments(request, password));

    return tx.asString();
}

std::string ContractFactory::sendTransaction(const std::string &from, const std::string &code, const BigInt &gas, const std::string &password)
{
    GasEstimator estimator(_provider);
    Json::Value request;
    request["from"] = from;
    request["data"] = code;
    request["gas"] = hex(gas);
    Json::Value tx = _provider.request("personal_signAndSendTransaction", Arguments(request, password));

    return tx.asString();
}


std::string ContractFactory::getDefaultAddress()
{
    Wallet wallet(_provider);
    return wallet.getCoinBase();
}

}}
