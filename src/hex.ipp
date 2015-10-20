

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
    return strtoull(value, NULL, 16);
}


template<typename T>
std::string hex(const T &value)
{
    std::stringstream stream;
    stream<<std::hex<<value;
    return stream.str();
}


}
