
#include "NamedPipeTransport.hpp"

#ifdef BOOST_OS_WINDOWS

namespace Eth{

NamedPipeTransport::NamedPipeTransport(const char *path)
{
    _pipe = CreateFile(path, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    this->_socket.assign(_pipe);
}


NamedPipeTransport::NamedPipeTransport()
{}


bool NamedPipeTransport::connect(const char *path)
{
    _pipe = CreateFile(path, GENERIC_READ|GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
    if(!_pipe)
    {
        return false;
    }
    this->_socket.assign(_pipe);
    return true;
}



}


#endif
