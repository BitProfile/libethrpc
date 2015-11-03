#include "UnixSocketTransport.hpp"


namespace Ethereum{namespace Connector{


bool UnixSocketConnector::connect(UnixSocket &socket, const char *path)
{
    UnixEndpoint endpoint(path);
    boost::system::error_code ec;

    if(socket.is_open())
    {
        socket.close();
    }

    socket.connect(endpoint, ec);

    if(ec)
    {
        LOG_DEBUG("connection to "<<path<<" failed : "<<ec);

        return false;
    }

    return true;
}






}}

