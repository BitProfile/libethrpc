
#include "Path.hpp"

#include<iostream>
namespace Ethereum{namespace Connector{



const std::string& Path::toString() const
{
    return _path;
}

const char *Path::toCString() const
{
    return _path.c_str();
}


DefaultGethPath::DefaultGethPath()
{
    _path = "ipc:";
#if  defined(__APPLE__)
    _path += getenv("HOME");
    _path += "/Library/Ethereum/";
#elif defined(__linux__)
    _path += getenv("HOME");
    _path += "/.ethereum/";
#elif defined(__MINGW32__)
    _path += getenv("HOMEPATH");
    _path += "\\AppData\\Roaming\\Ethereum\\";
#endif
    _path+="geth.ipc";
}

DefaultEthPath::DefaultEthPath()
{
    _path = "ipc:";
#if  defined(__APPLE__)
    _path += getenv("HOME");
    _path += "/.ethereum/";
#elif defined(__linux__)
    _path += getenv("HOME");
    _path += "/.ethereum/";
#elif defined(__MINGW32__)
    _path += getenv("HOMEPATH");
    _path += "\\AppData\\Roaming\\Ethereum\\";
#endif
    _path += "eth.ipc";
}



}}
