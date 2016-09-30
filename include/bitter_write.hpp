#pragma once

#include <bitter_bit.hpp>

namespace bitter {
    class BitWriter {
    public:
        template <typename T>
        constexpr BitWriter(T * const target)
        : m_target(reinterpret_cast<char* const>(target)) {

        }

        constexpr void setBit(size_t bitNumber, const Bit bitValue) {
            const size_t byteNumber = bitNumber / 8;
            bitNumber %= 8;

            char* const targetByte = (m_target + byteNumber);
            
            // if you want to set bit 3 of byte 00111000 for example:
            // 00111000 = (00111000 & 11111011) | (00000100)
            *targetByte = (*targetByte & ~(1 << bitNumber)) | (static_cast<int>(bitValue) << bitNumber);
        }

    private:
        char* const m_target;
    };
}

