#pragma once 

#ifdef __ABI_ENABLED__

#include <string>

#include "Provider.hpp"
#include "GasEstimator.hpp"

#include "detail/TransactionParamsFactory.hpp"


namespace Ethereum{namespace Connector{


typedef Ethereum::ABI::Result ContractResult;
typedef Ethereum::ABI::Arguments ContractArguments;


class Contract
{

    public:
        class Auth;

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

        std::string execute(const char *, const Auth &auth);
        std::string execute(const char *, const ContractArguments &, const Auth &auth);

        std::string execute(const char *);
        std::string execute(const char *, const ContractArguments &);

    private:
        std::string getDefaultAddress() const;
        Json::Value makeParams(const std::string &from, const std::string &code) const;
        Json::Value makeParams(const std::string &code) const;
        std::string executeCode(const std::string &code);
        std::string signAndExecute(const std::string &code, const std::string &address, const std::string &password);
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



class Contract::Auth
{
    public:
        Auth(const std::string &sender, const std::string &password);
        const std::string &getSenderAddress() const;
        const std::string &getPassword() const;

    private:
        std::string _sender;
        std::string _password;
};


}}

#endif
