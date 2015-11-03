#pragma once

#ifdef BOOST_OS_WINDOWS

#include <boost/asio.hpp>
#include <windows.h>
#include <stdexcept>

namespace Ethereum{namespace Connector{

typedef boost::asio::windows::stream_handle NamedPipeSocket;

class NamedPipeConnector
{
    public:
        bool connect(NamedPipeSocket &, const char *);
};

typedef GenericTransport<NamedPipeSocket, NamedPipeConnector> NamedPipeTransport;



}}

#endif
