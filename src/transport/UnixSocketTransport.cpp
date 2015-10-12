#include "UnixSocketTransport.hpp"


namespace Eth{


bool UnixSocketConnector::connect(UnixSocket &socket, const char *path)
{
    UnixEndpoint endpoint(path);
    boost::system::error_code ec;
    socket.connect(endpoint, ec);

    if(ec)
    {
        LOG_DEBUG("connection to "<<path<<" failed : "<<ec);

        return false;
    }

    return true;
}






}

