
#include "Provider.hpp"
#include "transport/RequestEncoder.hpp"

namespace Eth{

Provider::Provider(const char *uri)
{
    if(!connect(uri))
    {
        throw std::runtime_error("failed to connect");
    }
}

Provider::Provider()
{}


bool Provider::connect(const char *uri)
{
    if(!strncmp(uri, "ipc:", 4))
    {
        uri+=4;
        if(uri[0]=='/' && uri[1] =='/')
        {
            uri++;
        }
        std::cout<<"uri = "<<uri<<"\n"<<std::flush;
        _connection.reset(new ConnectionAdapter<IpcTransport>);
        return _connection->connect(uri);
    }
    else
    {
        throw std::runtime_error("Protocol not implemented");
    }
}

Json::Value Provider::request(Json::Value &request)
{
    return _connection->request(request);
}


bool Provider::Connection::request(const char *method, const Arguments &args, Json::Value &result)
{
    Json::Value message;
    RequestEncoder encoder;
    encoder.encode(method, args, message);
    return request(message, result);
}


bool Provider::request(const char *method, const Arguments &args, Json::Value &result)
{
    return _connection->request(method, args, result);
}


Json::Value Provider::request(const char *method, const Arguments &args)
{
    Json::Value result;
    if(!request(method, args, result))
    {
        throw std::runtime_error("rpc request failed");
    }
    return result;
}


bool Provider::request(Json::Value &request, Json::Value &response)
{
    return _connection->request(request, response);
}

bool Provider::request(const char *method, Json::Value &response)
{
    RequestEncoder encoder;
    Json::Value request = encoder.encode(method);
    return _connection->request(request, response);
}

bool Provider::request(const char *method, const Json::Value &params, Json::Value &result)
{
    RequestEncoder encoder;
    Json::Value request = encoder.encode(method, params);
    return _connection->request(request, result);
}

Json::Value Provider::request(const char *method)
{
    Json::Value result;
    if(!request(method, result))
    {
        throw std::runtime_error("failed to send request");
    }
    return result;
}

bool Provider::isEmpty() const
{
    return !_connection;
}


bool Provider::isConnected() const
{
    return (bool)_connection && _connection->isConnected();
}

template<class Transport>
Provider::ConnectionAdapter<Transport>::ConnectionAdapter(const char *uri) : _transport(uri)
{}

template<class Transport>
Provider::ConnectionAdapter<Transport>::ConnectionAdapter()
{}

template<class Transport>
Json::Value Provider::ConnectionAdapter<Transport>::request(Json::Value &msg)
{
    return _transport.request(msg);
}

template<class Transport>
bool Provider::ConnectionAdapter<Transport>::request(Json::Value &request, Json::Value &response)
{
    return _transport.request(request, response);
}

template<class Transport>
bool Provider::ConnectionAdapter<Transport>::isConnected() const
{
    return _transport.isConnected();
}

template<class Transport>
bool Provider::ConnectionAdapter<Transport>::connect(const char *uri)
{
    return _transport.connect(uri);
}


}
