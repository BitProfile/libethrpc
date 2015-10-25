#pragma once


#include "Filter.hpp"
#include "Provider.hpp"


namespace Eth{



class PendingTransactionFilterBuilder
{
    public:
        PendingTransactionFilterBuilder(Provider &);
        Filter build();

    private:
        Provider &_provider;
};


}
