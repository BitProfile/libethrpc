#include "Wallet.hpp"

namespace Ethereum{namespace Connector{

Wallet::Wallet(Provider &provider) :
    _provider(provider)
{}

Collection<std::string> Wallet::getAccounts()
{
    return Collection<std::string>(_provider.request("eth_accounts"));
}

std::string Wallet::getCoinBase()
{
    Json::Value result = _provider.request("eth_coinbase");
    return result.asString();
}

BigInt Wallet::getBalance(const char *account)
{
    Json::Value result = _provider.request("eth_getBalance", Arguments(account));
    return unhex<BigInt>(result.asCString());
}

BigInt Wallet::getBalance(const std::string &account)
{
    return getBalance(account.c_str());
}

bool Wallet::unlockAccount(const char *address, const char *password, time_t time)
{
    Json::Value result = _provider.request("personal_unlockAccount", Arguments(address, password, time));
    return result.asBool();
}

size_t Wallet::getGasPrice()
{
    Json::Value result = _provider.request("eth_gasPrice");
    return unhex<uint64_t>(result.asCString());
}

std::string Wallet::sendTransaction(const char *from, const char *to, BigInt amount, size_t nonce)
{

    return sendTransactionRequest("eth_SendTransaction", buildTransactionRequest(from, to, amount, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", buildTransactionRequest(from, to, amount, gasPrice, gas, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, BigInt amount, const char *data, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", buildTransactionRequest(from, to, amount, data, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", buildTransactionRequest(from, to, amount, data, gasPrice, gas, nonce));
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, BigInt amount, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, nonce);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, gasPrice, gas, nonce);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, data);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, data, gasPrice, gas, nonce);
}


std::string Wallet::sendRawTransaction(const char *transaction)
{
    Json::Value result = _provider.request("eth_sendRawTransaction", Arguments(transaction));
    return result.asString();
}

std::string Wallet::sendRawTransaction(const std::string &transaction)
{
    return sendRawTransaction(transaction.c_str());
}

std::string Wallet::call(const char *from, const char *to, BigInt amount, size_t nonce)
{
    return sendTransactionRequest("eth_call", buildTransactionRequest(from, to, amount, nonce));
}

std::string Wallet::call(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_call", buildTransactionRequest(from, to, amount, gasPrice, gas, nonce));
}

std::string Wallet::call(const char *from, const char *to, BigInt amount, const char *data, size_t nonce)
{
    return sendTransactionRequest("eth_call", buildTransactionRequest(from, to, amount, data, nonce));
}

std::string Wallet::call(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_call", buildTransactionRequest(from, to, amount, data, gasPrice, gas, nonce));
}

std::string Wallet::call(const std::string &from, const std::string &to, BigInt amount, size_t nonce)
{
    return call(from.c_str(), to.c_str(), amount, nonce);
}

std::string Wallet::call(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return call(from.c_str(), to.c_str(), amount, gasPrice, gas, nonce);
}

std::string Wallet::call(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce)
{
    return call(from.c_str(), to.c_str(), amount, data.c_str(), nonce);
}

std::string Wallet::call(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return call(from.c_str(), to.c_str(), amount, data.c_str(), gasPrice, gas, nonce);
}

std::string Wallet::estimateGas(const char *from, const char *to, BigInt amount, size_t nonce)
{
    return sendTransactionRequest("eth_estimateGas", buildTransactionRequest(from, to, amount, nonce));
}

std::string Wallet::estimateGas(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_estimateGas", buildTransactionRequest(from, to, amount, gasPrice, gas, nonce));
}

std::string Wallet::estimateGas(const char *from, const char *to, BigInt amount, const char *data, size_t nonce)
{
    return sendTransactionRequest("eth_estimateGas", buildTransactionRequest(from, to, amount, data, nonce));
}

std::string Wallet::estimateGas(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return sendTransactionRequest("eth_estimateGas", buildTransactionRequest(from, to, amount, data, gasPrice, gas, nonce));
}

std::string Wallet::estimateGas(const std::string &from, const std::string &to, BigInt amount, size_t nonce)
{
    return estimateGas(from.c_str(), to.c_str(), amount, nonce);
}

std::string Wallet::estimateGas(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return estimateGas(from.c_str(), to.c_str(), amount, gasPrice, gas, nonce);
}

std::string Wallet::estimateGas(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce)
{
    return estimateGas(from.c_str(), to.c_str(), amount, data.c_str(), nonce);
}

std::string Wallet::estimateGas(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    return estimateGas(from.c_str(), to.c_str(), amount, data.c_str(), gasPrice, gas, nonce);
}

std::string Wallet::sign(const char *account, const char *data)
{
    Json::Value result = _provider.request("eth_sign", Arguments(account, data));
    return result.asString();
}

std::string Wallet::sign(const std::string &account, const std::string &data)
{
    return sign(account.c_str(), data.c_str());
}

inline std::string Wallet::sendTransactionRequest(const char *type, const Json::Value &params)
{
    Json::Value result = _provider.request(type, params);
    return result.asString();
}


inline Json::Value Wallet::buildTransactionRequest(const char *from, const char *to, BigInt amount, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value Wallet::buildTransactionRequest(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value Wallet::buildTransactionRequest(const char *from, const char *to, BigInt amount, const char *data, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["data"] = data;
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value Wallet::buildTransactionRequest(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["data"] = data;
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}


}}
