if(ETHCRYPTO_INCLUDE_DIRS)
    set(ABI_ENALED TRUE)
    add_definitions(-D__ABI_ENABLED__)
    add_definitions(-DBOOST_PP_VARIADICS)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/abi)
endif()


include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/MakeIncludesLink.cmake)

include_directories(${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${JSONCPP_INCLUDE_DIR})

file(GLOB_RECURSE SOURCES "src/*.cpp")



if(APPLE)
    add_definitions(-D__HAS_INT64__)
else()
    include(CheckTypeSize) 
    check_type_size("int64_t" SIZEOF_INT64_T)
    if(NOT SIZEOF_INT64_T)
        check_type_size("__int64_t" SIZEOF_INT64_T BUILTIN_TYPES_ONLY)
    endif()
    if(SIZEOF_INT64_T EQUAL 8)
        add_definitions(-D__HAS_INT64__)
    endif()
endif()


MakeIncludesLink()

if(ABI_ENALED)
    include_directories(${CMAKE_CURRENT_BINARY_DIR}/abi/include)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}")

add_library(ethrpc STATIC ${SOURCES})

if(ABI_ENALED)
    add_dependencies(ethrpc abi)
    include_directories(${CRYPTOPP_INCLUDE_DIR})

    if (WIN32 AND NOT MINGW)
#        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS $<TARGET_OBJECTS:abi>)
        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS "\"${CMAKE_CURRENT_BINARY_DIR}/abi/abi.lib\"")
    elseif (${CMAKE_GENERATOR} STREQUAL "Xcode")
#        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS $<TARGET_OBJECTS:abi>)
        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS "${CMAKE_CURRENT_BINARY_DIR}/abi/libabi.a")
    else()
        set(LIB_OBJ_DIR ${CMAKE_CURRENT_BINARY_DIR}/obj)
#        set(ETHRPC_LIBRARY_PATH $<TARGET_FILE:ethrpc>)
#        set(ABI_LIBRARY_PATH $<TARGET_FILE:abi>)
        set(ETHRPC_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/libethrpc.a)
        set(ABI_LIBRARY_PATH ${CMAKE_CURRENT_BINARY_DIR}/abi/libabi.a)
        make_directory (${LIB_OBJ_DIR})

        ADD_CUSTOM_COMMAND(TARGET ethrpc
              POST_BUILD
              COMMAND echo "packing libethrpc.a"
              COMMAND ${CMAKE_AR} x  ${ABI_LIBRARY_PATH} WORKING_DIRECTORY ${LIB_OBJ_DIR}
              COMMAND ${CMAKE_AR} x  ${ETHRPC_LIBRARY_PATH} WORKING_DIRECTORY ${LIB_OBJ_DIR}
              COMMAND ${CMAKE_AR} rcs  ${ETHRPC_LIBRARY_PATH} ${LIB_OBJ_DIR}/*.o
        )
    endif ()
    file(COPY ${CMAKE_CURRENT_BINARY_DIR}/abi/include/abi DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/ethrpc)
endif()

if(NOT SKIP_LIBRARY_INSTALL)
    install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ethrpc DESTINATION include OPTIONAL)
    install (TARGETS ethrpc ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin OPTIONAL)
endif()


set(ETHRPC_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/include CACHE STRING "" FORCE)
set(ETHRPC_INCLUDE_DIRS ${ETHRPC_INCLUDE_DIR} CACHE STRING "" FORCE)
set(ETHRPC_LIBRARY ethrpc CACHE STRING "" FORCE)
set(ETHRPC_LIBRARIES ${ETHRPC_LIBRARY} CACHE STRING "" FORCE)


