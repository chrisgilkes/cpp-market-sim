cmake_minimum_required(VERSION 3.24)

project(
    cpp_market_sim
    VERSION 0.1.0
    DESCRIPTION "Modern C++ limit order book and market simulator"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(MARKET_SIM_BUILD_TESTS "Build the test suite" ON)

add_subdirectory(src)

if(MARKET_SIM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()