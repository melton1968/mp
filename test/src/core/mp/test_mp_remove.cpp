// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/remove.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Remove)
{
    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::remove_t<mp_f,L>;
	StaticAssertTypeEq<R,L>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_c,mp_e,mp_e>;
	using R = mp::remove_t<mp_a,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_a,mp_a,mp_e,mp_e>;
	using R = mp::remove_t<mp_c,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_a,mp_a,mp_c>;
	using R = mp::remove_t<mp_e,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<>;
	using R = mp::remove_t<mp_a,L>;
	StaticAssertTypeEq<R,L>();
    }
}

TEST(MP, RemoveList)
{
    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::remove_list_t<mp::list<mp_f>,L>;
	StaticAssertTypeEq<R,L>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_c,mp_e,mp_e>;
	using R = mp::remove_list_t<mp::list<mp_a>,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_c>;
	using R = mp::remove_list_t<mp::list<mp_a,mp_e>,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<mp_a,mp_a,mp_c,mp_e,mp_e>;
	using A = mp::list<mp_a,mp_a,mp_c>;
	using R = mp::remove_list_t<mp::list<mp_e>,L>;
	StaticAssertTypeEq<R,A>();
    }
    {
	using L = mp::list<>;
	using R = mp::remove_list_t<mp::list<mp_a>,L>;
	StaticAssertTypeEq<R,L>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
