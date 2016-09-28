namespace Ethereum{namespace Connector{


inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gas, const BigInt &gasPrice, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const BigInt &gas, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    request["data"] = normalizeHex(data);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, const BigInt &gasPrice, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    request["data"] = normalizeHex(data);
    request["gasPrice"] = hex(gasPrice);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}

inline Json::Value TransactionParamsFactory::makeParams(const char *from, const char *to, const BigInt &amount, const char *data, const BigInt &gas, size_t nonce)
{
    Json::Value request;
    request["from"] = normalizeHex(from);
    request["to"] = normalizeHex(to);
    request["value"] = hex(amount);
    request["data"] = normalizeHex(data);
    request["gas"] = hex(gas);
    if(nonce)
    {
        request["nonce"] = hex(nonce);
    }
    return request;
}



}}
