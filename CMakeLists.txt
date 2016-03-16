
project(ethrpc)

if(DEBUG)
    set(CMAKE_BUILD_TYPE Debug)
    add_definitions(-D__DEBUG__)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

cmake_minimum_required(VERSION 3.2)

set (Eth_Connector_VERSION_MAJOR 1)
set (Eth_Connector_VERSION_MINOR 0)
set (Eth_Connector_VERSION_PATCH 0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/modules")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/OSFlags.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/lib.cmake)

if(ENABLE_EXAMPLES)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/examples.cmake)
endif()

configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/src/Config.hpp.in"
  "${CMAKE_CURRENT_BINARY_DIR}/include/ethrpc/Config.hpp"
)




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
