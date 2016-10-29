#pragma once

#include <type_traits>
#include <algorithm>
#include <cstdint>

#include <bitter_read.hpp>
#include <bitter_write.hpp>

namespace bitter {
    //////////////////////////
    // forward declarations //
    //////////////////////////

    class VariableUnsignedInteger;

    ////////////////////////////////////
    // arithmetic operator prototypes //
    ////////////////////////////////////

    VariableUnsignedInteger operator+(const VariableUnsignedInteger&, const VariableUnsignedInteger&);
    VariableUnsignedInteger operator-(VariableUnsignedInteger, const VariableUnsignedInteger&);
    VariableUnsignedInteger& operator++(VariableUnsignedInteger&);
    VariableUnsignedInteger& operator--(VariableUnsignedInteger&);

    /////////////////////////////////
    // logical operator prototypes //
    /////////////////////////////////

    bool operator>(const VariableUnsignedInteger&, const VariableUnsignedInteger&);
    bool operator>=(const VariableUnsignedInteger&, const VariableUnsignedInteger&);

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator==(const VariableUnsignedInteger&, const T&);

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator!=(const VariableUnsignedInteger&, const T&);

    ////////////////////////////////
    // binary operator prototypes //
    ////////////////////////////////

    VariableUnsignedInteger operator<<(VariableUnsignedInteger, VariableUnsignedInteger);

    class VariableUnsignedInteger {
    public:
        //////////////////
        // constructors //
        //////////////////

        explicit VariableUnsignedInteger(const size_t numberOfBytes)
        : m_data(numberOfBytes) {

        }

        //////////////////////////
        // assignment operators //
        //////////////////////////

        VariableUnsignedInteger& operator=(const VariableUnsignedInteger& rhs) {
            // TODO:
            // This potentially changes the size of the integer.
            // What's the desired behaviour given different sizes?
            m_data = rhs.m_data;
            return *this;
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator=(T rhs) {
            const auto maxBytes = std::min(sizeof(rhs), m_data.size());

            for(size_t i = 0; i < maxBytes; ++i) {
                m_data[i] = rhs & static_cast<uint8_t>(0xFF);
                rhs >>= 8;
            }

            return *this;
        }

        VariableUnsignedInteger operator+=(const VariableUnsignedInteger& rhs) {
            // TODO:
            // add test for this
            return (*this = *this + rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger operator+=(const T& rhs) {
            // TODO:
            // add test for this

            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this += variableRhs;
        }

        VariableUnsignedInteger operator-=(const VariableUnsignedInteger& rhs) {
            // TODO:
            // add test for this
            return (*this = *this - rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger operator-=(const T& rhs) {
            // TODO:
            // add test for this

            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this -= variableRhs;
        }

        VariableUnsignedInteger operator*=(const VariableUnsignedInteger& rhs) {
            return *this;
        }

        VariableUnsignedInteger operator/=(const VariableUnsignedInteger& rhs) {
            return *this;
        }

        VariableUnsignedInteger operator%=(const VariableUnsignedInteger& rhs) {
            return *this;
        }

        VariableUnsignedInteger operator<<=(const VariableUnsignedInteger& rhs) {
            return (*this = *this << rhs);
        }
        
        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger operator<<=(const T& rhs) {
            // TODO:
            // add test for this

            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this <<= variableRhs;
        }

        ///////////////////////
        // boolean operators //
        ///////////////////////

        explicit operator bool() const {
            return false;
        }

        bool operator!() const {
            return false;
        }

        //////////////////////////////
        // logical operator friends //
        //////////////////////////////

        friend bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);
        friend bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);
        friend bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

        /////////////////////////////////
        // arithmetic operator friends //
        /////////////////////////////////

        friend VariableUnsignedInteger operator+(const VariableUnsignedInteger&, const VariableUnsignedInteger&);
        friend VariableUnsignedInteger operator*(const VariableUnsignedInteger&, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator-(VariableUnsignedInteger, const VariableUnsignedInteger&);
        friend VariableUnsignedInteger operator/(const VariableUnsignedInteger&, const VariableUnsignedInteger&);

        //////////////////////////////
        // bitwise operator friends //
        //////////////////////////////

        friend VariableUnsignedInteger operator<<(VariableUnsignedInteger, VariableUnsignedInteger);

    private:
        using chunk_t = uint8_t;
        std::vector<chunk_t> m_data;
    };

    //////////////////////////
    // arithmetic operators //
    //////////////////////////

    VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        // TODO:
        // Should the size increase if necessary?
        VariableUnsignedInteger result(std::max(lhs.m_data.size(), rhs.m_data.size()));

        const size_t maxBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        // need to make sure the carry is at least
        // one byte larger than the "chunk" type
        using carry_t = uint16_t;
        static_assert(sizeof(carry_t) > sizeof(VariableUnsignedInteger::chunk_t), "");

        carry_t carry = 0;

        for(size_t i = 0; i < maxBytes; ++i) {
            auto chunkSum = lhs.m_data[i] + rhs.m_data[i] + carry;

            constexpr auto chunkMax = std::numeric_limits<VariableUnsignedInteger::chunk_t>::max();
            carry = chunkSum > chunkMax ? 1 : 0;

            chunkSum &= chunkMax;

            result.m_data[i] = chunkSum;
        }

        // TODO:
        // if(carry != 0) ... overflow!
        // Do we want to report this?

        return result;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs + variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator+(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs + lhs;
    }

    VariableUnsignedInteger operator-(VariableUnsignedInteger lhs, const VariableUnsignedInteger& rhs) {
        const size_t maxBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        // need to make sure the carry is at least
        // two bytes larger than the "chunk" type
        // (one for signedness, one for magnitude)
        using carry_t = int32_t;
        static_assert(sizeof(carry_t) > (sizeof(VariableUnsignedInteger::chunk_t) + 1), "");

        for(size_t i = 0; i < maxBytes; ++i) {
            carry_t chunkSub = static_cast<carry_t>(lhs.m_data[i]) - static_cast<carry_t>(rhs.m_data[i]);

            size_t borrowByteIndex = i;
            while(chunkSub < 0) {
                ++borrowByteIndex;

                if(borrowByteIndex >= maxBytes) {
                    // TODO:
                    // how to handle underflow?
                }

                if(lhs.m_data[borrowByteIndex] > 0) {
                    lhs.m_data[borrowByteIndex] -= 1;

                    for(size_t j = borrowByteIndex - 1; j != i; --j) {
                        lhs.m_data[j] = std::numeric_limits<VariableUnsignedInteger::chunk_t>::max();
                    }

                    chunkSub += std::numeric_limits<VariableUnsignedInteger::chunk_t>::max() + 1;
                }
            }

            lhs.m_data[i] = chunkSub;
        }

        return lhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs - variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator-(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs - rhs;
    }

    VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, VariableUnsignedInteger rhs) {
        VariableUnsignedInteger result(lhs.m_data.size());
        result = 0;
        
        for(; rhs != 0; --rhs) {
            result += lhs;
        }
        
        return result;
    }
   
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs * variableRhs;
    }
    
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator*(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs * lhs;
    }

    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        if(rhs == 1) {
            return lhs;
        }

        // TODO:
        // What do if rhs == 0?

        VariableUnsignedInteger quotient(lhs.m_data.size());
        VariableUnsignedInteger remainder(lhs.m_data.size());

        quotient = 0;
        remainder = 0;

        const auto bitsInRhs = rhs.m_data.size() * (sizeof(decltype(rhs.m_data)::value_type) * 8);

        for(size_t i = bitsInRhs; i > 0; --i) {
            const auto bitIndex = i - 1;
            
            remainder <<= 1;
            
            BitReader bitReader(lhs.m_data.data());
            BitWriter bitWriter(remainder.m_data.data());

            bitWriter.setBit(0, bitReader.getBit(bitIndex));
            
            if(remainder >= rhs) {
                remainder -= rhs;
                
                BitWriter bitWriter(quotient.m_data.data());
                bitWriter.setBit(bitIndex, Bit::One);
            }
        }

        return quotient;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs / variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator/(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs / rhs;
    }

    VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger& operator++(VariableUnsignedInteger& value) {
        // TODO:
        // add test for this
        value += 1;
        return value;
    }

    VariableUnsignedInteger operator++(VariableUnsignedInteger& value, int) {
        return value;
    }

    VariableUnsignedInteger operator+(const VariableUnsignedInteger& value) {
        return value;
    }

    VariableUnsignedInteger& operator--(VariableUnsignedInteger& value) {
        // TODO:
        // add test for this
        value -= 1;
        return value;
    }

    VariableUnsignedInteger operator--(VariableUnsignedInteger& value, int) {
        return value;
    }

    VariableUnsignedInteger operator-(const VariableUnsignedInteger& value) {
        return value;
    }

    ///////////////////////
    // logical operators //
    ///////////////////////

    bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        const size_t lowestNumberOfBytes = std::min(lhs.m_data.size(), rhs.m_data.size());

        for(size_t i = 0; i < lowestNumberOfBytes; ++i) {
            if(lhs.m_data[i] != rhs.m_data[i]) {
                return false;
            }
        }

        // instances can still be considered
        // equal if the extra bytes are all 0

        const size_t highestNumberOfBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        for(size_t i = lowestNumberOfBytes; i < highestNumberOfBytes; ++i) {
            if((lhs.m_data.size() > i && lhs.m_data[i] != 0) || (rhs.m_data.size() > i && rhs.m_data[i] != 0)) {
                return false;
            }
        }

        return true;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator==(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs == variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator==(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs == lhs;
    }

    bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs == rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator!=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs != variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator!=(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs != lhs;
    }

    bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        const size_t lowestNumberOfBytes = std::min(lhs.m_data.size(), rhs.m_data.size());
        const size_t highestNumberOfBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        for(size_t i = highestNumberOfBytes; i > 0; --i) {
            const size_t byteIndex = i - 1;

            const bool lhsNonZero = lhs.m_data.size() > byteIndex && lhs.m_data[byteIndex] != 0;
            const bool rhsNonZero = rhs.m_data.size() > byteIndex && rhs.m_data[byteIndex] != 0;

            if(lhsNonZero && rhsNonZero) {
                const auto lhsByte = lhs.m_data[byteIndex];
                const auto rhsByte = rhs.m_data[byteIndex];

                if(lhsByte != rhsByte) {
                    return lhsByte < rhsByte;
                }
            } else if(lhsNonZero || rhsNonZero) {
                return ! lhsNonZero;
            }
        }

        for(size_t i = lowestNumberOfBytes; i > 0; --i) {
            const auto byteIndex = i - 1;

            const auto lhsByte = lhs.m_data[byteIndex];
            const auto rhsByte = rhs.m_data[byteIndex];

            if(lhsByte != rhsByte) {
                return lhsByte < rhsByte;
            }
        }

        return false;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator<(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs < variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator<(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs < rhs;
    }

    bool operator>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return (lhs != rhs) && (! (lhs < rhs));
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator>(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs > variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator>(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs > rhs;
    }

    bool operator<=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs > rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator<=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs <= variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator<=(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs <= rhs;
    }

    bool operator>=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs < rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator>=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs >= variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator>=(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs >= rhs;
    }

    ///////////////////////
    // bitwise operators //
    ///////////////////////

    VariableUnsignedInteger operator<<(VariableUnsignedInteger lhs, VariableUnsignedInteger rhs) {
        // TODO:
        // if the user was using an uint8_t (for example), and shift by > 7, it's UB
        // it might be nice to have an exception thrown in those circumstances

        for(; rhs > 0; --rhs) {
            for(size_t i = lhs.m_data.size(); i > 0; --i) {
                const auto chunkIndex = i - 1;

                if(i != lhs.m_data.size()) {
                    // TODO:
                    // these should be functions; no object is needed. Refactor BitReader/BitWriter...
                    const BitReader bitReader(&lhs.m_data[chunkIndex]);
                    if(bitReader.getBit((sizeof(decltype(lhs.m_data)::value_type) * 8) - 1) == Bit::One) {
                        BitWriter bitWriter(&lhs.m_data[chunkIndex + 1]);
                        bitWriter.setBit(0, Bit::One);
                    }
                }

                // TODO:
                // I know, I know! Shifting one bit at a time will be slow as hell...
                // the algorithm should be changed and a test should be added for large lhs and rhs values.
                lhs.m_data[chunkIndex] <<= 1;
            }
        }

        return lhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator<<(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs << variableRhs;
    }

    VariableUnsignedInteger operator>>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator&(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator^(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator|(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator~(const VariableUnsignedInteger& value) {
        return value;
    }

    //////////////////////
    // stream operators //
    //////////////////////

    std::ostream& operator<<(std::ostream& stream, const VariableUnsignedInteger& value) {
        return stream;
    }

    std::istream& operator>>(std::istream& stream, VariableUnsignedInteger& value) {
        return stream;
    }
}

