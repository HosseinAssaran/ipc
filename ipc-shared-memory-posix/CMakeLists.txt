cmake_minimum_required(VERSION 3.10)
project(MultiProcessCounter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(sender sender.cpp)
add_executable(receiver receiver.cpp)

# Link the real-time library (-lrt) for POSIX shared memory functions
target_link_libraries(sender rt)
target_link_libraries(receiver rt)