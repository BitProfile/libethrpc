#pragma once


#include <boost/iterator/iterator_facade.hpp>

#include "Decoder.hpp"

namespace Eth{

template<class Data, class Decoder=typename Eth::Decoder<Data> >
class Iterator: 
    public boost::iterator_facade<
        Iterator<Data,Decoder>,
        Data,
        boost::bidirectional_traversal_tag,
        Data
    >
{
    public:
        Iterator(const Json::Value::const_iterator &);

    protected:
        bool equal(Iterator const&) const;
        Data dereference() const;
        void increment();
        void decrement();

    protected:
        Json::Value::const_iterator _it;

    friend class boost::iterator_core_access;
};



}

#include "Iterator.ipp"



