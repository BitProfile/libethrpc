

namespace Eth{




template<class Socket>
bool JsonReader::read(Socket &socket, Json::Value &message)
{

    //ToDo : analyze json delimiters
    boost::asio::streambuf buffer;
    size_t size = boost::asio::read_until(socket, buffer, '}');
    if(!size)
    {
        return false;
    }

    Json::Reader reader;
    const char *data = boost::asio::buffer_cast<const char*>(buffer.data());
    if(!reader.parse(data, data+buffer.size(), message, false))
    {
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



}
