
#include "Provider.hpp"


namespace Ethereum{namespace Connector{

Provider::Provider(const char *uri): 
    _retryLimit(1),
    _retryInterval(1000)
{
    if(!connect(uri))
    {
        throw std::runtime_error("failed to connect");
    }
}

Provider::Provider(const Path &path): 
    _retryLimit(1),
    _retryInterval(1000)
{
    if(!connect(path.toCString()))
    {
        throw std::runtime_error("failed to connect");
    }
}


Provider::Provider() : 
    _retryLimit(1),
    _retryInterval(1000)
{}

void Provider::setRetryInterval(size_t retryInterval)
{
    _retryInterval = retryInterval;
}

void Provider::setRetryLimit(size_t retryLimit)
{
    _retryLimit = retryLimit;
}

bool Provider::connect()
{
    Path path = Path::GethPath();
    return connect(path.toCString());
}

bool Provider::connect(Network net)
{
    Path path = Path::GethPath(net);
    return connect(path.toCString());
}

bool Provider::connect(const char *uri)
{
    if(!strncmp(uri, "ipc:", 4))
    {
        uri+=4;
        if(uri[0]=='/' && uri[1] =='/')
        {
            uri++;
        }
        _uri = uri;
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
    Json::Value result;
    if(!_connection->request(request, result))
    {
        throw std::runtime_error("request failed");
    }
    return result;
}


bool Provider::request(const char *method, const Arguments &args, Json::Value &result)
{
    Json::Value message;
    RequestEncoder encoder;
    encoder.encode(method, args, message);
    return request(message, result);
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
    if(!_connection->request(request, response))
    {
        size_t errors = 1;

        while(errors <= _retryLimit)
        {

            LOG_DEBUG("request failed, retrying in "<<_retryInterval);

            if(_retryInterval)
            {
                boost::this_thread::sleep(boost::posix_time::milliseconds(_retryInterval));
            }
            
            if(_connection->connect(_uri.c_str()))
            {
                if(_connection->request(request, response))
                {
                    return true;
                }
                else
                {
                    LOG_DEBUG("failed to send request");
                }
            }
            else
            {
                LOG_DEBUG("failed to re-establish connection to : "<<_uri.c_str());
            }
            
            errors++;
        }

        LOG_DEBUG("request failed, too many errors : "<<errors);

        return false;
    }

    return true;
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


}}
