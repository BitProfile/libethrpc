#pragma once


#include <iostream>
#include <sstream>

#include <stdint.h>
#include <stdlib.h>


namespace Eth{


template<typename T>
std::string hex(const T &);



template<typename T>
T unhex(const char *);

template<>
uint32_t unhex<uint32_t>(const char *);

template<>
uint64_t unhex<uint64_t>(const char *);



}

#include "hex.ipp"
