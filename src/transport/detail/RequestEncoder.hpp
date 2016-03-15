#pragma once

#include <json/value.h>

#include "../types.hpp"
#include "Arguments.hpp"

namespace Ethereum{namespace Connector{


class RequestEncoder
{
    public:

        Json::Value encode(const char *, const Arguments &);
        void encode(const char*, const Arguments &, Json::Value &result);
        Json::Value encode(const char *);
        Json::Value encode(const char *method, const Json::Value &params);
        void encode(const char *method, const Json::Value &params, Json::Value &);
};



}}

#include "RequestEncoder.ipp"
