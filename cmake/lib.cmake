find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system thread REQUIRED)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${JSONCPP_INCLUDE_DIR})

file(GLOB SOURCES 
    "src/*.cpp"
    "src/transport/*.cpp"
)

CopyHeaders()

add_library(ethrpc STATIC ${SOURCES})

install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ethrpc DESTINATION include)
install (TARGETS ethrpc ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)


