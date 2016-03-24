#pragma once

#include <boost/function.hpp>

#include "abi/ContractConstructor.hpp"

#include "Provider.hpp"
#include "Contract.hpp"
#include "Wallet.hpp"

#include "detail/ContractAddressWatcher.hpp"
#include "detail/hex.hpp"


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


        template<class CallBack>
        void deploy(const std::string &from, const std::string &code, const BigInt &gas, const CallBack &);

        template<class CallBack>
        void deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &, const BigInt &gas, const CallBack &);

        Contract deploy(const std::string &from, const std::string &code, const BigInt &gas);
        Contract deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &, const BigInt &gas);

        template<class CallBack>
        void deploy(const std::string &code, const BigInt &gas, const CallBack &);

        template<class CallBack>
        void deploy(const std::string &code, const Ethereum::ABI::Arguments &, const BigInt &gas, const CallBack &);

        Contract deploy(const std::string &code, const BigInt &gas);
        Contract deploy(const std::string &code, const Ethereum::ABI::Arguments &, const BigInt &gas);


    private:
        std::string sendTransaction(const std::string &from, const std::string &code);
        std::string sendTransaction(const std::string &from, const std::string &code, const BigInt &gas);
        std::string getDefaultAddress();

    private:
        Provider &_provider;
        ContractAddressWatcher _watcher;
};


}}

#include "ContractFactory.ipp"
