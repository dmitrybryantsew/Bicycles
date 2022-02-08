cmake_minimum_required(VERSION 3.20)



project(Bicycles_lib)

include_directories(src/SmartPointers
        src/TestData
        src/Allocators
        "src/Data Structures")

set(CMAKE_CXX_STANDARD 17)


#spdy log
hunter_add_package(spdlog)
find_package(spdlog CONFIG REQUIRED)

set(SOURCES  "src/Data Structures/basic_string.c"
             "src/Data Structures/stack.c"
)

set(HEADERS src/Allocators/trackingAllocator.hpp
            "src/Data Structures/basic_string.h"
        "src/Data Structures/simpleVector.hpp"
            "src/Data Structures/stack.h"
            src/SmartPointers/UPointer.hpp
            src/SmartPointers/SPointer.hpp
            src/TestData/testStruct.hpp
)

add_library(Bicycles_lib STATIC ${SOURCES} ${HEADERS})
target_link_libraries(Bicycles_lib spdlog::spdlog)