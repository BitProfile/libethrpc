#pragma once

#include <boost/asio.hpp>

#if defined(BOOST_ASIO_HAS_LOCAL_SOCKETS)
    #include "UnixSocketTransport.hpp"
    #define IPC_TRANSPORT_CLASS_NAME UnixSocketTransport
#else
    #if defined(__WINDOWS_OS__)
        #include "NamedPipeTransport.hpp"
        #define IPC_TRANSPORT_CLASS_NAME NamedPipeTransport
    #else
        #error Local sockets not available on this platform.
    #endif
#endif

namespace Ethereum{namespace Connector{

typedef IPC_TRANSPORT_CLASS_NAME IpcTransport;


}}
