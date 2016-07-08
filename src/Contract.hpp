#pragma once 

#ifdef __ABI_ENABLED__

#include <string>

#include "abi/Contract.hpp"
#include "Provider.hpp"
#include "GasEstimator.hpp"

#include "detail/TransactionParamsFactory.hpp"


namespace Ethereum{namespace Connector{


typedef Ethereum::ABI::Result ContractResult;
typedef Ethereum::ABI::Arguments ContractArguments;


class Contract
{

    public:
        Contract(Provider &, const std::string &address);

        void setSenderAddress(const std::string &address);
        void unsetSenderAddress();
        void setGasPrice(const BigInt &);
        void setGasLimit(const BigInt &);

        std::string getSenderAddress() const;
        const std::string & getAddress() const;
        const BigInt & getGasLimit() const;
        const BigInt & getGasPrice() const;
        bool hasGasPrice() const;
        bool hasGasLimit() const;

        ContractResult call(const char *) const;
        ContractResult call(const char *, const ContractArguments &) const;

        std::string execute(const char *, const std::string &password);
        std::string execute(const char *, const ContractArguments &, const std::string &password);

    private:
        std::string getDefaultAddress() const;
        Json::Value makeParams(const std::string &from, const std::string &code) const;
        Json::Value makeParams(const std::string &code) const;
        std::string executeCode(const std::string &code, const std::string &password);
        ContractResult executeCall(const std::string &code) const;

    private:
        Provider &_provider;
        std::string _address;
        std::string _sender;
        BigInt _gas;
        BigInt _price;
        bool _hasGas;
        bool _hasGasPrice;
};


}}

#endif
