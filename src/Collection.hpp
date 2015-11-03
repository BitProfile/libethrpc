#pragma once 

#include <json/value.h>
#include "Iterator.hpp"

namespace Ethereum{namespace Connector{

template<class T>
class Collection
{

    public:
        typedef Ethereum::Connector::Iterator<T> Iterator;

    public:

        Collection(const Json::Value &);

        size_t size() const;

        Iterator begin() const;
        Iterator end() const;


    private:
        Json::Value _data;
};


}}

#include "Collection.ipp"
