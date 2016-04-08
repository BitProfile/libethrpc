#ifdef __WINDOWS_OS__

#include "NamedPipeTransport.hpp"

namespace Ethereum{namespace Connector{


bool NamedPipeConnector::connect(NamedPipeSocket &socket, const char *path)
{
    HANDLE pipe = CreateFile(path, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    if(pipe==INVALID_HANDLE_VALUE)
    {
        return false;
    }
    socket.assign(pipe);
    return true;
}



}}


#endif
