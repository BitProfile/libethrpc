#pragma once

#ifdef BOOST_WINDOWS_OS
#include "NamedPipeTransport.hpp"
#define IPC_TRANSPORT_CLASS_NAME NamedPipeTransport
#else
#include "UnixSocketTransport.hpp"
#define IPC_TRANSPORT_CLASS_NAME UnixSocketTransport
#endif

namespace Ethereum{namespace Connector{

typedef IPC_TRANSPORT_CLASS_NAME IpcTransport;


}}
