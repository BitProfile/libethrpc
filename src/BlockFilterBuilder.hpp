#pragma once

#include "Filter.hpp"
#include "Provider.hpp"

namespace Ethereum{namespace Connector{

class BlockFilterBuilder
{

    public:

        BlockFilterBuilder(Provider &);

        Filter build();

    private:
        Provider &_provider;

};


}}
