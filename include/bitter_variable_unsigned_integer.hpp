#pragma once

#include <type_traits>

namespace bitter {
    class VariableUnsignedInteger {
    public:
        VariableUnsignedInteger(const size_t numberOfBytes)
        : m_data(numberOfBytes) {

        }

        //////////////////////////
        // assignment operators //
        //////////////////////////

        VariableUnsignedInteger& operator=(const VariableUnsignedInteger& rhs) {
            return *this;
        }

        VariableUnsignedInteger operator+=(const VariableUnsignedInteger& rhs) const {
            return *this;
        }

        VariableUnsignedInteger operator-=(const VariableUnsignedInteger& rhs) const {
            return *this;
        }

        VariableUnsignedInteger operator*=(const VariableUnsignedInteger& rhs) const {
            return *this;
        }

        VariableUnsignedInteger operator/=(const VariableUnsignedInteger& rhs) const {
            return *this;
        }

        VariableUnsignedInteger operator%=(const VariableUnsignedInteger& rhs) const {
            return *this;
        }

        ///////////////////////
        // boolean operators //
        ///////////////////////

        operator bool() const {
            return false;
        }

        bool operator!() const {
            return false;
        }

    private:
        using byte = uint8_t;
        std::vector<byte> m_data;
    };

    //////////////////////////
    // arithmetic operators //
    //////////////////////////

    VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
    }

    VariableUnsignedInteger& operator++(VariableUnsignedInteger& value) {
        return value;
    }

    VariableUnsignedInteger operator++(VariableUnsignedInteger& value, int) {
        return value;
    }

    VariableUnsignedInteger operator+(const VariableUnsignedInteger& value) {
        return value;
    }

    VariableUnsignedInteger operator-(const VariableUnsignedInteger& value) {
        return value;
    }

    ///////////////////////
    // logical operators //
    ///////////////////////

    bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator==(const VariableUnsignedInteger& lhs, const T& rhs) {
        return false;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator==(const T& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator!=(const VariableUnsignedInteger& lhs, const T& rhs) {
        return false;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    bool operator!=(const T& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    bool operator>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    bool operator<=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    bool operator>=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return false;
    }

    ///////////////////////
    // bitwise operators //
    ///////////////////////

    VariableUnsignedInteger operator<<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return lhs;
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

