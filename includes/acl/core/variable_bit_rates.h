#pragma once

////////////////////////////////////////////////////////////////////////////////
// The MIT License (MIT)
//
// Copyright (c) 2020 Nicholas Frechette & Animation Compression Library contributors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#include "acl/core/error.h"
#include "acl/core/impl/compiler_utils.h"

#include <cstdint>

ACL_IMPL_FILE_PRAGMA_PUSH

namespace acl
{
	// Bit rate 0 is reserved for tracks that are constant in a segment
	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr uint8_t k_bit_rate_num_bits[] = { 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 32 };

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr uint8_t k_invalid_bit_rate = 0xFF;

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr uint8_t k_lowest_bit_rate = 1;

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr uint8_t k_highest_bit_rate = 18;

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr uint32_t k_num_bit_rates = 19;

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	inline uint32_t get_num_bits_at_bit_rate(uint32_t bit_rate)
	{
		ACL_ASSERT(bit_rate <= 18, "Invalid bit rate: %u", bit_rate);
		constexpr uint8_t bit_rate_num_bits[] = { 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 32 };
		return bit_rate_num_bits[bit_rate];
	}

	// Track is constant, our constant sample is stored in the range information
	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr bool is_constant_bit_rate(uint32_t bit_rate) { return bit_rate == 0; }

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	constexpr bool is_raw_bit_rate(uint32_t bit_rate) { return bit_rate == 18; }

	ACL_DEPRECATED("Internal implementation detail; to be removed in v3.0")
	struct BoneBitRate
	{
		uint8_t rotation;
		uint8_t translation;
		uint8_t scale;
	};
}

ACL_IMPL_FILE_PRAGMA_POP
