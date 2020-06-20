cmake_minimum_required(VERSION 3.0.0)

find_package(GTest MODULE REQUIRED)#查找GTest
find_package(Threads)#查找Threads

#一些调试信息
message(gtest_include_dir=${GTEST_INCLUDE_DIR})
message(gtest_library=${GTEST_LIBRARY})
message(threads=${CMAKE_THREAD_LIBS_INIT})
include_directories(${GTEST_INCLUDE_DIR})

#包含src的项目文件
include_directories(../src)

add_executable(main_test main.cpp 03-test.cpp)


#链接gtest_simple_lib,这个是src项目生成的静态库
#链接${GTEST_LIBRARY},这个是gtest的库文件
#链接${CMAKE_THREAD_LIBS_INIT},即-lpthread
target_link_libraries(main_test PUBLIC src ${GTEST_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME main_test COMMAND gtest_simple_test)