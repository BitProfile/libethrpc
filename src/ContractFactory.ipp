namespace Ethereum{namespace Connector{


template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const std::string &password, const CallBack &callback)
{
    _watcher.watch(sendTransaction(from, Ethereum::ABI::ContractConstructor::Encode(code), password), callback);
}

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const std::string &password, const CallBack &callback)
{
    return deploy(from, Ethereum::ABI::ContractConstructor::Encode(code, args), password, callback);
}



template<class CallBack>
void ContractFactory::deploy(const std::string &code, const std::string &password, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, password, callback);
}


template<class CallBack>
void ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const std::string &password, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, args, password, callback);
}


//

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const BigInt &gas, const std::string &password, const CallBack &callback)
{
    _watcher.watch(sendTransaction(from, code, gas, password), callback);
}

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const std::string &password, const CallBack &callback)
{
    return deploy(from, code+args.toHex(), gas, password, callback);
}



template<class CallBack>
void ContractFactory::deploy(const std::string &code, const BigInt &gas, const std::string &password, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, gas, password, callback);
}


template<class CallBack>
void ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const std::string &password, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, args, gas, password, callback);
}

}}
