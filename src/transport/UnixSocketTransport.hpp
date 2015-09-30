#pragma once

#include <boost/asio.hpp>
#include <stdexcept>

#include "GenericTransport.hpp"

namespace Eth{


typedef boost::asio::local::stream_protocol::socket UnixSocket;
typedef boost::asio::local::stream_protocol::endpoint UnixEndpoint;


class UnixSocketTransport : public GenericTransport<UnixSocket>
{
    public:

        UnixSocketTransport(const char *path);
        UnixSocketTransport();

        bool connect(const char *path);

    private:
        UnixEndpoint _endpoint;
};



}


