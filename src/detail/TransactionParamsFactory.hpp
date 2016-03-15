#pragma once 

#include "../BigInt.hpp"


namespace Ethereum{namespace Connector{


class TransactionParamsFactory
{
    public:
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, size_t nonce);
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gas, size_t nonce);
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gasPrice, const BigInt &gas, size_t nonce);
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce);
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, size_t nonce);
        static inline Json::Value makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gasPrice, const BigInt &gas, size_t nonce);
};



}}

#include "TransactionParamsFactory.ipp"
