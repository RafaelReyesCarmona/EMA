/*
EMA.h - Arduino library for Exponential Moving Average filter (EMA),
implemented very easily and efficiently.
v0.1.1

Copyright © 2022 Francisco Rafael Reyes Carmona.
All rights reserved.

rafael.reyes.carmona@gmail.com


  This file is part of EMA Library.

  EMA Library is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  EMA Library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with EMA Library.  If not, see <https://www.gnu.org/licenses/>.

*/

/* 
 *  This library is extracted from code "https://github.com/tttapa/tttapa.github.io/blob/
 *  master/Pages-src/Raw-HTML/Mathematics/Systems-and-Control-Theory/Digital-filters/
 *  Exponential%20Moving%20Average/resources/EMA-Arduino.ino"
 */

/* Autor: Pieter P
 * https://github.com/tttapa
 *
 *  tttapa/tttapa.github.io is licensed under the
 *
 *  GNU General Public License v3.0
 *  Permissions of this strong copyleft license are conditioned on making 
 *  available complete source code of licensed works and modifications, which 
 *  include larger works using a licensed work, under the same license. 
 *  Copyright and license notices must be preserved. Contributors provide an 
 *  express grant of patent rights.
 *  https://github.com/tttapa/tttapa.github.io/blob/master/LICENSE
 */

/*
 *    Filtering the result of `analogRead`: analogRead returns an integer
 *    between 0 and 1023, which can be represented using 10 bits, so 
 *    @f$ M = 10 @f$. Input is `uint16_t` so the maximum shift factor
 *    `K` is @f$ 16 - M = 6 @f$.
 */

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#ifndef EMA_h
#define EMA_h

#define zero 0

template <uint8_t K, class uint_t = uint16_t>
class EMA {
  public:
      /// Constructor: initialize filter to zero or optional given value.
    EMA(uint_t initial = uint_t(0))
      : state(zero + (uint_t(initial) << K) - initial) {}

    /// Update the filter with the given input and return the filtered output.
    uint_t operator()(uint_t input) {
        state += input;
        uint_t output = (state + half) >> K;
        state -= output;
        return output;
    }

    static_assert(
        uint_t(0) < uint_t(-1),  // Check that `uint_t` is an unsigned type
        "The `uint_t` type should be an unsigned integer, otherwise, "
        "the division using bit shifts is invalid.");

    /// Fixed point representation of one half, used for rounding.
    constexpr static uint_t half = 1 << (K - 1);

  private:
    uint_t state;
};

#endif