#pragma once


#include "Provider.hpp"
#include "Collection.hpp"
#include "FilterLog.hpp"

#include "detail/hex.hpp"


namespace Ethereum{namespace Connector{

class Filter
{
    public:
        Filter(Provider &, unsigned id);
        ~Filter();

        Collection<FilterLog> getChanges();
        Collection<FilterLog> getLogs();

        void destroy();
        
        unsigned getId();


    private:
        Provider &_provider;
        unsigned _id;
        bool _active;
};


}}
