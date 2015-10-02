#pragma once

#include <iostream>
#include <ctime>

#ifdef __DEBUG__

#define LOG_DEBUG(x) std::cout<<time(NULL)<<" -> "<<x<<std::endl

#else

//do nothing
#define LOG_DEBUG(x)

#endif
