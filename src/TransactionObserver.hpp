#pragma once 

#include "Provider.hpp"
#include "BlockChain.hpp"

namespace Ethereum{namespace Connector{


class TransactionObserver
{
    public:
        TransactionObserver(Provider &provider);

        template<class CallBack>
        void watch(const std::string &, const CallBack &);

        bool watch(const std::string &);
        static bool watch(Provider &, const std::string &address);

    private:
        template<class CallBack>
        static void watch(Provider &, const std::string &address, const CallBack &);

    private:
        Provider &_provider;
};



}}

#include "TransactionObserver.ipp"
