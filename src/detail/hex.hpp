#pragma once


#include <iostream>
#include <sstream>

#include <stdlib.h>

#include "../BigInt.hpp"
#include "types.hpp"

namespace Ethereum{namespace Connector{

template<typename T>
std::string hex(const T &);



template<typename T>
T unhex(const char *);

template<>
uint32_t unhex<uint32_t>(const char *);

#if __HAS_INT64__
template<>
uint64_t unhex<uint64_t>(const char *);
#endif


template<>
BigInt unhex<BigInt>(const char *);

template<class String>
std::string normalizeHex(const String &hex);


}}

#include "hex.ipp"
