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


bool Contract::hasGasLimit() const
{
    return getInvoker().hasGasLimit();
}

bool Contract::hasGasPrice() const
{
    return getInvoker().hasGasPrice();
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
    _provider(provider),
    _hasGas(false),
    _hasGasPrice(false)
{}


void ContractInvoker::setGasLimit(const BigInt &gas)
{
    _hasGas = true;
    _gas = gas;
}


void ContractInvoker::setGasPrice(const BigInt &price)
{
    _hasGasPrice = true;
    _price = price;
}

bool ContractInvoker::hasGasLimit() const
{
    return _hasGas;
}


bool ContractInvoker::hasGasPrice() const
{
    return _hasGasPrice;
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
    Json::Value result = _provider.request("eth_sendTransaction", Arguments(makeParams(from, to, code), "latest"));
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
    Json::Value result = _provider.request("eth_call", Arguments(makeParams(from, to, code), "latest"));
    return result.asString();
}


std::string ContractInvoker::getDefaultAddress() const
{
    Json::Value result = _provider.request("eth_coinbase");
    return result.asString();
}


Json::Value ContractInvoker::makeParams(const std::string &from, const std::string &to, const std::string &code) const
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["code"] = code;
    if(_hasGas)
    {
        request["gas"] = hex(_gas);
    }
    else
    {
        GasEstimator estimator(_provider);
        request["gas"] = hex(estimator.estimate(from, to, BigInt(0), code));
    }

    if(_hasGasPrice)
    {
        request["gasPrice"] = hex(_price);
    }

    return request;
}



}}

#endif
