#include "UnixSocketTransport.hpp"


namespace Eth{


UnixSocketTransport::UnixSocketTransport(const char *path)
{
    if(!connect(path))
    {
        throw std::runtime_error("failed to connect");
    }
}


UnixSocketTransport::UnixSocketTransport()
{}


bool UnixSocketTransport::connect(const char *path)
{
    _endpoint.path(path);
    boost::system::error_code ec;
    this->_socket.connect(_endpoint, ec);
    return !ec;
}




}

