

namespace Ethereum{namespace Connector{

template<class T>
T Decoder<T>::decode(const Json::Value &data) const
{
    return T(data);
}


inline std::string Decoder<std::string>::decode(const Json::Value &data) const
{
    return data.asString();
}


#if __HAS_INT64__
inline uint64_t Decoder<uint64_t>::decode(const Json::Value &data) const
{
    return data.asUInt64();
}
#endif

inline uint32_t Decoder<uint32_t>::decode(const Json::Value &data) const
{
    return data.asUInt();
}


inline bool Decoder<bool>::decode(const Json::Value &data) const
{
    return data.asBool();
}


}}
