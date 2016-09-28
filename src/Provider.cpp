
#include "Provider.hpp"
#include "BlockChain.hpp"

namespace Ethereum{namespace Connector{


Provider::Provider(const char *uri, size_t retryLimit, size_t retryInterval): 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval),
    _hasError(false)
{
    if(!connect(uri))
    {
        throw std::runtime_error("failed to connect");
    }
}


Provider::Provider(const Path &path, size_t retryLimit, size_t retryInterval): 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval),
    _hasError(false)
{
    if(!connect(path.toCString()))
    {
        throw std::runtime_error("failed to connect");
    }
}


Provider::Provider(size_t retryLimit, size_t retryInterval) : 
    _retryLimit(retryLimit),
    _retryInterval(retryInterval),
    _hasError(false)
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


bool Provider::connect(NetworkParams net)
{
    if(net==Test_Net)
    {
        if(!connect(Path::GethPath(Test_Net).toCString()))
        {
            //old geth has same ipc path for mainnet and testnet
            if(!connect(Path::GethPath(Main_Net).toCString()))
            {
                return false;
            }

            //check if it's testnet
            BlockChain chain(*this);
            if(chain.getBlock(0).getHash() == "0xd4e56740f876aef8c010b86a40d5f56745a118d0906a34e69aec8c0db1cb8fa3")
            {
                _connection.reset();
                return false;
            }
        }

        return true;
    }
    else
    {
        return connect(Path::GethPath(Main_Net).toCString());
    }
}


bool Provider::connectIPC(const char *path)
{
    _uri = path;
    _connection.reset(new ConnectionAdapter<IpcTransport>);
    return _connection->connect(path);
}


bool Provider::connectIPC(const Path &path)
{
    return connectIPC(path.toCString());
}


void Provider::close()
{
    if(_connection) _connection.reset();
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
        return connectIPC(uri);
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
    if(_hasError)
    {
        //reset connection
        if(!_connection->connect(_uri.c_str()))
        {
            LOG_DEBUG("failed to re-establish connection to : "<<_uri.c_str());
            throw std::runtime_error("failed to re-establish connection");
        }
        _hasError = false;
    }

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
        _hasError = true;
        if(_observers.empty())
        {
            throw std::runtime_error(errMsg.size()?errMsg:"rpc request failed");
        }
        else
        {
            LOG_DEBUG("rpc error : "<<(errMsg.size()?errMsg:""));
            _observers();
        }
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
