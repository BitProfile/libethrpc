namespace Ethereum{namespace Connector{


template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const CallBack &callback)
{
    _watcher.watch(sendTransaction(from, code), callback);
}

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const CallBack &callback)
{
    return deploy(from, code+args.toHex(), callback);
}



template<class CallBack>
void ContractFactory::deploy(const std::string &code, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, callback);
}


template<class CallBack>
void ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, args, callback);
}


//

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const BigInt &gas, const CallBack &callback)
{
    _watcher.watch(sendTransaction(from, code, gas), callback);
}

template<class CallBack>
void ContractFactory::deploy(const std::string &from, const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const CallBack &callback)
{
    return deploy(from, code+args.toHex(), gas, callback);
}



template<class CallBack>
void ContractFactory::deploy(const std::string &code, const BigInt &gas, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, gas, callback);
}


template<class CallBack>
void ContractFactory::deploy(const std::string &code, const Ethereum::ABI::Arguments &args, const BigInt &gas, const CallBack &callback)
{
    deploy(getDefaultAddress(), code, args, gas, callback);
}

}}
