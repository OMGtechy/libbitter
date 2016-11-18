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

namespace bitter {
    template <typename T>
    constexpr void setBit(T* const target, size_t bitNumber, const Bit bitValue) {
        char* const castTarget = reinterpret_cast<char* const>(target);

        const size_t byteNumber = bitNumber / 8;
        bitNumber %= 8;

        char* const targetByte = (castTarget + byteNumber);

        // if you want to set bit 3 of byte 00111000 for example:
        // 00111000 = (00111000 & 11111011) | (00000100)
        *targetByte = (*targetByte & ~(1 << bitNumber)) | (static_cast<int>(bitValue) << bitNumber);
    }
}

