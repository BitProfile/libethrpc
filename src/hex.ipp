
namespace Eth{

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


template<>
inline uint64_t unhex<uint64_t>(const char *value)
{
    uint64_t result = strtoull(value, NULL, 16);
    return result;
}


template<typename T>
std::string hex(const T &value)
{
    std::stringstream stream;
    stream<<"0x"<<std::hex<<value;
    return stream.str();
}

template<>
inline boost::multiprecision::cpp_int unhex<boost::multiprecision::cpp_int>(const char *value)
{
    return boost::multiprecision::cpp_int(value);
}

}
