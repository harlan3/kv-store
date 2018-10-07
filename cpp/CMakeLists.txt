cmake_minimum_required(VERSION 2.8.9)
project(kvstore)

IF(WIN32)
include_directories("C:\\local\\boost_1_65_1" "C:\\local\\protobuf-3.4.1\\src")
ENDIF(WIN32)

include_directories("src/" "proto/cpp/" "src/util/")

file(GLOB SOURCES "src/*.cpp" "src/unittest/*.cpp" "src/util/*.cpp" "proto/cpp/KVStore.pb.cc")

IF(WIN32)
link_directories("C:\\local\\boost_1_65_1\\lib64-msvc-14.1" "C:\\local\\protobuf-3.4.1\\cmake\\build\\solution\\Debug")
ENDIF(WIN32)

add_executable(kvstore ${SOURCES})

IF(WIN32)
target_link_libraries(kvstore "libprotobufd.lib")
ENDIF(WIN32)

IF(UNIX)
target_link_libraries(kvstore "libprotobuf.so" "boost_system.so" "boost_thread.so")
ENDIF(UNIX)