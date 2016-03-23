#pragma once 

#ifdef __ABI_ENABLED__

#include <string>

#include "abi/Reflection.hpp"
#include "Provider.hpp"
#include "GasEstimator.hpp"

#include "detail/TransactionParamsFactory.hpp"


namespace Ethereum{namespace Connector{


class ContractInvoker
{
    public:
        ContractInvoker(Provider &);
        std::string call(const std::string &, const std::string &);
        std::string call(const std::string &, const std::string &, const std::string &);
        std::string execute(const std::string &, const std::string &);
        std::string execute(const std::string &, const std::string &, const std::string &);

    private:
        std::string getDefaultAddress();

    private:
        Provider &_provider;
};


typedef Ethereum::ABI::Result ContractResult;


class Contract : public Ethereum::ABI::Reflection<ContractInvoker>
{
    public:
        typedef Ethereum::ABI::Reflection<ContractInvoker> Base;

    public:
        Contract(Provider &, const std::string &address);

};


}}

#endif
