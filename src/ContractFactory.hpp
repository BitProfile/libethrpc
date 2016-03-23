#pragma once

#include <boost/function.hpp>

#include "Provider.hpp"
#include "Contract.hpp"
#include "Wallet.hpp"

#include "detail/ContractAddressWatcher.hpp"


namespace Ethereum{namespace Connector{


class ContractFactory
{
    public:
        ContractFactory(Provider &);

        Contract at(const std::string &);

        template<class CallBack>
        void deploy(const std::string &from, const std::string &code, const CallBack &);

        template<class CallBack>
        void deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &, const CallBack &);

        Contract deploy(const std::string &from, const std::string &code);
        Contract deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &);

        template<class CallBack>
        void deploy(const std::string &code, const CallBack &);

        template<class CallBack>
        void deploy(const std::string &code, const Ethereum::ABI::Arguments &, const CallBack &);

        Contract deploy(const std::string &code);
        Contract deploy(const std::string &code, const Ethereum::ABI::Arguments &);

    private:
        std::string sendTransaction(const std::string &from, const std::string &code);
        std::string getDefaultAddress();

    private:
        Provider &_provider;
        ContractAddressWatcher _watcher;
};


}}

#include "ContractFactory.ipp"
