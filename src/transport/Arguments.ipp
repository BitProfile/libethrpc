namespace Ethereum{namespace Connector{

inline Arguments::Arguments() : _value(Json::arrayValue)
{}

template<class T>
Arguments::Arguments(const T &a)
{
    add(a);
}

template<class T1, class T2>
Arguments::Arguments(const T1 &a, const T2 &b)
{
    add(a);
    add(b);
}


template<class T1, class T2, class T3>
Arguments::Arguments(const T1 &a, const T2 &b, const T3 &c)
{
    add(a);
    add(b);
    add(c);
}


template<class T1, class T2, class T3, class T4>
Arguments::Arguments(const T1 &a, const T2 &b, const T3 &c, const T4 &d)
{
    add(a);
    add(b);
    add(c);
    add(d);
}


template<class T1, class T2, class T3, class T4, class T5>
Arguments::Arguments(const T1 &a, const T2 &b, const T3 &c, const T4 &d, const T5 &e)
{
    add(a);
    add(b);
    add(c);
    add(d);
    add(e);
}


inline void Arguments::add(const Json::Value &a)
{
    _value.append(a);
}

inline void Arguments::add(const char *a)
{
    _value.append(Json::Value(a));
}

inline void Arguments::add(const std::string &a)
{
    _value.append(Json::Value(a));
}


#if __HAS_INT64__
inline void Arguments::add(int64_t a)
{
    _value.append((Json::Int64)a);
}
#endif

inline void Arguments::add(size_t a)
{
#if __HAS_INT64__
    _value.append((Json::UInt64)a);
#else
    _value.append((Json::UInt)a);
#endif
}

inline void Arguments::add(uint32_t a)
{
    _value.append((Json::UInt)a);
}

inline void Arguments::add(int32_t a)
{
    _value.append((Json::Int)a);
}


inline size_t Arguments::size() const
{
    return _value.size();
}

inline Arguments::Iterator Arguments::begin() 
{
    return _value.begin();
}

inline Arguments::Iterator Arguments::end()
{
    return _value.end();
}

inline Arguments::ConstIterator Arguments::begin() const
{   
    return _value.begin();
}

inline Arguments::ConstIterator Arguments::end() const
{
    return _value.end();
}

inline Json::Value & Arguments::toJson()
{
    return _value;
}

inline const Json::Value & Arguments::toJson() const
{
    return _value;
}


}}
