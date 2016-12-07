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

#include <bitter_bit.hpp>

///
/// INTERFACE
///

namespace bitter {
    //!
    //! \brief  Sets the state of a bit
    //!
    //! \tparam  T  the type the target pointer points to,
    //!             should be inferred from the parameter,
    //!             do not set this explicitly
    //!
    //! \param[out]  target     where to write to
    //! \param[in]   bitNumber  which bit to set (zero-indexed)
    //! \param[in]   bitValue   what to set the bit to
    //!
    //! \par Example
    //! \code
    //!     uint8_t data[] = { 0, 255 };
    //!     setBit(&data, 0, Bit::One);  // data[0] is now 1
    //!     setBit(&data, 8, Bit::Zero); // data[1] is now 254
    //! \endcode
    //!
    //! \warning  this function necessarily dereferences
    //!           the \p target pointer, so make sure it
    //!           points to valid memory!
    //!
    //! \see  #getBit
    //! \see  #Bit
    //!
    template <typename T>
    constexpr void setBit(T* target, size_t bitNumber, Bit bitValue);
}

///
/// IMPLEMENTATION
///

template <typename T>
constexpr void bitter::setBit(T* const target, size_t bitNumber, const bitter::Bit bitValue) {
    char* const castTarget = reinterpret_cast<char* const>(target);

    const size_t byteNumber = bitNumber / 8;
    bitNumber %= 8;

    char* const targetByte = (castTarget + byteNumber);

    // if you want to set bit 3 of byte 00111000 for example:
    // 00111000 = (00111000 & 11111011) | (00000100)
    *targetByte = (*targetByte & ~(1 << bitNumber)) | (static_cast<int>(bitValue) << bitNumber);
}

