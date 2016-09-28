namespace Ethereum{namespace Connector{


template<class Callback>
void Provider::onError(const Callback &callback)
{
    _observers.connect(callback);
}


}}
