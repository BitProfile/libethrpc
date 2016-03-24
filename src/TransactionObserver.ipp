namespace Ethereum{namespace Connector{


template<class CallBack>
void TransactionObserver::watch(const std::string &txid, const CallBack &callback)
{
    boost::thread(boost::bind(&TransactionObserver::watch<CallBack>, _provider, txid));
}



template<class CallBack>
void TransactionObserver::watch(Provider &provider, const std::string &txid, const CallBack &callback)
{
    callback(watch(provider, txid));
}



}}
