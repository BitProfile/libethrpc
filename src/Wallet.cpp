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
    Json::Value result = _provider.request("personal_unlockAccount", Arguments(address, password, (size_t)time));
    return result.asBool();
}

bool Wallet::unlockAccount(const std::string &address, const std::string &password, time_t time)
{
    return unlockAccount(address.c_str(), password.c_str(), time);
}


std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, size_t nonce)
{

    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, const BigInt &gasPrice, const BigInt &gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, gasPrice, gas, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, const BigInt &gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, gas, nonce));
}


std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, data, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gasPrice, const BigInt &gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, data, gasPrice, gas, nonce));
}

std::string Wallet::sendTransaction(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, size_t nonce)
{
    return sendTransactionRequest("eth_sendTransaction", TransactionParamsFactory::makeParams(from, to, amount, data, gas, nonce));
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, nonce);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, const BigInt &gasPrice, const BigInt &gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, gasPrice, gas, nonce);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, const BigInt &gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, gas, nonce);
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, data.c_str());
}

std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, const BigInt &gasPrice, const BigInt &gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, data.c_str(), gasPrice, gas, nonce);
}


std::string Wallet::sendTransaction(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, const BigInt &gas, size_t nonce)
{
    return sendTransaction(from.c_str(), to.c_str(), amount, data.c_str(), gas, nonce);
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




}}
