#include "Contract.hpp"

#ifdef __ABI_ENABLED__

namespace Ethereum{namespace Connector{


Contract::Contract(Provider &provider, const std::string &address) : 
    Base(address, ContractInvoker(provider))
{}


void Contract::setSenderAddress(const std::string &sender)
{
    getInvoker().setSenderAddress(sender);
}

std::string Contract::getSenderAddress() const
{
    return getInvoker().getSenderAddress();
}

void Contract::setGasLimit(const BigInt &gas)
{
    getInvoker().setGasLimit(gas);
}

const BigInt & Contract::getGasLimit() const
{
    return getInvoker().getGasLimit();
}

void Contract::setGasPrice(const BigInt &gas)
{
    getInvoker().setGasPrice(gas);
}

const BigInt & Contract::getGasPrice() const
{
    return getInvoker().getGasPrice();
}


ContractInvoker::ContractInvoker(Provider &provider) : 
    _provider(provider)
{}


void ContractInvoker::setGasLimit(const BigInt &gas)
{
    _gas = gas;
}


void ContractInvoker::setGasPrice(const BigInt &price)
{
    _price = price;
}


const BigInt & ContractInvoker::getGasLimit() const
{
    return _gas;
}

const BigInt & ContractInvoker::getGasPrice() const
{
    return _price;
}

void ContractInvoker::setSenderAddress(const std::string &sender)
{
    _sender = sender;
}


std::string ContractInvoker::getSenderAddress() const
{
    return _sender.size()? _sender:getDefaultAddress();
}



std::string ContractInvoker::execute(const std::string &from, const std::string &to, const std::string &code)
{
    GasEstimator estimator(_provider);
    BigInt gas = (_gas>0) ? _gas : estimator.estimate(from, to, BigInt(0), code);
    Json::Value request = (_price>0) ? TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), gas, _price, 0) : TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), gas, 0);
    Json::Value result = _provider.request("eth_sendTransaction", request);
    return result.asString();
}

std::string ContractInvoker::execute(const std::string &to, const std::string &code)
{
    return execute(_sender.size()?_sender:getDefaultAddress(), to, code);
}



std::string ContractInvoker::call(const std::string &to, const std::string &code) const
{
    return call(_sender.size()?_sender:getDefaultAddress(), to, code);
}


std::string ContractInvoker::call(const std::string &from, const std::string &to, const std::string &code) const
{
    Json::Value result = _provider.request("eth_call", TransactionParamsFactory::makeParams(from.c_str(), to.c_str(), BigInt(0), code.c_str(), 0));
    return result.asString();
}


std::string ContractInvoker::getDefaultAddress() const
{
    Json::Value result = _provider.request("eth_coinbase");
    return result.asString();
}



}}

#endif
