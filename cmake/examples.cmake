find_package(JsonCPP REQUIRED)
find_package(Boost COMPONENTS system thread date_time chrono regex REQUIRED)

set(CMAKE_THREAD_PREFER_PTHREAD ON)
find_package(Threads REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/examples)

file(GLOB EXAMPLES 
    "examples/*.cpp"
)

include_directories(${Boost_INCLUDE_DIRS})

foreach(EXAMPLE ${EXAMPLES})
    get_filename_component(EXAMPLE_NAME ${EXAMPLE} NAME_WE)
    add_executable(${EXAMPLE_NAME} ${EXAMPLE})
    target_link_libraries(${EXAMPLE_NAME} 
        ethrpc
        ${JSONCPP_LIBRARY}
        ${Boost_DATE_TIME_LIBRARY}
        ${Boost_CHRONO_LIBRARY}
        ${Boost_REGEX_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${CMAKE_THREAD_LIBS_INIT}
    )
    if(WIN32)
        target_link_libraries(${EXAMPLE_NAME} ws2_32)
    endif()
    add_dependencies(${EXAMPLE_NAME} ethrpc)
endforeach(EXAMPLE)
