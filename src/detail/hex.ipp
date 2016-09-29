
namespace Ethereum{namespace Connector{


template<typename T>
T unhex(const char *value)
{
    return strtoul(value, NULL, 16);
}


template<>
inline uint32_t unhex<uint32_t>(const char *value)
{
    return strtoul(value, NULL, 16);
}


#if __HAS_INT64__
template<>
inline uint64_t unhex<uint64_t>(const char *value)
{
    uint64_t result = strtoull(value, NULL, 16);
    return result;
}
#endif


template<typename T>
std::string hex(const T &value)
{
    std::stringstream stream;
    stream<<"0x"<<std::hex<<value;
    return stream.str();
}

template<>
inline BigInt unhex<BigInt>(const char *value)
{
    return BigInt(value);
}



template<class String>
std::string normalizeHex(const String &hex)
{
    std::string result;
    result = hex;
    if(result[1]!='x' && result[1]!='X')
    {
        result.insert(0, "0x");
    }
    return result;
}


}}
