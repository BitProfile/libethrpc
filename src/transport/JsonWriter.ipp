

namespace Eth{




template<class Socket>
bool JsonWriter::write(Socket &socket, const Json::Value &json)
{
    Json::FastWriter writer;
    std::string data = writer.write(json);
    size_t size = data.size();

    boost::system::error_code  error;
    size_t sent = boost::asio::write(socket, boost::asio::buffer(data.c_str(), size), error);

    if(error)
    {
        LOG_DEBUG("failed to send message: "<<error.message());
        return false;
    }

    if(sent<size)
    {
        LOG_DEBUG("failed to send full message, sent "<<sent<<" message size "<<size<<" msg: "<<data);
        return false;
    }
    LOG_DEBUG("sent : "<<data);
    return true;
}


}
