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
        Provider(const char *uri, size_t retryLimit=0, size_t retryInterval=1000);
        Provider(const Path &, size_t retryLimit=0, size_t retryInterval=1000);
        Provider(size_t retryLimit=0, size_t retryInterval=1000);

        bool connect();
        bool connect(Network);
        bool connect(const char *uri);
        bool connectIPC(const char *path);
        bool connectIPC(const Path &);

        void close();

        void setRetryLimit(size_t );
        void setRetryInterval(size_t);

        bool isEmpty() const;
        bool isConnected() const;

        Json::Value request(const char *, const Arguments &);
        Json::Value request(const char *);

    private:
        Json::Value request(Json::Value &);
        bool retryRequest(Json::Value &request, Json::Value &response, std::string &errMsg);

    private:
        class Connection
        {
            public:
            
              virtual bool request(Json::Value &, Json::Value &, std::string &) = 0;
              virtual bool isConnected() const = 0;
              virtual bool connect(const char *) = 0;
        };

        template<class Transport>
        class ConnectionAdapter : public Connection
        {
            public:
                ConnectionAdapter();
                ConnectionAdapter(const char *uri);
                bool request(Json::Value &, Json::Value &, std::string &);
                bool isConnected() const;
                bool connect(const char *);

            private:
                Transport _transport;
        };


    private:
        boost::shared_ptr<Connection> _connection;
        size_t _retryLimit;
        size_t _retryInterval;
        std::string _uri;
        bool _hasError;
};




}}
