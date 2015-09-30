#pragma once

#ifdef BOOST_OS_WINDOWS

#include <boost/asio.hpp>
#include <windows.h>
#include <stdexcept>

namespace Eth{

typedef boost::asio::windows::stream_handle NamedPipeSocket;


class NamedPipeTransport : public GenericTransport<NamedPipeSocket>
{
    public:
        NamedPipeTransport(const char *);
        NamedPipeTransport();

        bool connect(const char *);

    private:
        HANDLE _pipe;
};


}

#endif
