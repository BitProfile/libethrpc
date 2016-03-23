namespace Ethereum{namespace Connector{


template<class CallBack>
void ContractAddressWatcher::watch(const std::string &txid, const CallBack &callback)
{
    boost::thread(boost::bind(&ContractAddressWatcher::watch<CallBack>, _provider, txid));
}



template<class CallBack>
void ContractAddressWatcher::watch(Provider &provider, const std::string &txid, const CallBack &callback)
{
    try
    {
        Contract contract = watch(provider, txid);
        callback(contract);
    }
    catch(const std::exception &e)
    {
        LOG_DEBUG("got exception : "<<e.what());
        callback(boost::system::errc::timed_out);
    }
    catch(...)
    {
        LOG_DEBUG("got unknown exception");
        callback(boost::system::errc::timed_out);
    }
}



}}
