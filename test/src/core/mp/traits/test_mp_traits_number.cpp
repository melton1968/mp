// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/traits/number.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, TraitsNumber)
{
    auto x = StaticAssertTypeEq<mp::next_larger_t<std::int8_t>, std::int16_t>;
    EXPECT_TRUE(x);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
