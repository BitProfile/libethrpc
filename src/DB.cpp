#include "DB.hpp"

namespace Ethereum{namespace Connector{

DB::DB(Provider &provider) :
    _provider(provider)
{}


bool DB::putString(const char *dbName, const char *key, const char *value)
{
    Json::Value result = _provider.request("db_putString", Arguments(dbName,key,value));
    return result.asBool();
}

bool DB::putString(const std::string &dbName, const std::string &key, const std::string &value)
{
    return putString(dbName.c_str(), key.c_str(), value.c_str());
}


std::string DB::getString(const char *dbName, const char *key)
{
    Json::Value result = _provider.request("db_getString", Arguments(dbName, key));
    return result.asString();
}




}}
