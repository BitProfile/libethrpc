#include "Filter.hpp"

namespace Eth{

Filter::Filter(Provider &provider, unsigned id) :
    _provider(provider),
    _id(id),
    _active(true)
{}


Collection<FilterLog> Filter::getChanges()
{
    return Collection<FilterLog>(_provider.request("eth_getFilterChanges", Arguments(hex(_id))));
}

Collection<FilterLog> Filter::getLogs()
{
    return Collection<FilterLog>(_provider.request("eth_getFilterLogs", Arguments(hex(_id))));
}


void Filter::destroy()
{
    if(_active)
    {
        _provider.request("eth_uninstallFilter", Arguments(hex(_id)));
        _active = false;
    }
}

Filter::~Filter()
{
    destroy();
}

unsigned Filter::getId()
{
    return _id;
}

}
