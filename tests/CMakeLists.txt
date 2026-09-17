include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(market_tests
    types_tests.cpp
    order_tests.cpp
)

target_include_directories(market_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(market_tests
    PRIVATE
        Catch2::Catch2WithMain
)

include(Catch)
catch_discover_tests(market_tests)