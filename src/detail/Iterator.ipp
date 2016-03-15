

namespace Ethereum{namespace Connector{

template<class Data, class Decoder>
Iterator<Data, Decoder>::Iterator(const Json::Value::const_iterator &it) : 
    _it(it)
{}

template<class Data, class Decoder>
bool Iterator<Data, Decoder>::equal(Iterator const &it) const
{
    return _it == it._it;
}

template<class Data, class Decoder>
Data Iterator<Data, Decoder>::dereference() const
{
    Decoder decoder;
    return decoder.decode(*_it);
}

template<class Data, class Decoder>
void Iterator<Data, Decoder>::increment()
{
    ++_it;
}

template<class Data, class Decoder>
void Iterator<Data, Decoder>::decrement()
{
    return --_it;
}


}}
