#pragma once

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp> 

#include "transport/IpcTransport.hpp"
#include "transport/Arguments.hpp"
#include "transport/Path.hpp"

#include "transport/detail/RequestEncoder.hpp"

#include "Network.hpp"

namespace Ethereum{namespace Connector{


class Provider
{
    public:
        Provider(const char *uri, size_t retryLimit=1, size_t retryInterval=1000);
        Provider(const Path &, size_t retryLimit=1, size_t retryInterval=1000);
        Provider(size_t retryLimit=1, size_t retryInterval=1000);

        bool connect();
        bool connect(Network);
        bool connect(const char *uri);

        void setRetryLimit(size_t );
        void setRetryInterval(size_t);
        
        Json::Value request(Json::Value &);
        bool request(Json::Value &, Json::Value &);
        bool isEmpty() const;
        bool isConnected() const;
        
       bool request(const char *, const Arguments &, Json::Value &);
       Json::Value request(const char *, const Arguments &);

       bool request(const char *, Json::Value &);
       Json::Value request(const char *);

       bool request(const char *, const Json::Value &, Json::Value &);

    private:
        class Connection
        {
            public:
            
              virtual bool request(Json::Value &, Json::Value &) = 0;
              virtual bool isConnected() const = 0;
              virtual bool connect(const char *) = 0;
        };

        template<class Transport>
        class ConnectionAdapter : public Connection
        {
            public:
                ConnectionAdapter();
                ConnectionAdapter(const char *uri);
                bool request(Json::Value &, Json::Value &);
                bool isConnected() const;
                bool connect(const char *);

            private:
                Transport _transport;
        };

    private:
        bool retryRequest(Json::Value &request, Json::Value &response);

    private:
        boost::shared_ptr<Connection> _connection;
        size_t _retryLimit;
        size_t _retryInterval;
        std::string _uri;
};




}}
