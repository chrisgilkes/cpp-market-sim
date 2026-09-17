#include <catch2/catch_test_macros.hpp>

#include "market/types.hpp"

TEST_CASE("Order sides are distinct")
{
    REQUIRE(market::Side::Buy != market::Side::Sell);
}