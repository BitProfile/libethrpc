#pragma once

#include <json/value.h>
#include <string>

#include "Provider.hpp"
#include "Filter.hpp"


namespace Eth{


class FilterBuilder
{
    public:

        FilterBuilder(Provider &);

        void setAddress(const char *address);
        void setAddress(const std::string &);

        void setFromBlock(size_t);
        void setFromBlock(const char *);

        void setToBlock(size_t);
        void setToBlock(const char *);

        void addTopic(const char *);

        void reset();

        Filter build();

    private:
        Json::Value _request;
        Provider _provider;
};


}

