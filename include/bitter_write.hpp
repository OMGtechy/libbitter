#pragma once

#include <bitter_bit.hpp>

namespace bitter {
    template <typename T>
    constexpr void setBit(T* const uncastTarget, size_t bitNumber, const Bit bitValue) {
        char* const target = reinterpret_cast<char* const>(uncastTarget);
        
        const size_t byteNumber = bitNumber / 8;
        bitNumber %= 8;

        char* const targetByte = (target + byteNumber);
        
        // if you want to set bit 3 of byte 00111000 for example:
        // 00111000 = (00111000 & 11111011) | (00000100)
        *targetByte = (*targetByte & ~(1 << bitNumber)) | (static_cast<int>(bitValue) << bitNumber);
    }
}

