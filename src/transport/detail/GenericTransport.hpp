#pragma once

#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>
#include <json/value.h>

#include "RequestEncoder.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"

#include "../Arguments.hpp"

namespace Ethereum{namespace Connector{


template<class Socket, class Connector>
class GenericTransport
{
    public:
        GenericTransport();
        GenericTransport(const char *);

        Json::Value request(Json::Value &);

        bool request(Json::Value &, Json::Value &);
        bool request(const char *, const Arguments &, Json::Value &);
        bool request(const char *, Json::Value &);

        bool request(Json::Value &, Json::Value &, std::string &);
        bool request(const char *, const Arguments &, Json::Value &, std::string &);
        bool request(const char *, Json::Value &, std::string &);

        Json::Value request(const char *);
        Json::Value request(const char *, const Arguments &);
        Json::Value request(const char *, const Json::Value &);


        bool isConnected() const;

        bool connect(const char *);

    private:
        bool read(Json::Value &);
        Json::Value read();
        
        bool write(const Json::Value &);

    protected:
        boost::asio::io_service _service;
        Socket _socket;
        JsonReader _reader;
        JsonWriter _writer;
        Connector _connector;
        boost::mutex _mutex;
};




}}

#include "GenericTransport.ipp"

