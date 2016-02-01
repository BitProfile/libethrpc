
project(ethrpc)

set(CMAKE_BUILD_TYPE Release)
cmake_minimum_required(VERSION 3.2)

set (Eth_Connector_VERSION_MAJOR 1)
set (Eth_Connector_VERSION_MINOR 0)
set (Eth_Connector_VERSION_PATCH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

find_package(Jsoncpp REQUIRED)
find_package(Boost COMPONENTS system REQUIRED)

#add_definitions(-D__DEBUG__)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${JSONCPP_INCLUDE_DIR})

file(GLOB SOURCES 
    "src/*.cpp"
    "src/transport/*.cpp"
)

file(GLOB_RECURSE HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/src
    "src/*.hpp"
    "src/*.ipp"
)


file(GLOB EXAMPLES 
    "examples/*.cpp"
)



configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Config.hpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/include/ethrpc/Config.hpp"
)


foreach(HEADER ${HEADERS})
    set(HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/${HEADER})
    configure_file(${HEADER_PATH} ${CMAKE_CURRENT_BINARY_DIR}/include/ethrpc/${HEADER} @ONLY)
endforeach(HEADER)

add_library(ethrpc STATIC ${SOURCES})


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/examples)


foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} 
        ethrpc
        ${Boost_SYSTEM_LIBRARY}
        ${JSONCPP_LIBRARY}
    )
endforeach(EXAMPLE)



install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ethrpc DESTINATION include)
install (TARGETS ethrpc ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)


if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  MESSAGE(Status Linux OS detected)
  set(PKGCONFIG_DIR lib/pkgconfig)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
  MESSAGE(Status FreeBSD OS detected)
  set(PKGCONFIG_DIR libdata/pkgconfig)
endif()

if( DEFINED PKGCONFIG_DIR)
  MESSAGE("PKG CONFIG FOUND")
  CONFIGURE_FILE("cmake/pkg-config.cmake" "ethrpc.pc" @ONLY)
  install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ethrpc.pc" DESTINATION "${CMAKE_INSTALL_PREFIX}/${PKGCONFIG_DIR}")
endif()
