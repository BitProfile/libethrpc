#pragma once

#include <iostream>
#include <ctime>

#ifdef __DEBUG__

#define LOG_DEBUG(x) std::cout<<clock()<<" -> "<<x<<std::endl

#else

//do nothing
#define LOG_DEBUG(x)

#endif
