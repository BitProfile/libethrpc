#include "Network.hpp"


namespace Ethereum{namespace Connector{


Network::Network(Provider &provider) : 
    _provider(provider)
{}


size_t Network::getPeersCount()
{
    Json::Value result = _provider.request("net_peerCount");
    return unhex<size_t>(result.asCString());
}


size_t Network::getProtocolVersion()
{
    Json::Value result  = _provider.request("eth_protocolVersion");
    return unhex<size_t>(result.asCString());
}



}}
