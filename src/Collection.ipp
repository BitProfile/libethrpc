

namespace Eth{

template<class T>
Collection<T>::Collection(const Json::Value &data) :
    _data(data)
{}

template<class T>
typename Collection<T>::Iterator Collection<T>::begin() const
{
    return Iterator(_data.begin());
}

template<class T>
typename Collection<T>::Iterator Collection<T>::end() const
{
    return Iterator(_data.end());
}

template<class T>
size_t Collection<T>::size() const
{
    return _data.size();
}


}
