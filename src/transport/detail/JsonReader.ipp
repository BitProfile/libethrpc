

namespace Ethereum{namespace Connector{




template<class Socket>
bool JsonReader::read(Socket &socket, Json::Value &message)
{
    boost::asio::streambuf buffer;
    boost::system::error_code error;

    size_t size = boost::asio::read_until(socket, buffer, JsonMatcher(), error);

    if(!size)
    {
        buffer.consume(1);
        size = boost::asio::read_until(socket, buffer, JsonMatcher(), error);
    }

    if(!size||error)
    {
        LOG_DEBUG("failed to read response: "<<error.message());
        return false;
    }

    Json::Reader reader;
    const char *data = boost::asio::buffer_cast<const char*>(buffer.data());
    LOG_DEBUG("got ("<<size<<" buf "<<buffer.size()<<") : "<<data);
    if(!reader.parse(data, data+size+1, message, false))
    {
        LOG_DEBUG("failed to parse json");
        return false;
    }

    return true;
}


template<class Socket>
Json::Value JsonReader::read(Socket &socket)
{
    Json::Value message;
    if(!read(socket, message))
    {
        throw std::runtime_error("Failed to read json");
    }
    return message;
}



}}
