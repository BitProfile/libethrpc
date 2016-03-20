#include "GasEstimator.hpp"


namespace Ethereum{namespace Connector{


GasEstimator::GasEstimator(Provider &provider) :
    _provider(provider)
{}

BigInt GasEstimator::estimate(const char *from, const char *to, const BigInt &amount, size_t nonce)
{
    return estimate(TransactionParamsFactory::makeParams(from, to, amount, nonce));
}



BigInt GasEstimator::estimate(const char *from, const char *to, const BigInt &amount, const char *data, size_t nonce)
{
    return estimate(TransactionParamsFactory::makeParams(from, to, amount, data, nonce));
}


BigInt GasEstimator::estimate(const std::string &from, const std::string &to, const BigInt &amount, size_t nonce)
{
    return estimate(from.c_str(), to.c_str(), amount, nonce);
}



BigInt GasEstimator::estimate(const std::string &from, const std::string &to, const BigInt &amount, const std::string &data, size_t nonce)
{
    return estimate(from.c_str(), to.c_str(), amount, data.c_str(), nonce);
}



BigInt GasEstimator::getPrice()
{
    Json::Value result = _provider.request("eth_gasPrice");
    return unhex<BigInt>(result.asCString());
}


BigInt GasEstimator::estimate(const Json::Value &params)
{
    Json::Value result = _provider.request("eth_estimateGas", params);
    return unhex<BigInt>(result.asCString());
}


}}
