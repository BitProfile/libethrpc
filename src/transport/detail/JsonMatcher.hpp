#pragma once

#include <utility>

namespace Ethereum{namespace Connector{


class JsonMatcher
{
    public:
        JsonMatcher();

        template<class Iterator>
        std::pair<Iterator, bool> operator()(Iterator , Iterator ) const;

    private:
        mutable bool   _string;
        mutable bool   _escape;
        mutable size_t  _depth;
};


}}

namespace boost {namespace asio {

    template <> struct is_match_condition<Ethereum::Connector::JsonMatcher> : public boost::true_type {};

}}

#include "JsonMatcher.ipp"
