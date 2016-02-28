#pragma once

#include <json/value.h>


namespace Ethereum{namespace Connector{


class Arguments
{
    public:
        typedef Json::Value::iterator Iterator;
        typedef Json::Value::const_iterator ConstIterator;

    public:
        Arguments();

        template<class T>
        Arguments(const T &);

        template<class T1, class T2>
        Arguments(const T1&, const T2&);

        template<class T1, class T2, class T3>
        Arguments(const T1&, const T2&, const T3&);

        template<class T1, class T2, class T3, class T4>
        Arguments(const T1&, const T2&, const T3&, const T4&);

        template<class T1, class T2, class T3, class T4, class T5>
        Arguments(const T1&, const T2&, const T3&, const T4&, const T5&);

        void add(const Json::Value &);
        void add(const char *);
        void add(const std::string &);

#if __HAS_INT64__
        void add(int64_t);
#endif

        void add(size_t);
        void add(uint32_t);
        void add(int32_t);

        size_t size() const;
        ConstIterator begin() const;
        ConstIterator end() const;
        Iterator begin();
        Iterator end();
        Json::Value &toJson();
        const Json::Value &toJson() const;


    private:
        Json::Value _value;
};




}}

#include "Arguments.ipp"
