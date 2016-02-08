#pragma once

#include <json/value.h>
#include <string>
#include <stdint.h>

#include "BigInt.hpp"
#include "Provider.hpp"
#include "Collection.hpp"
#include "hex.hpp"

namespace Ethereum{namespace Connector{

class Wallet
{
    public:
        Wallet(Provider &);

        Collection<std::string> getAccounts();
        std::string getCoinBase();

        BigInt getBalance(const char *account);
        BigInt getBalance(const std::string &);

        size_t getGasPrice();

        bool unlockAccount(const char *address, const char *password, time_t time=1);
        bool unlockAccount(const std::string &, const std::string &, time_t time=1);

        std::string sendTransaction(const char *from, const char *to, BigInt amount, size_t nonce=0);
        std::string sendTransaction(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string sendTransaction(const char *from, const char *to, BigInt amount, const char *data, size_t nonce=0);
        std::string sendTransaction(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string sendTransaction(const std::string &from, const std::string &to, BigInt amount, size_t nonce=0);
        std::string sendTransaction(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string sendTransaction(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce=0);
        std::string sendTransaction(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string sendRawTransaction(const char *);
        std::string sendRawTransaction(const std::string &);

        std::string call(const char *from, const char *to, BigInt amount, size_t nonce=0);
        std::string call(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string call(const char *from, const char *to, BigInt amount, const char *data, size_t nonce=0);
        std::string call(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string call(const std::string &from, const std::string &to, BigInt amount, size_t nonce=0);
        std::string call(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string call(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce=0);
        std::string call(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string estimateGas(const char *from, const char *to, BigInt amount, size_t nonce=0);
        std::string estimateGas(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string estimateGas(const char *from, const char *to, BigInt amount, const char *data, size_t nonce=0);
        std::string estimateGas(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string estimateGas(const std::string &from, const std::string &to, BigInt amount, size_t nonce=0);
        std::string estimateGas(const std::string &from, const std::string &to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce=0);
        std::string estimateGas(const std::string &from, const std::string &to, BigInt amount, const std::string &data, size_t nonce=0);
        std::string estimateGas(const std::string &from, const std::string &to, BigInt amount, const std::string &data, BigInt gasPrice, BigInt gas, size_t nonce=0);

        std::string sign(const char *account, const char *data);
        std::string sign(const std::string &account, const std::string &data);

    private:
        std::string sendTransactionRequest(const char *type, const Json::Value &);
        Json::Value buildTransactionRequest(const char *from, const char *to, BigInt amount, size_t nonce);
        Json::Value buildTransactionRequest(const char *from, const char *to, BigInt amount, BigInt gasPrice, BigInt gas, size_t nonce);
        Json::Value buildTransactionRequest(const char *from, const char *to, BigInt amount, const char *data, size_t nonce);
        Json::Value buildTransactionRequest(const char *from, const char *to, BigInt amount, const char *data, BigInt gasPrice, BigInt gas, size_t nonce);

    private:
        Provider &_provider;

};

}}
