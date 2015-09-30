#pragma once

#include <boost/asio.hpp>
#include <json/value.h>
#include <json/reader.h>
#include <stdexcept>



namespace Eth{


class JsonReader
{
    public:

        template<class Socket>
        Json::Value read(Socket &);

        template<class Socket>
        bool read(Socket &, Json::Value &);


    private:
        boost::asio::streambuf _buffer;
};



}

#include "JsonReader.ipp"
