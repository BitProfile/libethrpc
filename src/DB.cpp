#include "DB.hpp"

namespace Eth{

DB::DB(Provider &provider) :
    _provider(provider)
{}


bool DB::putString(const char *dbName, const char *key, const char *value)
{
    Json::Value result;
    if(!_provider.request("db_putString", Arguments(dbName,key,value), result))
    {
        return false;
    }

    return true;
}

bool DB::putString(const std::string &dbName, const std::string &key, const std::string &value)
{
    return putString(dbName.c_str(), key.c_str(), value.c_str());
}


std::string DB::getString(const char *dbName, const char *key)
{

    std::string result;
    if(!getString(dbName, key, result))
    {
        throw std::runtime_error("failed to fetch value");
    }
    return result;

}


bool DB::getString(const char *dbName, const char *key, std::string &value)
{
    Json::Value result;
    if(!_provider.request("db_getString", Arguments(dbName, key), result))
    {
        return false;
    }

    value = result.asString();
    return true;
}


bool DB::getString(const std::string &dbName, const std::string &key, std::string &value)
{
    return getString(dbName.c_str(), key.c_str(), value);
}


}
