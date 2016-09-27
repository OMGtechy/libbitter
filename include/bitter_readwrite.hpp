#pragma once

namespace bitter {
    enum class Bit {
        Zero = 0,
        One = 1
    };

    class BitReader {
    public:
        BitReader(const char* const source, const size_t sourceBytes)
        : m_source(source),
          m_sourceBytes(sourceBytes) {

        }


        Bit getBitNumber(const size_t bitNumber) const {
            return (*m_source & (1 << bitNumber)) ? Bit::One : Bit::Zero;
        }

    private:
        const char* const m_source;
        const size_t m_sourceBytes;
    };
}

