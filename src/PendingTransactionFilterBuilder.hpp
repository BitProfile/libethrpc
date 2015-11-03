#pragma once


#include "Filter.hpp"
#include "Provider.hpp"


namespace Ethereum{namespace Connector{


class PendingTransactionFilterBuilder
{
    public:
        PendingTransactionFilterBuilder(Provider &);
        Filter build();

    private:
        Provider &_provider;
};


}}
