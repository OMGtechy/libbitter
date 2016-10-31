#pragma once

#include <bitter_bit.hpp>

namespace bitter {
    template <typename T>
    constexpr Bit getBit(const T* const uncastSource, size_t bitNumber) {
        const char* const source = reinterpret_cast<const char* const>(uncastSource);
        
        const size_t byteNumber = bitNumber / 8;
        bitNumber %= 8;

        return (*(source + byteNumber) & (1 << bitNumber)) ? Bit::One : Bit::Zero;
    }
}

