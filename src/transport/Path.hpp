#pragma once

#include <string>
#include <cstdlib>

namespace Ethereum{namespace Connector{


class Path
{
    public:

        const std::string &toString() const;
        const char * toCString() const;

    protected:
        std::string _path;
};


class DefaultEthPath : public Path
{
    public:

        DefaultEthPath();

        static std::string RootDirectory();
};


class DefaultGethPath : public Path
{
    public:

        DefaultGethPath();

        static std::string RootDirectory();
};


}}
