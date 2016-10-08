#pragma once

#include <bitter_bit.hpp>

namespace bitter {
    class BitReader {
    public:
        template <typename T>
        constexpr BitReader(const T* const source)
        : m_source(reinterpret_cast<const char* const>(source)) {

        }

        constexpr Bit getBit(size_t bitNumber) const {
            const size_t byteNumber = bitNumber / 8;
            bitNumber %= 8;

            return (*(m_source + byteNumber) & (1 << bitNumber)) ? Bit::One : Bit::Zero;
        }

    private:
        const char* const m_source;
    };

}

