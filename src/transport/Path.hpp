#pragma once

#include <string>
#include <cstdlib>

#include "../Network.hpp"

namespace Ethereum{namespace Connector{


class Path
{
    public:

        Path(const char *);
        Path(const std::string &);

        const std::string &toString() const;
        const char * toCString() const;

        static Path GethRootPath();
        static Path GethRootPath(Network net);
        static Path GethPath();
        static Path GethPath(Network net);

        static Path EthRootPath();
        static Path EthRootPath(Network net);

        static Path EthPath();
        static Path EthPath(Network net);

    protected:
        std::string _path;
};




}}
