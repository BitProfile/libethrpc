#include "TransactionObserver.hpp"


namespace Ethereum{namespace Connector{


TransactionObserver::TransactionObserver(Provider &provider) :
    _provider(provider)
{}


bool TransactionObserver::watch(const std::string &txid)
{
    return watch(_provider, txid);
}


bool TransactionObserver::watch(Provider &provider, const std::string &txid)
{
    BlockChain chain(provider);
    size_t timeout = chain.getHeight() + 50;
    size_t errors = 0;

    do
    {
        try
        {
            Json::Value result = provider.request("eth_getTransactionByHash", Arguments(txid));
            if(!result.isNull()&&!result["blockNumber"].isNull())
            {
                return true;
            }

            if(chain.getHeight() > timeout)
            {
                return false;
            }

            boost::this_thread::sleep(boost::posix_time::milliseconds(5000));

        }
        catch(...)
        {
            errors++;
        }
    }
    while(errors < 100);

    return false;

}





}}
