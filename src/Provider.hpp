#pragma once


#include "transport/IpcTransport.hpp"
#include "transport/Arguments.hpp"

namespace Eth{


class Provider
{
    public:
        Provider(const char *uri);
        Provider();
        bool connect(const char *uri);
        
        Json::Value request(Json::Value &);
        bool request(Json::Value &, Json::Value &);
        bool isEmpty() const;
        bool isConnected() const;
        
       bool request(const char *, const Arguments &, Json::Value &);
       Json::Value request(const char *, const Arguments &);

       bool request(const char *, Json::Value &);
       Json::Value request(const char *);

    private:
        class Connection
        {
            public:
            
              virtual Json::Value request(Json::Value &) = 0;
              virtual bool request(Json::Value &, Json::Value &) = 0;
              virtual bool isConnected() const = 0;
              virtual bool connect(const char *) = 0;

              template<class Arguments>
              bool request(const char *method, const Arguments &, Json::Value &result);
        };

        template<class Transport>
        class ConnectionAdapter : public Connection
        {
            public:
                ConnectionAdapter();
                ConnectionAdapter(const char *uri);
                Json::Value request(Json::Value &);
                bool request(Json::Value &, Json::Value &);
                bool isConnected() const;
                bool connect(const char *);

            private:
                Transport _transport;
        };

    private:
        boost::shared_ptr<Connection> _connection;
};




}
