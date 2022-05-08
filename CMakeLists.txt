cmake_minimum_required(VERSION 3.22)
project(test_zmq)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
link_directories(lib)

add_executable(cppzmq_client src/cppzmq_client.cpp)
target_link_libraries(cppzmq_client libzmq-v142-mt-4_3_4.dll)

add_executable(cppzmq_server src/cppzmq_server.cpp)
target_link_libraries(cppzmq_server libzmq-v142-mt-4_3_4.dll)

file(GLOB LIBS_PATH lib/*)
file(COPY ${LIBS_PATH} DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug)