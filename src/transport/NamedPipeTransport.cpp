
#include "NamedPipeTransport.hpp"

#ifdef BOOST_OS_WINDOWS

namespace Eth{


bool NamedPipeConnector::connect(NamedPipeSocket &socket, const char *path)
{
    HANDLE pipe = CreateFile(path, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    if(!pipe)
    {
        return false;
    }
    socket.assign(pipe);
    return true;
}



}


#endif
