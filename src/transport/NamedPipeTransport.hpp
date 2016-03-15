#pragma once

#include <boost/asio.hpp>
#include <stdexcept>

#include "detail/GenericTransport.hpp"

namespace Ethereum{namespace Connector{


typedef boost::asio::windows::stream_handle NamedPipeSocket;


class NamedPipeConnector
{
    public:
        bool connect(NamedPipeSocket &, const char *);
};

typedef GenericTransport<NamedPipeSocket, NamedPipeConnector> NamedPipeTransport;



}}

