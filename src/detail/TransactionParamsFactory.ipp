namespace Ethereum{namespace Connector{


inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gas, const BigInt &gasPrice, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gas, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["gas"] = hex(gas);
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["data"] = data;
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, const BigInt &gasPrice, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["data"] = data;
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, size_t nonce)
{
    Json::Value request;
    request["from"] = from;
    request["to"] = to;
    request["value"] = hex(amount);
    request["data"] = data;
    request["gas"] = hex(gas);
    request["nonce"] = hex(nonce ? nonce : 1);
    return request;
}



}}
