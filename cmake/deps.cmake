find_package(JsonCPP REQUIRED)
#find_package(Boost COMPONENTS system thread REQUIRED)
find_package(Boost COMPONENTS system thread date_time chrono regex REQUIRED)
find_package(CryptoPP)

set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)
