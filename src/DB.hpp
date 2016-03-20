#pragma once

#include <string>
#include <boost/assign/list_of.hpp>

#include "Provider.hpp"


namespace Ethereum{namespace Connector{

class DB 
{
    public:
        DB(Provider &);

        bool putString(const char *dbName, const char *key, const char *value);
        bool putString(const std::string &dbName, const std::string &key, const std::string &value);

        std::string getString(const char *dbName, const char *key);

    private:
        Provider &_provider;

};



}}

