#pragma once

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/system/error_code.hpp>


#include "../Provider.hpp"
#include "../Contract.hpp"
#include "../BlockChain.hpp"


namespace Ethereum{namespace Connector{



class ContractAddressWatcher
{
    public:
        ContractAddressWatcher(Provider &);

        template<class CallBack>
        void watch(const std::string &, const CallBack &);

        Contract watch(const std::string &);
        static Contract watch(Provider &, const std::string &address);

    private:
        template<class CallBack>
        static void watch(Provider &, const std::string &address, const CallBack &);

    private:
        Provider &_provider;
};


}}

#include "ContractAddressWatcher.ipp"
