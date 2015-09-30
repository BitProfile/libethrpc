#pragma once

#include <boost/asio.hpp>
#include <json/value.h>

#include "RequestEncoder.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"

#include "Arguments.hpp"

namespace Eth{


template<class Socket>
class GenericTransport
{
    public:
        GenericTransport();
        
        bool read(Json::Value &);
        Json::Value read();
        
        bool write(const Json::Value &);

        Json::Value request(Json::Value &);
        bool request(Json::Value &, Json::Value &);

        bool request(const char *, const Arguments &, Json::Value &);

        Json::Value request(const char *, const Arguments &);

        bool request(const char *, Json::Value &);
        Json::Value request(const char *);

        Json::Value request(const char *, const Json::Value &);


        bool isConnected() const;

    protected:
        boost::asio::io_service _service;
        Socket _socket;
        JsonReader _reader;
        JsonWriter _writer;
};




}

#include "GenericTransport.ipp"

