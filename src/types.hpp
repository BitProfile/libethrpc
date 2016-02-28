#ifdef _MSC_VER

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;

#if __HAS_UINT64__
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#endif


#else
#include <stdint.h>
#endif