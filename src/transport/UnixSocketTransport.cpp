#include "UnixSocketTransport.hpp"


namespace Eth{


bool UnixSocketConnector::connect(UnixSocket &socket, const char *path)
{
    UnixEndpoint endpoint(path);
    boost::system::error_code ec;
    socket.connect(endpoint, ec);
    return !ec;
}






}

