#pragma once

#include "Filter.hpp"
#include "Provider.hpp"

namespace Eth{


class BlockFilterBuilder
{

    public:

        BlockFilterBuilder(Provider &);

        Filter build();

    private:
        Provider &_provider;

};


}
