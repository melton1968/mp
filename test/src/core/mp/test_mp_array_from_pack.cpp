// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/array_from_pack.h"

using namespace core;

template<size_t N>
using Array = std::array<int,N>;

TEST(MP, ArrayFromPack)
{
    constexpr auto r0 = mp::array_from_pack<int>();
    static_assert(r0 == Array<0>{}, "Array should be { }");
    
    constexpr auto r2 = mp::array_from_pack<char, 'a', 'b'>();
    static_assert(r2 == std::array<char, 2>{ 'a', 'b' }, "Array should be { 'a', 'b' }");
    
    constexpr auto r3 = mp::array_from_pack<int, 1, 2, 3>();
    static_assert(r3 == Array<3>{ 1, 2, 3 }, "Array should be { 1, 2 3 }");
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
