#pragma once

#include <type_traits>
#include <algorithm>
#include <cstdint>

#include <bitter_read.hpp>
#include <bitter_write.hpp>

///
/// INTERFACE
///

namespace bitter {
    class VariableUnsignedInteger;

    //!
    //! \brief  Adds two VariableUnsignedIntegers together
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the sum,
    //!           whose maxValue() >= max(lhs.maxValue(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     VariableUnsignedInteger sum = x + y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Adds a VariableUnsignedInteger and unsigned primitive together
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the sum,
    //!           whose maxValue() >= max(lhs.maxValue(), std::numeric_limits<T>::max())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger sum = x + 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Adds an unsigned primitive and VariableUnsignedInteger together
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the sum,
    //!           whose maxValue() >= max(std::numeric_limits<T>::max(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger sum = 42 + x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator+(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Subtracts one VariableUnsignedInteger from another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the difference,
    //!           whose maxValue() >= max(lhs.maxValue(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     VariableUnsignedInteger difference = x - y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator-(VariableUnsignedInteger lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Subtracts an unsigned primitive from a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the difference,
    //!           whose maxValue() >= max(lhs.maxValue(), std::numeric_limits<T>::max())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger difference = x - 1024;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Subtracts a VariableUnsignedInteger from an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the difference,
    //!           whose maxValue() >= max(std::numeric_limits<T>::max(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger difference = 1024 - x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator-(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Multiplies two VariableUnsignedIntegers together
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the product,
    //!           whose maxValue() >= max(lhs.maxValue(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     VariableUnsignedInteger product = x * y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, VariableUnsignedInteger rhs);

    //!
    //! \brief  Multiplies a VariableUnsignedIntegers and unsigned primitive together
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the product,
    //!           whose maxValue() >= max(lhs.maxValue(), std::numeric_limits<T>::max())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger product = x * 2;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Multiplies an unsigned primitive and VariableUnsignedInteger together
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the product,
    //!           whose maxValue() >= max(std::numeric_limits<T>::max(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger product = 2 * x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator*(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Divides one VariableUnsignedInteger by another, returning the quotient
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the quotient,
    //!           whose maxValue() >= max(lhs.maxValue(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     VariableUnsignedInteger quotient = x / y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Divides a VariableUnsignedInteger by an unsigned primitive, returning the quotient
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the quotient,
    //!           whose maxValue() >= max(lhs.maxValue(), std::numeric_limits<T>::max())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger quotient = x / 180;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Divides an unsigned primitive by a VariableUnsignedInteger, returning the quotient
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the quotient,
    //!           whose maxValue() >= max(std::numeric_limits<T>::max(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger quotient = 180 / x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator/(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Divides one VariableUnsignedInteger by another, returning the remainder
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the remainder,
    //!           whose maxValue() >= max(lhs.maxValue(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     VariableUnsignedInteger remainder = x % y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Divides a VariableUnsignedInteger by an unsigned primitive, returning the remainder
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the remainder,
    //!           whose maxValue() >= max(lhs.maxValue(), std::numeric_limits<T>::max())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger remainder = x % 180;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Divides an unsigned primitive by a VariableUnsignedInteger, returning the remainder
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger containing the remainder,
    //!           whose maxValue() >= max(std::numeric_limits<T>::max(), rhs.maxValue())
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     VariableUnsignedInteger remainder = 180 % x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator%(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Preincrements a VariableUnsignedInteger
    //!
    //! \param[in,out]  instance  the instance to preincrement
    //!
    //! \returns  \p instance, incremented
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 0;
    //!     y = ++x;
    //!     // x == 1 && y == 1
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger& operator++(VariableUnsignedInteger& instance);

    //!
    //! \brief  Postincrements a VariableUnsignedInteger
    //!
    //! \param[in,out]  instance  the instance to postincrement
    //!
    //! \returns  \p instance, not incremented
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 0;
    //!     y = x++;
    //!     // x == 1 && y == 0
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator++(VariableUnsignedInteger& instance, int);

    //!
    //! \brief  Predecrements a VariableUnsignedInteger
    //!
    //! \param[in,out]  instance  the instance to predecrement
    //!
    //! \returns  \p instance, decremented
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 2;
    //!     y = --x;
    //!     // x == 1 && y == 1
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger& operator--(VariableUnsignedInteger& instance);

    //!
    //! \brief  Postdecrements a VariableUnsignedInteger
    //!
    //! \param[in,out]  instance  the instance to postdecrement
    //!
    //! \returns  \p instance, not decremented
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 2;
    //!     y = x--;
    //!     // x == 1 && y == 2
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    VariableUnsignedInteger operator--(VariableUnsignedInteger& instance, int);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is less than another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 1;
    //!     y = 2;
    //!     const bool xIsLessThanY = x < y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is less than or equal to another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 2;
    //!     y = 2;
    //!     const bool xIsLessThanOrEqualToY = x <= y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    bool operator<=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is greater than another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 2;
    //!     y = 2;
    //!     const bool xIsGreaterThanY = x > y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    bool operator>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is greater than or equal to another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 2;
    //!     y = 2;
    //!     const bool xIsGreaterThanOrEqualToY = x >= y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    bool operator>=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);
}

///
/// IMPLEMENTATION
///

namespace bitter {
    //////////////////////////
    // forward declarations //
    //////////////////////////

    struct DivisonResult;

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

    /////////////////////////////////
    // bitwise operator prototypes //
    /////////////////////////////////

    VariableUnsignedInteger operator<<(VariableUnsignedInteger, VariableUnsignedInteger);

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator<<(const VariableUnsignedInteger&, const T&);

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator>>(const VariableUnsignedInteger&, const T&);

    class VariableUnsignedInteger {
    public:
        //////////////////
        // constructors //
        //////////////////

        explicit VariableUnsignedInteger(const size_t numberOfBytes)
        : m_data(numberOfBytes, 0) {

        }

        //////////////////////////
        // assignment operators //
        //////////////////////////

        VariableUnsignedInteger& operator=(const VariableUnsignedInteger& rhs) {
            // TODO:
            // This potentially changes the size of the integer.
            // What's the desired behaviour given different sizes?
            const auto targetSize = std::max(rhs.m_data.size(), m_data.size());

            m_data = rhs.m_data;
            m_data.resize(targetSize, 0);

            return *this;
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator=(T rhs) {
            const auto maxBytes = std::min(sizeof(rhs), m_data.size());
            std::fill(m_data.begin(), m_data.end(), 0);

            for(size_t i = 0; i < maxBytes; ++i) {
                m_data[i] = rhs & static_cast<uint8_t>(0xFF);
                rhs >>= 8;
            }

            return *this;
        }

        VariableUnsignedInteger& operator+=(const VariableUnsignedInteger& rhs) {
            return (*this = *this + rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator+=(const T& rhs) {
            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this += variableRhs;
        }

        VariableUnsignedInteger& operator-=(const VariableUnsignedInteger& rhs) {
            return (*this = *this - rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator-=(const T& rhs) {
            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this -= variableRhs;
        }

        VariableUnsignedInteger& operator*=(const VariableUnsignedInteger& rhs) {
            return (*this = *this * rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator*=(const T& rhs) {
            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this *= variableRhs;
        }

        VariableUnsignedInteger& operator/=(const VariableUnsignedInteger& rhs) {
            return (*this = *this / rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator/=(const T& rhs) {
            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this /= variableRhs;
        }

        VariableUnsignedInteger& operator%=(const VariableUnsignedInteger& rhs) {
            return (*this = *this % rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator%=(const T& rhs) {
            VariableUnsignedInteger variableRhs(sizeof(rhs));
            variableRhs = rhs;
            return *this %= variableRhs;
        }

        VariableUnsignedInteger& operator<<=(const VariableUnsignedInteger& rhs) {
            return (*this = *this << rhs);
        }

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator<<=(const T& rhs) {
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
            return *this != 0;
        }

        bool operator!() const {
            return *this == 0;
        }

        /////////////////////
        // other operators //
        /////////////////////

        VariableUnsignedInteger maxValue() const {
            VariableUnsignedInteger result(m_data.size());
            std::fill(result.m_data.begin(), result.m_data.end(), std::numeric_limits<decltype(m_data)::value_type>::max());

            return result;
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
        friend DivisonResult quotientAndRemainder(const VariableUnsignedInteger& value, const VariableUnsignedInteger& divisor);
        friend VariableUnsignedInteger operator++(VariableUnsignedInteger&, int);
        friend VariableUnsignedInteger operator--(VariableUnsignedInteger&, int);

        //////////////////////////////
        // bitwise operator friends //
        //////////////////////////////

        friend VariableUnsignedInteger operator<<(VariableUnsignedInteger, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator>>(VariableUnsignedInteger, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator~(VariableUnsignedInteger);

        template <template<typename> typename Operation>
        friend VariableUnsignedInteger applyBinaryOperationBetweenChunks(const VariableUnsignedInteger&, const VariableUnsignedInteger&);

        /////////////////////////////
        // stream operator friends //
        /////////////////////////////

        friend std::ostream& operator<<(std::ostream&, VariableUnsignedInteger);

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
            auto lhsChunk = i < lhs.m_data.size() ? lhs.m_data[i] : 0;
            auto rhsChunk = i < rhs.m_data.size() ? rhs.m_data[i] : 0;

            auto chunkSum = lhsChunk + rhsChunk + carry;

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

    VariableUnsignedInteger operator-(const VariableUnsignedInteger& value) {
        return ~value + 1U;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const T& rhs);

    VariableUnsignedInteger operator-(VariableUnsignedInteger lhs, const VariableUnsignedInteger& rhs) {
        const size_t maxBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        if(rhs > lhs) {
            return (std::max(lhs, rhs).maxValue() - (rhs - lhs)) + 1;
        }

        // need to make sure the carry is at least
        // two bytes larger than the "chunk" type
        // (one for signedness, one for magnitude)
        using carry_t = int32_t;
        static_assert(sizeof(carry_t) > (sizeof(VariableUnsignedInteger::chunk_t) + 1), "");

        for(size_t i = 0; i < maxBytes; ++i) {
            const carry_t lhsChunk = i < lhs.m_data.size() ? lhs.m_data[i] : 0;
            const carry_t rhsChunk = i < rhs.m_data.size() ? rhs.m_data[i] : 0;

            carry_t chunkSub = lhsChunk - rhsChunk;

            size_t borrowByteIndex = i;
            while(chunkSub < 0) {
                ++borrowByteIndex;

                if(lhs.m_data[borrowByteIndex] > 0) {
                    lhs.m_data[borrowByteIndex] -= 1;

                    for(size_t j = borrowByteIndex - 1; j != i; --j) {
                        lhs.m_data[j] = std::numeric_limits<VariableUnsignedInteger::chunk_t>::max();
                    }

                    chunkSub += std::numeric_limits<VariableUnsignedInteger::chunk_t>::max() + 1;
                }
            }

            // if this is false and chunkSub is non-zero, underflow!
            // TODO:
            // if i is out of bounds for lhs, we could just break out of the loop
            // but that would stop use detecting underflow. Pick one!
            if(i < lhs.m_data.size()) {
                lhs.m_data[i] = chunkSub;
            }
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
        const auto maxBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        VariableUnsignedInteger result(maxBytes);
        result = 0;

        if(lhs == 0 || rhs == 0) {
            return result;
        }

        using carry_t = uint16_t;
        static_assert(sizeof(carry_t) >= sizeof(decltype(lhs.m_data)::value_type) + 1, "");
        carry_t carry;

        std::vector<VariableUnsignedInteger> lhsResults;
        std::vector<VariableUnsignedInteger> rhsResults;

        VariableUnsignedInteger lhsResult(maxBytes);
        lhsResult = lhs;

        VariableUnsignedInteger rhsResult(maxBytes);
        rhsResult = rhs;

        lhsResults.push_back(lhsResult);
        rhsResults.push_back(rhsResult);

        while(lhsResults.back() != 1) {
            lhsResult = lhsResults.back() >> 1;
            rhsResult = rhsResults.back() << 1;

            lhsResults.push_back(lhsResult);
            rhsResults.push_back(rhsResult);
        }

        for(size_t i = 0; i < lhsResults.size(); ++i) {
            if(lhsResults[i] % 2 != 0) {
                result += rhsResults[i];
            }
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

    // TODO:
    // either hide quotientAndRemainder / its return type from the public interface
    // or
    // find a proper place for it

    struct DivisonResult {
        VariableUnsignedInteger quotient;
        VariableUnsignedInteger remainder;
    };

    DivisonResult quotientAndRemainder(const VariableUnsignedInteger& value, const VariableUnsignedInteger& divisor) {
        const auto maxBytes = std::max(value.m_data.size(), divisor.m_data.size());

        VariableUnsignedInteger remainder(maxBytes);
        remainder = 0;

        if(divisor == 1) {
            return { value, remainder };
        }

        // TODO:
        // What do if divisor == 0?

        VariableUnsignedInteger quotient(maxBytes);
        quotient = 0;

        const auto bitsInValue = value.m_data.size() * (sizeof(decltype(value.m_data)::value_type) * 8);

        for(size_t i = bitsInValue; i > 0; --i) {
            const auto bitIndex = i - 1;

            remainder <<= 1;

            // TODO:
            // should be able to break out of the loop if this is false,
            // investigate and do so if possible, otherwise explain why
            setBit(remainder.m_data.data(), 0, getBit(value.m_data.data(), bitIndex));

            if(remainder >= divisor) {
                remainder -= divisor;
                setBit(quotient.m_data.data(), bitIndex, Bit::One);
            }
        }

        return { quotient, remainder };
    }

    VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return quotientAndRemainder(lhs, rhs).quotient;
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
        return quotientAndRemainder(lhs, rhs).remainder;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs % variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator%(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs % rhs;
    }

    VariableUnsignedInteger& operator++(VariableUnsignedInteger& value) {
        value += 1;
        return value;
    }

    VariableUnsignedInteger operator++(VariableUnsignedInteger& value, int) {
        VariableUnsignedInteger oldValue(value.m_data.size());
        oldValue = value;

        value += 1;
        return oldValue;
    }

    VariableUnsignedInteger operator+(VariableUnsignedInteger value) {
        return value;
    }

    VariableUnsignedInteger& operator--(VariableUnsignedInteger& value) {
        value -= 1;
        return value;
    }

    VariableUnsignedInteger operator--(VariableUnsignedInteger& value, int) {
        VariableUnsignedInteger oldValue(value.m_data.size());
        oldValue = value;

        value -= 1;
        return oldValue;
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
                    if(getBit(&lhs.m_data[chunkIndex], (sizeof(decltype(lhs.m_data)::value_type) * 8) - 1) == Bit::One) {
                        setBit(&lhs.m_data[chunkIndex + 1], 0, Bit::One);
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

    VariableUnsignedInteger operator>>(VariableUnsignedInteger lhs, VariableUnsignedInteger rhs) {
        // TODO:
        // if the user was using an uint8_t (for example), and shift by > 7, it's UB
        // it might be nice to have an exception thrown in those circumstances

        for(; rhs > 0; --rhs) {
            for(size_t i = 0; i < lhs.m_data.size(); ++i) {

                if(i != 0) {
                    if(getBit(&lhs.m_data[i], 0) == Bit::One) {
                        setBit(&lhs.m_data[i - 1], (sizeof(decltype(lhs.m_data)::value_type) * 8) - 1, Bit::One);
                    }
                }

                // TODO:
                // I know, I know! Shifting one bit at a time will be slow as hell...
                // the algorithm should be changed and a test should be added for large lhs and rhs values.
                lhs.m_data[i] >>= 1;
            }
        }

        return lhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    VariableUnsignedInteger operator>>(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs >> variableRhs;
    }

    template <template<typename> typename Operation>
    VariableUnsignedInteger applyBinaryOperationBetweenChunks(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        constexpr Operation<VariableUnsignedInteger::chunk_t> operation;

        VariableUnsignedInteger result(std::max(lhs.m_data.size(), rhs.m_data.size()));
        result = 0;

        for(size_t i = 0; i < result.m_data.size(); ++i) {
            const auto lhsChunk = i < lhs.m_data.size() ? lhs.m_data[i] : 0;
            const auto rhsChunk = i < rhs.m_data.size() ? rhs.m_data[i] : 0;

            result.m_data[i] = operation(lhsChunk, rhsChunk);
        }

        return result;
    }

    VariableUnsignedInteger operator&(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_and>(lhs, rhs);
    }

    VariableUnsignedInteger operator^(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_xor>(lhs, rhs);
    }

    VariableUnsignedInteger operator|(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_or>(lhs, rhs);
    }

    VariableUnsignedInteger operator~(VariableUnsignedInteger value) {
        for(size_t i = 0; i < value.m_data.size(); ++i) {
            value.m_data[i] = ~value.m_data[i];
        }

        return value;
    }

    //////////////////////
    // stream operators //
    //////////////////////

    std::ostream& operator<<(std::ostream& stream, VariableUnsignedInteger value) {
        VariableUnsignedInteger divisor(1);
        divisor = 10;

        std::vector<std::string> reversedResult;

        do {
            const auto quotientAndRemainderResult = quotientAndRemainder(value, divisor);

            reversedResult.push_back(std::to_string(quotientAndRemainderResult.remainder.m_data[0]));

            value = quotientAndRemainderResult.quotient;
        } while(value != 0);

        for(auto reverseIter = reversedResult.crbegin(); reverseIter != reversedResult.crend(); ++reverseIter) {
            stream << *reverseIter;
        }

        return stream;
    }

    std::istream& operator>>(std::istream& stream, VariableUnsignedInteger& value) {
        value = 0;

        for(char character = stream.get(); ! (stream.eof() || std::isspace(character)); character = stream.get()) {
            value *= 10;

            const char buffer[] = { character, '\0' };

            value += atoi(&buffer[0]);
        }

        return stream;
    }
}

