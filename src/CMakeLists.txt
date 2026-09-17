add_executable(market_sim
    main.cpp
)

target_include_directories(market_sim
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(market_sim PRIVATE /W4 /permissive-)
else()
    target_compile_options(market_sim PRIVATE -Wall -Wextra -Wpedantic)
endif()