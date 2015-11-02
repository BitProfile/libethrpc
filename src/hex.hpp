#pragma once


#include <iostream>
#include <sstream>

#include <stdint.h>
#include <stdlib.h>

#include "BigInt.hpp"

namespace Eth{


template<typename T>
std::string hex(const T &);



template<typename T>
T unhex(const char *);

template<>
uint32_t unhex<uint32_t>(const char *);

template<>
uint64_t unhex<uint64_t>(const char *);

template<>
BigInt unhex<BigInt>(const char *);



}

#include "hex.ipp"
