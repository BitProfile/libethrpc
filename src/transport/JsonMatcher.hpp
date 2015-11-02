#pragma once

#include <utility>

namespace Eth{


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


}

namespace boost {namespace asio {

    template <> struct is_match_condition<Eth::JsonMatcher> : public boost::true_type {};

}}

#include "JsonMatcher.ipp"
