find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system thread REQUIRED)
find_package(CryptoPP)


if(CRYPTOPP_INCLUDE_DIR)
    set(ABI_ENALED TRUE)
    add_definitions(-D__ABI_ENABLED__)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/abi)
endif()


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

if(ABI_ENALED)
    include_directories(${CMAKE_CURRENT_BINARY_DIR}/abi/include)
endif()


add_library(ethrpc STATIC ${SOURCES})

if(ABI_ENALED)
    add_dependencies(ethrpc abi)

    if (WIN32 AND NOT MINGW)
        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS $<TARGET_OBJECTS:abi>)
    elseif (${CMAKE_GENERATOR} STREQUAL "Xcode")
        set_property (TARGET ethrpc APPEND PROPERTY STATIC_LIBRARY_FLAGS $<TARGET_OBJECTS:abi>)
    else()
        set(LIB_OBJ_DIR ${CMAKE_CURRENT_BINARY_DIR}/obj)
        set(ETHRPC_LIBRARY_PATH $<TARGET_FILE:ethrpc>)
        set(ABI_LIBRARY_PATH $<TARGET_FILE:abi>)
        make_directory (${LIB_OBJ_DIR})

        ADD_CUSTOM_COMMAND(TARGET ethrpc
              POST_BUILD
              COMMAND echo "packing libethrpc.a"
              COMMAND ${CMAKE_AR} x  ${ABI_LIBRARY_PATH} WORKING_DIRECTORY ${LIB_OBJ_DIR}
              COMMAND ${CMAKE_AR} x  ${ETHRPC_LIBRARY_PATH} WORKING_DIRECTORY ${LIB_OBJ_DIR}
              COMMAND ${CMAKE_AR} rcs  ${ETHRPC_LIBRARY_PATH} ${LIB_OBJ_DIR}/*.o
              COMMAND rm -fr ${LIB_OBJ_DIR}
        )
    endif ()
    file(COPY ${CMAKE_CURRENT_BINARY_DIR}/abi/include/abi DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/include/ethrpc)
endif()

install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ethrpc DESTINATION include)
install (TARGETS ethrpc ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)


