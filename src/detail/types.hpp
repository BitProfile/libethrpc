#ifdef _MSC_VER

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;

#if __HAS_INT64__
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif


#else
#include <stdint.h>
#endif


#ifdef __APPLE_OS__
  #define SIZE_T(x) uint64_t(x)
#else
  #define SIZE_T(x) size_t(x)
#endif
