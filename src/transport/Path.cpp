
#include "Path.hpp"

namespace Ethereum{namespace Connector{


Path::Path(const char *path) :
    _path(path)
{}

Path::Path(const std::string &path) :
    _path(path)
{}

const std::string& Path::toString() const
{
    return _path;
}

const char *Path::toCString() const
{
    return _path.c_str();
}

Path Path::GethRootPath()
{
    return GethRootPath(Main_Net);
}

Path Path::GethPath()
{
    return GethPath(Main_Net);
}

Path Path::EthRootPath()
{
    return EthRootPath(Main_Net);
}

Path Path::EthPath()
{
    return EthPath(Main_Net);
}

Path Path::GethRootPath(NetworkParams net)
{
    std::string path;
#if  defined(__APPLE_OS__)
    path += getenv("HOME");
    path += "/Library/Ethereum";
#elif defined(__LINUX_OS__)
    path += getenv("HOME");
    path += "/.ethereum";
#elif defined(__WINDOWS_OS__)
    path += getenv("HOMEPATH");
    path += "\\AppData\\Roaming\\Ethereum";
#else
    #warning "No OS detected"
    return Path(path);
#endif

    if(net==Test_Net)
    {
#ifdef __WINDOWS_OS__
        path += "\\testnet";
#else
        path += "/testnet";
#endif
    }

    return Path(path);
}


Path Path::GethPath(NetworkParams net)
{
#if defined(__WINDOWS_OS__)
    if(net==Test_Net)
    {
        return Path("ipc:\\\\.\\pipe\\testnet\\geth.ipc");
    }
    return Path("ipc:\\\\.\\pipe\\geth.ipc");
#else
    Path path = Path::GethRootPath(net);
    path._path += "/geth.ipc";
    path._path.insert(0, "ipc:");
    return path;
#endif
}


Path Path::EthRootPath(NetworkParams net)
{
    std::string path;
#if  defined(__APPLE_OS__)
    path += getenv("HOME");
    path += "/.ethereum";
#elif defined(__LINUX_OS__)
    path += getenv("HOME");
    path += "/.ethereum";
#elif defined(__WINDOWS_OS__)
    path += getenv("HOMEPATH");
    path += "\\AppData\\Roaming\\Ethereum";
#else
    #warning "No OS detected"
    return Path(path);
#endif


    if(net==Test_Net)
    {
#ifdef __WINDOWS_OS__
        path += "\\testnet";
#else
        path += "/testnet";
#endif
    }

    return Path(path);
}

Path Path::EthPath(NetworkParams net)
{
#if defined(__WINDOWS_OS__)
    if(net==Test_Net)
    {
        return Path("ipc:\\\\.\\pipe\\testnet\\eth.ipc");
    }
    return Path("ipc:\\\\.\\pipe\\eth.ipc");
#else
    Path path = EthRootPath(net);
    path._path += "/eth.ipc";
    path._path.insert(0, "ipc:");
    return path;
#endif
}



}}
