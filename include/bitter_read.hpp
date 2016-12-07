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
    //! \brief  Retrieves the state of a bit
    //!
    //! \tparam  T  the type the source pointer points to,
    //!             should be inferred from the parameter,
    //!             do not set this explicitly
    //!
    //! \param[in]  source     where to read from
    //! \param[in]  bitNumber  which bit to retrieve (zero-indexed)
    //!
    //! \returns  #Bit::One if the bit is set,
    //!           #Bit::Zero if it is not.
    //!
    //! \par Example
    //! \code
    //!     constexpr uint8_t data[] = { 0, 1 };
    //!     const auto x = getBit(&data, 0); // returns Bit::Zero
    //!     const auto y = getBit(&data, 8); // returns Bit::One
    //! \endcode
    //!
    //! \warning  this function necessarily dereferences
    //!           the \p source pointer, so make sure it
    //!           points to valid memory!
    //!
    //! \see  #setBit
    //! \see  #Bit
    //!
    template <typename T>
    constexpr Bit getBit(const T* source, size_t bitNumber);
}

///
/// IMPLEMENTATION
///

template <typename T>
constexpr bitter::Bit bitter::getBit(const T* const source, size_t bitNumber) {
    const char* const castSource = reinterpret_cast<const char* const>(source);

    const size_t byteNumber = bitNumber / 8;
    bitNumber %= 8;

    return (*(castSource + byteNumber) & (1 << bitNumber)) ? Bit::One : Bit::Zero;
}

