// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/array.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

constexpr bool filter1(int a) {
    return a != 2;
}

template<size_t N>
using Array = std::array<int,N>;

static constexpr auto a0 = Array<0>{};
static constexpr auto a3 = Array<3>{1, 2, 3};

TEST(MP, ArrayAppend)
{
    constexpr auto r0 = mp::array_append(a0, 42u);
    static_assert(r0 == Array<1>{ 42 }, "Array should be { 42 }");
    
    constexpr auto r1 = mp::array_append(a3, 42);
    static_assert(r1 == Array<4>{ 1, 2, 3, 42 }, "Array should be { 1, 2, 3, 42 }");
    
    constexpr auto r2 = mp::array_append(a0, 1, 2, 3);
    static_assert(r2 == Array<3>{ 1, 2, 3 }, "Array should be { 1, 2, 3 }");
    
    constexpr auto r3 = mp::array_append(a0);
    static_assert(r3 == Array<0>{}, "Array should be { }");
}

TEST(MP, ArrayBitOr)
{
    constexpr auto b0 = Array<2>{ 1, 2 };
    constexpr auto r = mp::array_bit_or(b0, 4);
    static_assert(r == Array<2>{ 5, 2 }, "Array should be { 5, 2 }");
}

TEST(MP, ArrayDrop)
{
    constexpr auto r0 = mp::array_drop<1>(a3);
    static_assert(r0 == Array<2>{ 2, 3 }, "Array should be { 2, 3 }");
    
    constexpr auto r1 = mp::array_drop<3>(a3);
    static_assert(r1 == Array<0>{}, "Array should be {}");
}

TEST(MP, ArrayFilter)
{
    constexpr auto r0 = mp::array_filter(a0, filter1);
    static_assert(r0.first == Array<0>{}, "Array should be {}");
    static_assert(r0.second == 0, "Array should be {}");
    
    constexpr auto r1 = mp::array_filter(a3, filter1);
    static_assert(r1.first == Array<3>{ 1, 3, 0 }, "Array should be { 1, 3 }");
    static_assert(r0.second == 0, "Array should be {}");
}

TEST(MP, ArrayShiftLeft)
{
    constexpr auto b0 = std::array<uint16_t,2>{ 0x1000, 1 };
    constexpr auto r = mp::array_shift_left(b0, 4);
    static_assert(r == std::array<uint16_t,2>{ 0, 0x11 }, "Array should be { 0, 17 }");
}

TEST(MP, ArrayResize)
{
    constexpr auto r0 = mp::array_resize<2>(a0);
    static_assert(r0 == Array<2>{}, "Array should be { 0, 0 }");
    
    constexpr auto r1 = mp::array_resize<2>(a3);
    static_assert(r1 == Array<2>{1, 2}, "Array should be { 1, 2 }");
    
    constexpr auto r2 = mp::array_resize<0>(a3);
    static_assert(r2 == Array<0>{}, "Array should be {}");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
