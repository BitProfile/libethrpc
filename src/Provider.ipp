
namespace Eth{


template<class Arguments>
bool Provider::Connection::request(const char *method, const Arguments &args, Json::Value &result)
{
    Json::Value message;
    RequestEncoder encoder;
    encoder.encode(method, args, message);
    return request(message, result);
}


template<class Arguments>
bool Provider::request(const char *method, const Arguments &args, Json::Value &result)
{
    return _connection->request(method, args, result);
}

template<class Arguments>
Json::Value Provider::request(const char *method, const Arguments &args)
{
    Json::Value result;
    if(!request(method, args, result))
    {
        throw std::runtime_error("rpc request failed");
    }
    return result;
}




}
