#pragma once

#include "market/types.hpp"

namespace market
{
    class Order final
    {
    public:
        constexpr Order(
            const OrderId id,
            const Side side,
            const Price price,
            const Quantity quantity,
            const SequenceNumber sequence) noexcept
            : m_id(id)
            , m_side(side)
            , m_price(price)
            , m_originalQuantity(quantity)
            , m_remainingQuantity(quantity)
            , m_sequence(sequence)
        {
        }

        [[nodiscard]] constexpr OrderId Id() const noexcept
        {
            return m_id;
        }

        [[nodiscard]] constexpr Side GetSide() const noexcept
        {
            return m_side;
        }

        [[nodiscard]] constexpr Price LimitPrice() const noexcept
        {
            return m_price;
        }

        [[nodiscard]] constexpr Quantity OriginalQuantity() const noexcept
        {
            return m_originalQuantity;
        }

        [[nodiscard]] constexpr Quantity RemainingQuantity() const noexcept
        {
            return m_remainingQuantity;
        }

        [[nodiscard]] constexpr SequenceNumber Sequence() const noexcept
        {
            return m_sequence;
        }

        [[nodiscard]] constexpr bool IsFilled() const noexcept
        {
            return m_remainingQuantity == 0;
        }

        [[nodiscard]] constexpr bool TryFill(const Quantity quantity) noexcept
        {
            if (quantity == 0 || quantity > m_remainingQuantity)
            {
                return false;
            }

            m_remainingQuantity -= quantity;
            return true;
        }

    private:
        OrderId        m_id;
        Side           m_side;
        Price          m_price;
        Quantity       m_originalQuantity;
        Quantity       m_remainingQuantity;
        SequenceNumber m_sequence;
    };
}