#pragma once

#include <boost/asio.hpp>



#if defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
    #include "UnixSocketTransport.hpp"
#else
    #if defined(__WINDOWS_OS__)
        #include "NamedPipeTransport.hpp"
    #else
        #error Local sockets not available on this platform.
    #endif
#endif

namespace Ethereum{namespace Connector{

#if defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
    typedef UnixSocketTransport IpcTransport;
#else
    typedef NamedPipeTransport IpcTransport;
#endif




}}
