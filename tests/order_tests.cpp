#include <catch2/catch_test_macros.hpp>

#include "market/order.hpp"

TEST_CASE("A new order retains its submitted values")
{
    const market::Order order{
        1001,
        market::Side::Buy,
        12'500,
        100,
        1
    };

    REQUIRE(order.Id() == 1001);
    REQUIRE(order.GetSide() == market::Side::Buy);
    REQUIRE(order.LimitPrice() == 12'500);
    REQUIRE(order.OriginalQuantity() == 100);
    REQUIRE(order.RemainingQuantity() == 100);
    REQUIRE(order.Sequence() == 1);
    REQUIRE_FALSE(order.IsFilled());
}

TEST_CASE("An order can be partially filled")
{
    market::Order order{
        1001,
        market::Side::Buy,
        12'500,
        100,
        1
    };

    REQUIRE(order.TryFill(40));
    REQUIRE(order.RemainingQuantity() == 60);
    REQUIRE_FALSE(order.IsFilled());
}

TEST_CASE("An order becomes filled when its remaining quantity is consumed")
{
    market::Order order{
        1001,
        market::Side::Buy,
        12'500,
        100,
        1
    };

    REQUIRE(order.TryFill(100));
    REQUIRE(order.RemainingQuantity() == 0);
    REQUIRE(order.IsFilled());
}

TEST_CASE("An order rejects an invalid fill quantity")
{
    market::Order order{
        1001,
        market::Side::Sell,
        12'500,
        100,
        1
    };

    REQUIRE_FALSE(order.TryFill(0));
    REQUIRE_FALSE(order.TryFill(101));
    REQUIRE(order.RemainingQuantity() == 100);
}