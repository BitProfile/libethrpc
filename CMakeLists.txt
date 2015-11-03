
project(eth-connector)

set(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 3.2)

set (Eth_Connector_VERSION_MAJOR 1)
set (Eth_Connector_VERSION_MINOR 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(Jsoncpp REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${JSONCPP_INCLUDE_DIR}/jsoncpp)

file(GLOB SOURCES 
    "src/*.cpp"
    "src/transport/*.cpp"
)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
)


file(GLOB EXAMPLES 
    "examples/*.cpp"
)



configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.hpp.in"
  "${PROJECT_BINARY_DIR}/include/eth-connector/Config.hpp"
)


foreach(HEADER ${HEADERS})
    set(HEADER_PATH ${CMAKE_SOURCE_DIR}/src/${HEADER})
    configure_file(${HEADER_PATH} ${PROJECT_BINARY_DIR}/include/eth-connector/${HEADER} @ONLY)
endforeach(HEADER)

add_library(eth-connector SHARED ${SOURCES})


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/examples)


foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} 
        eth-connector
        ${Boost_SYSTEM_LIBRARY}
        ${JSONCPP_LIBRARY}
    )
endforeach(EXAMPLE)

install(DIRECTORY ${PROJECT_BINARY_DIR}/include/eth-connector DESTINATION include)
install (TARGETS eth-connector ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
