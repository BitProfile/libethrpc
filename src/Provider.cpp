
#include "Provider.hpp"


namespace Ethereum{namespace Connector{

Provider::Provider(const char *uri, size_t retryLimit, size_t retryInterval): 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval)
{
    if(!connect(uri))
    {
        throw std::runtime_error("failed to connect");
    }
}

Provider::Provider(const Path &path, size_t retryLimit, size_t retryInterval): 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval)
{
    if(!connect(path.toCString()))
    {
        throw std::runtime_error("failed to connect");
    }
}


Provider::Provider(size_t retryLimit, size_t retryInterval) : 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval)
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



Json::Value Provider::request(const char *method, const Arguments &args)
{
    Json::Value message;
    RequestEncoder encoder;
    encoder.encode(method, args, message);
    return request(message);
}

Json::Value Provider::request(const char *method)
{
    RequestEncoder encoder;
    Json::Value message = encoder.encode(method);
    return request(message);
}

bool Provider::retryRequest(Json::Value &request, Json::Value &response, std::string &errMsg)
{
    LOG_DEBUG("request failed, retrying in "<<_retryInterval);

    if(_retryInterval)
    {
        boost::this_thread::sleep(boost::posix_time::milliseconds(_retryInterval));
    }
    
    if(_connection->connect(_uri.c_str()))
    {
        if(_connection->request(request, response, errMsg))
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
    
    return false;
}

Json::Value Provider::request(Json::Value &request)
{
    Json::Value response;
    std::string errMsg;

    if(!_connection->request(request, response, errMsg))
    {

        if(_retryLimit)
        {
            size_t errors = 1;

            while(errors <= _retryLimit)
            {
                if(retryRequest(request, response, errMsg))
                {
                    return response;
                }
                errors++;
            }

            LOG_DEBUG("request failed, too many errors : "<<errors);
        }
        throw std::runtime_error(errMsg.size()?errMsg:"rpc request failed");
    }

    return response;
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
bool Provider::ConnectionAdapter<Transport>::request(Json::Value &request, Json::Value &response, std::string &errMsg)
{
    return _transport.request(request, response, errMsg);
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
