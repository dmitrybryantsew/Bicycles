cmake_minimum_required(VERSION 3.20)

set(HUNTER_ROOT  "E://.hunter")
set(HUNTER_STATUS_DEBUG ON)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/Hunter/HunterGate.cmake)
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.253.tar.gz"
        SHA1 "88ea6d37c897a81a080eb9ae0f69d7807bbb3c73"
        LOCAL
)

project(Bicycles_run)

include_directories(Bicycles_lib/src/SmartPointers
        Bicycles_lib/src/TestData
        Bicycles_lib/src/Allocators
                    "Bicycles_lib/src/Data Structures")
set(CMAKE_CXX_STANDARD 17)



add_executable(Bicycles_run src/main.cpp)
target_link_libraries(Bicycles_run Bicycles_lib)

add_subdirectory("google tests")
add_subdirectory(Bicycles_lib)