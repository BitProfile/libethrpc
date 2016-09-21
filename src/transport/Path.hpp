#pragma once

#include <string>
#include <cstdlib>

#include "../NetworkParams.hpp"

namespace Ethereum{namespace Connector{


class Path
{
    public:

        Path(const char *);
        Path(const std::string &);

        const std::string &toString() const;
        const char * toCString() const;

        static Path GethPath();
        static Path GethPath(NetworkParams net);

        static Path EthPath();
        static Path EthPath(NetworkParams net);

    private:
        static Path GethRootPath();
        static Path GethRootPath(NetworkParams net);
        static Path EthRootPath();
        static Path EthRootPath(NetworkParams net);

    protected:
        std::string _path;
};




}}
