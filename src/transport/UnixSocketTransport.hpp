#pragma once

#include <boost/asio.hpp>
#include <stdexcept>

#include "GenericTransport.hpp"

namespace Ethereum{namespace Connector{


typedef boost::asio::local::stream_protocol::socket UnixSocket;
typedef boost::asio::local::stream_protocol::endpoint UnixEndpoint;

class UnixSocketConnector
{
    public:
        bool connect(UnixSocket &, const char *path);
};


typedef GenericTransport<UnixSocket, UnixSocketConnector> UnixSocketTransport;



}}


