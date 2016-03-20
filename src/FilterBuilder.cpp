
#include "FilterBuilder.hpp"


namespace Ethereum{namespace Connector{

FilterBuilder::FilterBuilder(Provider &provider) : 
    _provider(provider)
{}


void FilterBuilder::setAddress(const char *address)
{
    _request["address"] = Json::Value(address);
}

void FilterBuilder::setAddress(const std::string &address)
{
    _request["address"] = Json::Value(address);
}

void FilterBuilder::setFromBlock(size_t index)
{
    _request["fromBlock"] = (Json::UInt)index;
}

void FilterBuilder::setToBlock(size_t index)
{
    _request["toBlock"] = (Json::UInt)index;
}

void FilterBuilder::setToBlock(const char *name)
{
    _request["toBlock"] = Json::Value(name);
}

void FilterBuilder::setFromBlock(const char *name)
{
    _request["fromBlock"] = Json::Value(name);
}

void FilterBuilder::addTopic(const char *topic)
{
    if(!_request.isMember("topics"))
    {
        _request["topics"] = Json::arrayValue;
    }
    
    _request["topics"].append(topic);
}

void FilterBuilder::reset()
{
    _request = Json::Value();
}


Filter FilterBuilder::build()
{
    Json::Value result = _provider.request("eth_newFilter", _request);
    return Filter(_provider, unhex<uint32_t>(result.asCString()));
}


}}
