find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system thread REQUIRED)

set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/examples)

file(GLOB EXAMPLES 
    "examples/*.cpp"
)

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} 
        ethrpc
        ${Boost_SYSTEM_LIBRARY}
        ${JSONCPP_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${CMAKE_THREAD_LIBS_INIT}
    )
    if(WIN32)
        target_link_libraries(${EXAMPLE_NAME} ws2_32)
    endif()
endforeach(EXAMPLE)
