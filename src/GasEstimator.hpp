#pragma once

#include <string>

#include "Provider.hpp"
#include "BigInt.hpp"

#include "detail/TransactionParamsFactory.hpp"
#include "detail/hex.hpp"


namespace Ethereum{namespace Connector{


class GasEstimator
{
    public:

        GasEstimator(Provider &provider);

        BigInt getPrice();

        BigInt estimate(const char *from, const char *to, const BigInt &amount, size_t nonce=0);
        BigInt estimate(const char *from, const char *to, const BigInt &amount, const BigInt &gasPrice, const BigInt &gas, size_t nonce=0);
        BigInt estimate(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce=0);
        BigInt estimate(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gasPrice, const BigInt &gas, size_t nonce=0);

        BigInt estimate(const std::string &from, const std::string &to, const BigInt &amount, size_t nonce=0);
        BigInt estimate(const std::string &from, const std::string &to, const BigInt &amount, const BigInt &gasPrice, const BigInt &gas, size_t nonce=0);
        BigInt estimate(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, size_t nonce=0);
        BigInt estimate(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, const BigInt &gasPrice, const BigInt &gas, size_t nonce=0);

    private:
        BigInt estimate(const Json::Value &);

    private:
        Provider &_provider;
};


}}
