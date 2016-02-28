find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system thread REQUIRED)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/CopyHeaders.cmake)

include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${JSONCPP_INCLUDE_DIR})

file(GLOB SOURCES 
    "src/*.cpp"
    "src/transport/*.cpp"
)

include(CheckTypeSize) 

check_type_size("int64_t" SIZEOF_INT64_T)

if(NOT SIZEOF_INT64_T)
    check_type_size("__int64_t" SIZEOF_INT64_T BUILTIN_TYPES_ONLY)
endif()

if(SIZEOF_INT64_T EQUAL 8)
    add_definitions(-D__HAS_INT64__)
endif()

CopyHeaders()


add_library(ethrpc STATIC ${SOURCES})

install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ethrpc DESTINATION include)
install (TARGETS ethrpc ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)


