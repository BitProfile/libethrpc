#include "PendingTransactionFilterBuilder.hpp"


namespace Eth{


PendingTransactionFilterBuilder::PendingTransactionFilterBuilder(Provider &provider) :
    _provider(provider)
{}




Filter PendingTransactionFilterBuilder::build()
{
    Json::Value result;

    if(!_provider.request("eth_newPendingTransactionFilter", result))
    {
        throw std::runtime_error("failed to set filter");
    }

     return Filter(_provider, unhex<uint32_t>(result.asCString()));
}

}
