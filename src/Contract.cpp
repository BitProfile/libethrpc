#include "Contract.hpp"

#ifdef __ABI_ENABLED__

namespace Ethereum{namespace Connector{


Contract::Contract(Provider &provider, const std::string &address) : 
    _provider(provider),
    _address(address),
    _hasGas(false),
    _hasGasPrice(false)
{}


void Contract::setGasLimit(const BigInt &gas)
{
    _hasGas = true;
    _gas = gas;
}


void Contract::setGasPrice(const BigInt &price)
{
    _hasGasPrice = true;
    _price = price;
}

bool Contract::hasGasLimit() const
{
    return _hasGas;
}


bool Contract::hasGasPrice() const
{
    return _hasGasPrice;
}

const BigInt & Contract::getGasLimit() const
{
    return _gas;
}

const BigInt & Contract::getGasPrice() const
{
    return _price;
}

void Contract::setSenderAddress(const std::string &sender)
{
    _sender = sender;
}

void Contract::unsetSenderAddress()
{
    _sender = "";
}


std::string Contract::getSenderAddress() const
{
    return _sender.size()? _sender:getDefaultAddress();
}



std::string Contract::execute(const char *method, const std::string &password)
{
    return signAndExecute(Ethereum::ABI::Method::Encode(method), password);
}


std::string Contract::signAndExecute(const std::string &code, const std::string &password)
{
    Json::Value result = _provider.request("personal_signAndSendTransaction", Arguments(makeParams(getSenderAddress(), code), password));
    return result.asString();
}


std::string Contract::execute(const char *method, const ContractArguments &args, const std::string &password)
{
    return signAndExecute(Ethereum::ABI::Method::Encode(method, args), password);
}


std::string Contract::execute(const char *method)
{
    return executeCode(Ethereum::ABI::Method::Encode(method));
}


std::string Contract::executeCode(const std::string &code)
{
    Json::Value result = _provider.request("eth_sendTransaction", makeParams(getSenderAddress(), code));
    return result.asString();
}


std::string Contract::execute(const char *method, const ContractArguments &args)
{
    return executeCode(Ethereum::ABI::Method::Encode(method, args));
}

ContractResult Contract::call(const char *method) const
{
    return executeCall(Ethereum::ABI::Method::Encode(method));
}


ContractResult Contract::call(const char *method, const ContractArguments &args) const
{
    return executeCall(Ethereum::ABI::Method::Encode(method, args));
}



ContractResult Contract::executeCall(const std::string &code) const
{
    Json::Value result = _provider.request("eth_call", Arguments(_sender.size() ? makeParams(_sender, code) : makeParams(code), "latest"));
    return ContractResult(result.asString());
}


std::string Contract::getDefaultAddress() const
{
    Json::Value result = _provider.request("eth_coinbase");
    return result.asString();
}


Json::Value Contract::makeParams( const std::string &code) const
{
    Json::Value request;
    request["to"] = _address;
    request["data"] = code;
    return request;
}


Json::Value Contract::makeParams(const std::string &from, const std::string &code) const
{
    Json::Value request = makeParams(code);
    request["from"] = from;

    if(_hasGas)
    {
        request["gas"] = hex(_gas);
    }
    else
    {
        GasEstimator estimator(_provider);
        request["gas"] = hex(estimator.estimate(from, _address, BigInt(0), code));
    }

    if(_hasGasPrice)
    {
        request["gasPrice"] = hex(_price);
    }

    return request;
}



}}

#endif
