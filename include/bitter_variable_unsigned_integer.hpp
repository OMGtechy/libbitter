/*
    This file is part of libbitter.

    libbitter is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libbitter is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libbitter.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <algorithm>
#include <cstdint>
#include <istream>
#include <ostream>
#include <type_traits>
#include <vector>

#include <bitter_read.hpp>
#include <bitter_write.hpp>

///
/// INTERFACE
///

namespace bitter {
    class VariableUnsignedInteger;
    struct DivisionResult;

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
    inline VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const T& rhs);

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
    inline VariableUnsignedInteger operator+(const T& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator-(VariableUnsignedInteger lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const T& rhs);

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
    inline VariableUnsignedInteger operator-(const T& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, VariableUnsignedInteger rhs);

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
    inline VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, const T& rhs);

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
    inline VariableUnsignedInteger operator*(const T& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const T& rhs);

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
    inline VariableUnsignedInteger operator/(const T& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const T& rhs);

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
    inline VariableUnsignedInteger operator%(const T& lhs, const VariableUnsignedInteger& rhs);

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
    inline VariableUnsignedInteger& operator++(VariableUnsignedInteger& instance);

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
    inline VariableUnsignedInteger operator++(VariableUnsignedInteger& instance, int);

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
    inline VariableUnsignedInteger& operator--(VariableUnsignedInteger& instance);

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
    inline VariableUnsignedInteger operator--(VariableUnsignedInteger& instance, int);

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
    //!     const bool xIsLessThanY = x < y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is less than an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsLessThan42 = x < 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is less than a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsLessThanX = 42 < x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<(const T& lhs, const VariableUnsignedInteger& rhs);

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
    //!     const bool xIsLessThanOrEqualToY = x <= y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator<=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is less than or equal to an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsLessThanOrEqualTo42 = x <= 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<=(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is less than or equal to a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is less than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsLessThanOrEqualToX = 42 <= x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<=(const T& lhs, const VariableUnsignedInteger& rhs);

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
    //!     const bool xIsGreaterThanY = x > y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is greater than an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsGreaterThan42 = x > 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is greater than a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsGreaterThanX = 42 < x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>(const T& lhs, const VariableUnsignedInteger& rhs);

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
    //!     const bool xIsGreaterThanOrEqualToY = x >= y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator>=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is greater than or equal to an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsGreaterThanOrEqualTo42 = x >= 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>=(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is greater than or equal to a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is greater than or equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsGreaterThanOrEqualToX = 42 >= x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>=(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is equal to another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     const bool xIsEqualToY = x == y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is equal to an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsEqualTo42 = x == 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator==(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is equal to a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsEqualToX = 42 == x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator==(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if one VariableUnsignedInteger is not equal to another
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is not equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     const bool xIsNotEqualToY = x != y;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Checks if a VariableUnsignedInteger is not equal to an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is not equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool xIsNotEqualTo42 = x != 42;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator!=(const VariableUnsignedInteger& lhs, const T& rhs);

    //!
    //! \brief  Checks if an unsigned primitive is not equal to a VariableUnsignedInteger
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  true if \p lhs is not equal to \p rhs, false otherwise
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x
    //!     const bool fourtyTwoIsNotEqualToX = 42 != x;
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator!=(const T& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Left-shifts a VariableUnsignedInteger by another
    //!
    //! \param[in]  shiftee        the value to shift
    //! \param[in]  bitsToShiftBy  the number of bits to shift by
    //!
    //! \returns  \p shiftee, left-shifted by \p bitsToShiftBy bits
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 1;
    //!     y = 2;
    //!     const VariableUnsignedInteger shifted = x << y; // return value == 4
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator<<(VariableUnsignedInteger shiftee, VariableUnsignedInteger bitsToShiftBy);

    //!
    //! \brief  Left-shifts a VariableUnsignedInteger by an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  shiftee        the value to shift
    //! \param[in]  bitsToShiftBy  the number of bits to shift by
    //!
    //! \returns  \p shiftee, left-shifted by \p bitsToShiftBy bits
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedIntegers called x
    //!     x = 1;
    //!     const VariableUnsignedInteger shifted = x << 2; // return value == 4
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator<<(const VariableUnsignedInteger& shiftee, const T& bitsToShiftBy);

    //!
    //! \brief  Right-shifts a VariableUnsignedInteger by another
    //!
    //! \param[in]  shiftee        the value to shift
    //! \param[in]  bitsToShiftBy  the number of bits to shift by
    //!
    //! \returns  \p shiftee, right-shifted by \p bitsToShiftBy bits
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 4;
    //!     y = 2;
    //!     const VariableUnsignedInteger shifted = x >> y; // return value == 1
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator>>(VariableUnsignedInteger shiftee, VariableUnsignedInteger bitsToShiftBy);

    //!
    //! \brief  Right-shifts a VariableUnsignedInteger by an unsigned primitive
    //!
    //! \tparam  T  the type of the unsigned primitive
    //!
    //! \param[in]  shiftee        the value to shift
    //! \param[in]  bitsToShiftBy  the number of bits to shift by
    //!
    //! \returns  \p shiftee, right-shifted by \p bitsToShiftBy bits
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedIntegers called x
    //!     x = 4;
    //!     const VariableUnsignedInteger shifted = x >> 2; // return value == 1
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator>>(const VariableUnsignedInteger& shiftee, const T& bitsToShiftBy);

    //!
    //! \brief  Applies bitwise AND between two VariableUnsignedIntegers
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger with all the common bits between \p lhs and \p rhs set
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 5;
    //!     y = 9;
    //!     const VariableUnsignedInteger commonBits = x & y; return value == 1
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator&(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Applies bitwise XOR between two VariableUnsignedIntegers
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger with the non-common bits between \p lhs and \p rhs set
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 5;
    //!     y = 9;
    //!     const VariableUnsignedInteger exclusiveBits = x ^ y; return value == 12
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator^(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Applies bitwise OR between two VariableUnsignedIntegers
    //!
    //! \param[in]  lhs  the left operand
    //! \param[in]  rhs  the right operand
    //!
    //! \returns  a VariableUnsignedInteger with bits in either \p lhs or \p rhs set
    //!
    //! \par Example
    //! \code
    //!     // given two VariableUnsignedIntegers called x and y
    //!     x = 5;
    //!     y = 9;
    //!     const VariableUnsignedInteger setBits = x | y; return value == 13
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator|(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

    //!
    //! \brief  Applies bitwise NOT between to VariableUnsignedInteger
    //!
    //! \param[in]  value  the value to apply bitwise NOT to
    //!
    //! \returns  a VariableUnsignedInteger with all bits flipped
    //!
    //! \par Example
    //! \code
    //!     // given a VariableUnsignedInteger called x of size >= 1
    //!     x = 0;
    //!     const VariableUnsignedInteger flippedBits = ~x; // return value >= 255
    //! \endcode
    //!
    //! \relates  VariableUnsignedInteger
    //!
    inline VariableUnsignedInteger operator~(VariableUnsignedInteger value);

    class VariableUnsignedInteger {
    public:
        //!
        //! \brief  Creates a VariableUnsignedInteger
        //!
        //! \param[in]  numberOfBytes  how many bytes should be allocated (minimum),
        //!                            so that maxValue() >= pow(2, numberOfBytes * 8) - 1
        //!
        //! \returns  a VariableUnsignedInteger of at least the requested size
        //!
        //! \par Example
        //! \code
        //!     VariableUnsignedInteger example(42);
        //! \endcode
        //!
        explicit VariableUnsignedInteger(size_t numberOfBytes);

        //!
        //! \brief  Assigns the value of one VariableUnsignedInteger to another
        //!
        //! \param[in]  rhs  the value to assign
        //!
        //! \returns  the assigned-to instance
        //!
        //! \note  maxValue() may change as a result of this operation,
        //!        but do not rely upon this as it is not guaranteed
        //!
        //! \par Example
        //! \code
        //!     // given two VariableUnsignedIntegers called x and y
        //!     x = y;
        //!     // x == y is now true
        //! \endcode
        //!
        VariableUnsignedInteger& operator=(const VariableUnsignedInteger& rhs);

        //!
        //! \brief  Assigns an unsigned value to a VariableUnsignedInteger
        //!
        //! \tparam  T  the type of the unsigned value
        //!
        //! \param[in]  rhs  the unsigned value
        //!
        //! \returns  the assigned-to instance
        //!
        //! \note  if the value is > maxValue(),
        //!        the behaviour is undefined
        //!
        //! \par Example
        //! \code
        //!     // given a VariableUnsignedInteger called x
        //!     x = 42;
        //!     // x == 42 is now true
        //! \endcode
        //!
        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator=(T rhs);

        //!
        //! \brief  Add-assigns the value of one VariableUnsignedInteger to another
        //!
        //! \param[in]  rhs  the value to add-assign
        //!
        //! \returns  the add-assigned-to instance
        //!
        //! \note  maxValue() may change as a result of this operation,
        //!        but do not rely upon this as it is not guaranteed
        //!
        //! \par Example
        //! \code
        //!     // given two VariableUnsignedIntegers called x and y
        //!     x = 1;
        //!     y = 2;
        //!     x += y;
        //!     // x == 3 is now true
        //! \endcode
        //!
        VariableUnsignedInteger& operator+=(const VariableUnsignedInteger& rhs);

        //!
        //! \brief  Add-assigns an unsigned value to a VariableUnsignedInteger
        //!
        //! \tparam  T  the type of the unsigned value
        //!
        //! \param[in]  rhs  the unsigned value
        //!
        //! \returns  the add-assigned-to instance
        //!
        //! \note  if the new value is > maxValue(),
        //!        the behaviour is undefined
        //!
        //! \par Example
        //! \code
        //!     // given a VariableUnsignedInteger called x
        //!     x = 42;
        //!     x += 2;
        //!     // x == 44 is now true
        //! \endcode
        //!
        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator+=(const T& rhs);

        //!
        //! \brief  Subtract-assigns the value of one VariableUnsignedInteger from another
        //!
        //! \param[in]  rhs  the value to subtract-assign
        //!
        //! \returns  the subtract-assigned-to instance
        //!
        //! \par Example
        //! \code
        //!     // given two VariableUnsignedIntegers called x and y
        //!     x = 2;
        //!     y = 1;
        //!     x -= y;
        //!     // x == 1 is now true
        //! \endcode
        //!
        VariableUnsignedInteger& operator-=(const VariableUnsignedInteger& rhs);

        //!
        //! \brief  Subtract-assigns an unsigned value from a VariableUnsignedInteger
        //!
        //! \tparam  T  the type of the unsigned value
        //!
        //! \param[in]  rhs  the unsigned value
        //!
        //! \returns  the subtract-assigned-to instance
        //!
        //! \par Example
        //! \code
        //!     // given a VariableUnsignedInteger called x
        //!     x = 42;
        //!     x -= 2;
        //!     // x == 40 is now true
        //! \endcode
        //!
        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator-=(const T& rhs);

        VariableUnsignedInteger& operator*=(const VariableUnsignedInteger& rhs);

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator*=(const T& rhs);

        VariableUnsignedInteger& operator/=(const VariableUnsignedInteger& rhs);

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator/=(const T& rhs);

        VariableUnsignedInteger& operator%=(const VariableUnsignedInteger& rhs);

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator%=(const T& rhs);

        VariableUnsignedInteger& operator<<=(const VariableUnsignedInteger& rhs);

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator<<=(const T& rhs);

        VariableUnsignedInteger& operator>>=(const VariableUnsignedInteger& rhs);

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        VariableUnsignedInteger& operator>>=(const T& rhs);

        explicit operator bool() const;
        bool operator!() const;

        VariableUnsignedInteger maxValue() const;

        template <typename T,
                  typename = std::enable_if<std::is_unsigned<T>::value>>
        T toPrimitive() const;

        friend bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);
        friend bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);
        friend bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs);

        friend VariableUnsignedInteger operator+(const VariableUnsignedInteger&, const VariableUnsignedInteger&);
        friend VariableUnsignedInteger operator*(const VariableUnsignedInteger&, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator-(VariableUnsignedInteger, const VariableUnsignedInteger&);
        friend DivisionResult quotientAndRemainder(const VariableUnsignedInteger& value, const VariableUnsignedInteger& divisor);
        friend VariableUnsignedInteger operator++(VariableUnsignedInteger&, int);
        friend VariableUnsignedInteger operator--(VariableUnsignedInteger&, int);

        friend VariableUnsignedInteger operator<<(VariableUnsignedInteger, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator>>(VariableUnsignedInteger, VariableUnsignedInteger);
        friend VariableUnsignedInteger operator~(VariableUnsignedInteger);

        template <template<typename> typename Operation>
        friend VariableUnsignedInteger applyBinaryOperationBetweenChunks(const VariableUnsignedInteger&, const VariableUnsignedInteger&);

        friend std::ostream& operator<<(std::ostream&, VariableUnsignedInteger);

    private:
        using chunk_t = uint8_t;
        std::vector<chunk_t> m_data;
    };
}

///
/// IMPLEMENTATION
///

namespace bitter {
    inline VariableUnsignedInteger::VariableUnsignedInteger(const size_t numberOfBytes)
    : m_data(numberOfBytes, 0) {

    }

    //////////////////////////
    // assignment operators //
    //////////////////////////

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator=(const VariableUnsignedInteger& rhs) {
        // TODO:
        // This potentially changes the size of the integer.
        // What's the desired behaviour given different sizes?
        const auto targetSize = std::max(rhs.m_data.size(), m_data.size());

        m_data = rhs.m_data;
        m_data.resize(targetSize, 0);

        return *this;
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator=(T rhs) {
        const auto maxBytes = std::min(sizeof(rhs), m_data.size());
        std::fill(m_data.begin(), m_data.end(), 0);

        for(size_t i = 0; i < maxBytes; ++i) {
            m_data[i] = rhs & static_cast<uint8_t>(0xFF);
            rhs >>= 8;
        }

        return *this;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator+=(const VariableUnsignedInteger& rhs) {
        return (*this = *this + rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator+=(const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this += variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator-=(const VariableUnsignedInteger& rhs) {
        return (*this = *this - rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator-=(const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this -= variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator*=(const VariableUnsignedInteger& rhs) {
        return (*this = *this * rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator*=(const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this *= variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator/=(const VariableUnsignedInteger& rhs) {
        return (*this = *this / rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator/=(const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this /= variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator%=(const VariableUnsignedInteger& rhs) {
        return (*this = *this % rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator%=(const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this %= variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator<<=(const VariableUnsignedInteger& rhs) {
        return (*this = *this << rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator<<=(const T& rhs) {
        // TODO:
        // add test for this

        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this <<= variableRhs;
    }

    inline VariableUnsignedInteger& VariableUnsignedInteger::operator>>=(const VariableUnsignedInteger& rhs) {
        return (*this = *this >> rhs);
    }

    template <typename T,
              typename>
    inline VariableUnsignedInteger& VariableUnsignedInteger::operator>>=(const T& rhs) {
        // TODO:
        // add test for this

        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return *this >>= variableRhs;
    }

    ///////////////////////
    // boolean operators //
    ///////////////////////

    inline VariableUnsignedInteger::operator bool() const {
        return *this != 0;
    }

    inline bool VariableUnsignedInteger::operator!() const {
        return *this == 0;
    }

    /////////////////////
    // other operators //
    /////////////////////

    inline VariableUnsignedInteger VariableUnsignedInteger::maxValue() const {
        VariableUnsignedInteger result(m_data.size());
        std::fill(result.m_data.begin(), result.m_data.end(), std::numeric_limits<decltype(m_data)::value_type>::max());

        return result;
    }

    template <typename T,
              typename>
    inline T VariableUnsignedInteger::toPrimitive() const {
        if(m_data.size() < sizeof(T)) {
            VariableUnsignedInteger largerCopy(sizeof(T));
            largerCopy = *this;
            return largerCopy.toPrimitive<T>();
        }

        return *reinterpret_cast<const T*>(m_data.data());
    }

    //////////////////////////
    // arithmetic operators //
    //////////////////////////

    inline VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
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
    inline VariableUnsignedInteger operator+(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs + variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator+(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs + lhs;
    }

    inline VariableUnsignedInteger operator-(const VariableUnsignedInteger& value) {
        return ~value + 1U;
    }

    inline VariableUnsignedInteger operator-(VariableUnsignedInteger lhs, const VariableUnsignedInteger& rhs) {
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
    inline VariableUnsignedInteger operator-(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs - variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator-(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs - rhs;
    }

    inline VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, VariableUnsignedInteger rhs) {
        const auto maxBytes = std::max(lhs.m_data.size(), rhs.m_data.size());

        VariableUnsignedInteger result(maxBytes);
        result = 0;

        if(lhs == 0 || rhs == 0) {
            return result;
        }

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
    inline VariableUnsignedInteger operator*(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs * variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator*(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs * lhs;
    }

    // TODO:
    // either hide quotientAndRemainder / its return type from the public interface
    // or
    // find a proper place for it

    struct DivisionResult {
        VariableUnsignedInteger quotient;
        VariableUnsignedInteger remainder;
    };

    inline DivisionResult quotientAndRemainder(const VariableUnsignedInteger& value, const VariableUnsignedInteger& divisor) {
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

    inline VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return quotientAndRemainder(lhs, rhs).quotient;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator/(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs / variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator/(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs / rhs;
    }

    inline VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return quotientAndRemainder(lhs, rhs).remainder;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator%(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs % variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline VariableUnsignedInteger operator%(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs % rhs;
    }

    inline VariableUnsignedInteger& operator++(VariableUnsignedInteger& value) {
        value += 1;
        return value;
    }

    inline VariableUnsignedInteger operator++(VariableUnsignedInteger& value, int) {
        VariableUnsignedInteger oldValue(value.m_data.size());
        oldValue = value;

        value += 1;
        return oldValue;
    }

    inline VariableUnsignedInteger operator+(VariableUnsignedInteger value) {
        return value;
    }

    inline VariableUnsignedInteger& operator--(VariableUnsignedInteger& value) {
        value -= 1;
        return value;
    }

    inline VariableUnsignedInteger operator--(VariableUnsignedInteger& value, int) {
        VariableUnsignedInteger oldValue(value.m_data.size());
        oldValue = value;

        value -= 1;
        return oldValue;
    }

    ///////////////////////
    // logical operators //
    ///////////////////////

    inline bool operator==(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
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
    inline bool operator==(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs == variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator==(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs == rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator!=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs != variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator!=(const T& lhs, const VariableUnsignedInteger& rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
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
    inline bool operator<(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs < variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs < rhs;
    }

    inline bool operator>(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return (lhs != rhs) && (! (lhs < rhs));
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs > variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs > rhs;
    }

    inline bool operator<=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs > rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs <= variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator<=(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs <= rhs;
    }

    inline bool operator>=(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return ! (lhs < rhs);
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>=(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs >= variableRhs;
    }

    template <typename T,
              typename = std::enable_if<std::is_unsigned<T>::value>>
    inline bool operator>=(const T& lhs, const VariableUnsignedInteger& rhs) {
        VariableUnsignedInteger variableLhs(sizeof(lhs));
        variableLhs = lhs;
        return variableLhs >= rhs;
    }

    ///////////////////////
    // bitwise operators //
    ///////////////////////

    inline VariableUnsignedInteger operator<<(VariableUnsignedInteger lhs, VariableUnsignedInteger rhs) {
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
    inline VariableUnsignedInteger operator<<(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs << variableRhs;
    }

    inline VariableUnsignedInteger operator>>(VariableUnsignedInteger lhs, VariableUnsignedInteger rhs) {
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
    inline VariableUnsignedInteger operator>>(const VariableUnsignedInteger& lhs, const T& rhs) {
        VariableUnsignedInteger variableRhs(sizeof(rhs));
        variableRhs = rhs;
        return lhs >> variableRhs;
    }

    template <template<typename> typename Operation>
    inline VariableUnsignedInteger applyBinaryOperationBetweenChunks(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
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

    inline VariableUnsignedInteger operator&(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_and>(lhs, rhs);
    }

    inline VariableUnsignedInteger operator^(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_xor>(lhs, rhs);
    }

    inline VariableUnsignedInteger operator|(const VariableUnsignedInteger& lhs, const VariableUnsignedInteger& rhs) {
        return applyBinaryOperationBetweenChunks<std::bit_or>(lhs, rhs);
    }

    inline VariableUnsignedInteger operator~(VariableUnsignedInteger value) {
        for(size_t i = 0; i < value.m_data.size(); ++i) {
            value.m_data[i] = ~value.m_data[i];
        }

        return value;
    }

    //////////////////////
    // stream operators //
    //////////////////////

    inline std::ostream& operator<<(std::ostream& stream, VariableUnsignedInteger value) {
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

    inline std::istream& operator>>(std::istream& stream, VariableUnsignedInteger& value) {
        value = 0;

        for(char character = stream.get(); ! (stream.eof() || std::isspace(character)); character = stream.get()) {
            value *= 10;

            const char buffer[] = { character, '\0' };

            value += atoi(&buffer[0]);
        }

        return stream;
    }
}

