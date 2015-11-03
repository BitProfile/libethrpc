#pragma once


#include <json/value.h>
#include <stdint.h>

namespace Ethereum{namespace Connector{

template<class T>
class Decoder
{
    public:
        T decode(const Json::Value &) const;
};



template<>
class Decoder<std::string>
{
    public:
        std::string decode(const Json::Value &) const;
};



template<>
class Decoder<uint64_t>
{
    public:
        uint64_t decode(const Json::Value &) const;
};


template<>
class Decoder<uint32_t>
{
    public:
        uint32_t decode(const Json::Value &) const;
};


template<>
class Decoder<bool>
{
    public:
        bool decode(const Json::Value &) const;
};


}}

#include "Decoder.ipp"
