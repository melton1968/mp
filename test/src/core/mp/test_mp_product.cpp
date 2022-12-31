// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/product.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Product)
{
    using L0 = mp::list<>;
    using L1 = mp::list<mp_a>;
    using L2 = mp::list<mp_a,mp_b>;
    using J1 = mp::list<mp_d>;
    using J2 = mp::list<mp_d,mp_e>;
    using J3 = mp::list<mp_d,mp_e,mp_f>;

    using M11 = mp::list<std::pair<mp_a, mp_d>>;
    using M12 = mp::list<std::pair<mp_a, mp_d>, std::pair<mp_a, mp_e>>;
    using M13 = mp::list<std::pair<mp_a, mp_d>, std::pair<mp_a, mp_e>, std::pair<mp_a, mp_f>>;
    using M21 = mp::list<std::pair<mp_a, mp_d>, std::pair<mp_b, mp_d>>;
    using M22 = mp::list<std::pair<mp_a, mp_d>, std::pair<mp_a, mp_e>,
			 std::pair<mp_b, mp_d>, std::pair<mp_b, mp_e>>;
    using M23 = mp::list<std::pair<mp_a, mp_d>, std::pair<mp_a, mp_e>, std::pair<mp_a, mp_f>,
			 std::pair<mp_b, mp_d>, std::pair<mp_b, mp_e>, std::pair<mp_b, mp_f>>;

    (void)StaticAssertTypeEq<mp::product_t<L0,L0>, L0>;
    (void)StaticAssertTypeEq<mp::product_t<L0,L1>, L0>;
    (void)StaticAssertTypeEq<mp::product_t<L1,L0>, L0>;

    (void)StaticAssertTypeEq<mp::product_t<L1,J1>, M11>;
    (void)StaticAssertTypeEq<mp::product_t<L1,J2>, M12>;
    (void)StaticAssertTypeEq<mp::product_t<L1,J3>, M13>;
    
    (void)StaticAssertTypeEq<mp::product_t<L2,J1>, M21>;
    (void)StaticAssertTypeEq<mp::product_t<L2,J2>, M22>;
    (void)StaticAssertTypeEq<mp::product_t<L2,J3>, M23>;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
