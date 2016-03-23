#include "ContractAddressWatcher.hpp"


namespace Ethereum{namespace Connector{


ContractAddressWatcher::ContractAddressWatcher(Provider &provider) :
    _provider(provider)
{}


Contract ContractAddressWatcher::watch(const std::string &txid)
{
    return watch(_provider, txid);
}


Contract ContractAddressWatcher::watch(Provider &provider, const std::string &txid)
{
    BlockChain chain(provider);
    size_t timeout = chain.getHeight() + 50;
    size_t errors = 0;

    do
    {
        try
        {
            Json::Value result = provider.request("eth_getTransactionReceipt", Arguments(txid));
            if(!result.isNull())
            {
                return Contract(provider, result["contractAddress"].asString());
            }

            if(chain.getHeight() > timeout)
            {
                throw std::runtime_error("timeout");
            }

            boost::this_thread::sleep(boost::posix_time::milliseconds(5000));

        }
        catch(...)
        {
            errors++;
        }
    }
    while(errors < 100);

    throw std::runtime_error("too many errors");

}





}}
