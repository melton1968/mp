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

template<size_t N>
using CharArray = std::array<char,N>;

static constexpr auto a0 = Array<0>{};
static constexpr auto a3 = Array<3>{1, 2, 3};

TEST(MP, ArrayProduct)
{
    constexpr auto r0 = mp::array_product(a3);
    static_assert(r0 == 6);
}

TEST(MP, ArrayFind)
{
    constexpr auto r0 = mp::array_find<int,1>(a3);
    static_assert(r0 == 0, "Index should be 0");
    
    constexpr auto r1 = mp::array_find<int,2>(a3);
    static_assert(r1 == 1, "Index should be 1");

    constexpr auto r2 = mp::array_find<int,0>(a3);
    static_assert(r2 == 3, "Index should be 3");
}

TEST(MP, ArraySplit)
{
    constexpr auto p0 = mp::array_split<char, '.', '1', '2', '.', '3', '4'>();
    static_assert(p0.first == CharArray<2>{'1', '2'}, "Array should be {1, 2}");
    static_assert(p0.second == CharArray<2>{'3', '4'}, "Array should be {3, 4}");
    
    constexpr auto p1 = mp::array_split<char, '.', '1', '2'>();
    static_assert(p1.first == CharArray<2>{'1', '2'}, "Array should be {1, 2}");
    static_assert(p1.second == CharArray<0>{}, "Array should be {}");
    
    constexpr auto p2 = mp::array_split<char, '.', '1', '2', '.'>();
    static_assert(p2.first == CharArray<2>{'1', '2'}, "Array should be {1, 2}");
    static_assert(p2.second == CharArray<0>{}, "Array should be {}");
    
    constexpr auto p3 = mp::array_split<char, '.', '.', '1', '2'>();
    static_assert(p3.first == CharArray<0>{}, "Array should be {}");
    static_assert(p3.second == CharArray<2>{'1', '2'}, "Array should be {1, 2}");
}

TEST(MP, ArraySlice)
{
    constexpr auto r0 = mp::array_slice<0, 2>(a3);
    static_assert(r0 == Array<2>{1, 2}, "Array should be {1, 2}");
    
    constexpr auto r1 = mp::array_slice<2,a3.size()>(a3);
    static_assert(r1 == Array<1>{3}, "Array should be {3}");
}

TEST(MP, ArraySliceFrom)
{
    constexpr auto r0 = mp::array_slice_from<1>(a3);
    static_assert(r0 == Array<2>{2, 3}, "Array should be {2, 3}");
    
    constexpr auto r1 = mp::array_slice_to<2>(a3);
    static_assert(r1 == Array<2>{1, 2}, "Array should be {1, 2}");
}

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
