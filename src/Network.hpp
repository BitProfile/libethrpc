#pragma once 


#include "Provider.hpp"
#include "detail/hex.hpp"


namespace Ethereum{namespace Connector{



class Network
{

    public:
        Network(Provider &);

        size_t getPeersCount();
        size_t getProtocolVersion();

    private:
        Provider &_provider;
};



}}
