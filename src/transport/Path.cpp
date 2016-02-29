
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


std::string DefaultGethPath::RootDirectory()
{
    std::string path;
#if  defined(__APPLE_OS__)
    path += getenv("HOME");
    path += "/Library/Ethereum/";
#elif defined(__LINUX_OS__)
    path += getenv("HOME");
    path += "/.ethereum/";
#elif defined(__WINDOWS_OS__)
    path += getenv("HOMEPATH");
    path += "\\AppData\\Roaming\\Ethereum\\";
#else
    #warning "No OS detected"
#endif
    return path;
}

DefaultGethPath::DefaultGethPath()
{
    _path = "ipc:";
    _path += RootDirectory();
    _path += "geth.ipc";
}

std::string DefaultEthPath::RootDirectory()
{
    std::string path;
#if  defined(__APPLE_OS__)
    path += getenv("HOME");
    path += "/.ethereum/";
#elif defined(__LINUX_OS__)
    path += getenv("HOME");
    path += "/.ethereum/";
#elif defined(__WINDOWS_OS__)
    path += getenv("HOMEPATH");
    path += "\\AppData\\Roaming\\Ethereum\\";
#else
    #warning "No OS detected"
#endif
    return path;
}

DefaultEthPath::DefaultEthPath()
{
    _path = "ipc:";
    _path += RootDirectory();
    _path += "eth.ipc";
}



}}
