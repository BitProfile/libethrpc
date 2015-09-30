

namespace Eth{


template<class Socket>
GenericTransport<Socket>::GenericTransport() : 
    _socket(_service)
{}

template<class Socket>
bool GenericTransport<Socket>::read(Json::Value &message)
{
    return _reader.read(_socket, message);
}

template<class Socket>
Json::Value GenericTransport<Socket>::read()
{
    return _reader.read(_socket);
}

template<class Socket>
bool GenericTransport<Socket>::write(const Json::Value &message)
{
    return _writer.write(_socket, message);
}



template<class Socket>
Json::Value GenericTransport<Socket>::request(Json::Value &msg)
{
    Json::Value response;
    if(!request(msg, response))
    {
        throw std::runtime_error("Failed to send request");
    }
    
    return response;
}

template<class Socket>
bool GenericTransport<Socket>::request(Json::Value &msg, Json::Value &response)
{

    unsigned id = (unsigned)time(NULL);
    msg["id"] = Json::Value(id);
    if(!_writer.write(_socket, msg))
    {
        return false;
    }

    if(!_reader.read(_socket, response))
    {
        return false;
    }

    if(!response["id"]||response["id"].asUInt64()!=id)
    {
        return false;
    }

    if(response.isMember("error"))
    {
        return false;
    }

    response = response["result"];

    return true;
}

template<class Socket>
bool GenericTransport<Socket>::request(const char *method, const Arguments &args, Json::Value &result)
{
   Json::Value message;
   RequestEncoder encoder;
   encoder.encode(method, args,  message);
   return request(message, result);
}

template<class Socket>
Json::Value GenericTransport<Socket>::request(const char *method, const Arguments &args)
{
    Json::Value result;
    if(!request(method, args, result))
    {
        throw std::runtime_error("failed to send request");
    }
    return result;
}

template<class Socket>
bool GenericTransport<Socket>::request(const char *method, Json::Value &result)
{
   Json::Value message;
   RequestEncoder encoder;
   encoder.encode(method,  message);
   return request(message, result);
}

template<class Socket>
Json::Value GenericTransport<Socket>::request(const char *method)
{
    Json::Value result;
    if(!request(method, result))
    {
        throw std::runtime_error("failed to send request");
    }
    return result;
}

template<class Socket>
Json::Value GenericTransport<Socket>::request(const char *method, const Json::Value &params)
{
   RequestEncoder encoder;
   Json::Value message = encoder.encode(method, params);
   return request(message);
}

template<class Socket>
bool GenericTransport<Socket>::isConnected() const
{
    return _socket.is_open();
}


}
