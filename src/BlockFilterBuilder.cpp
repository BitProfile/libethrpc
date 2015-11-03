#include "BlockFilterBuilder.hpp"

namespace Ethereum{namespace Connector{

BlockFilterBuilder::BlockFilterBuilder(Provider &provider) :
    _provider(provider)
{}

Filter BlockFilterBuilder::build()
{
    Json::Value result;

    if(!_provider.request("eth_newBlockFilter", result))
    {
        throw std::runtime_error("failed to set filter");
    }

     return Filter(_provider, unhex<uint32_t>(result.asCString()));
}

}}
