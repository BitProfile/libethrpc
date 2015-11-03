

namespace Ethereum{namespace Connector{


inline Json::Value RequestEncoder::encode(const char *method, const Arguments &args)
{
    Json::Value result;
    encode(method, args, result);
    return result;
}


inline void RequestEncoder::encode(const char *method, const Arguments &args, Json::Value &result)
{
    encode(method, args.toJson(), result);
}



inline Json::Value RequestEncoder::encode(const char *method)
{
    return encode(method, Json::Value(Json::arrayValue));
}



inline Json::Value RequestEncoder::encode(const char *method, const Json::Value &params)
{
    Json::Value result;
    encode(method, params, result);
    return result;
}

inline void RequestEncoder::encode(const char *method, const Json::Value &params, Json::Value &result)
{
    result["method"] = method;
    result["params"] = params;
    result["jsonrpc"] = "2";
}


}}
