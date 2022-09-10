// Copyright (C) 2017, 2019 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/cat.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Cat)
{
    {
	using A = mp::cat_t<
	    mp::list<mp_a, mp_b>,
	    mp::list<mp_c, mp_d>,
	    mp::list<mp_e, mp_f>>;
	using R = mp::list<mp_a, mp_b, mp_c, mp_d, mp_e, mp_f>;
	StaticAssertTypeEq<R,A>();
    }
}

TEST(MP, CatNoLists)
{
    {
	using A = mp::cat_t<>;
	using R = mp::list<>;
	StaticAssertTypeEq<R,A>();
    }
}

TEST(MP, CatEmptyList)
{
    {
	using A = mp::cat_t<
	    mp::list<>,
	    mp::list<mp_c, mp_d>,
	    mp::list<mp_e, mp_f>>;
	using R = mp::list<mp_c, mp_d, mp_e, mp_f>;
	StaticAssertTypeEq<R,A>();
    }
}

TEST(MP, CatDups)
{
    {
	using A = mp::cat_t<
	    mp::list<mp_c, mp_d>,
	    mp::list<mp_c, mp_d>,
	    mp::list<mp_e, mp_f>>;
	using R = mp::list<mp_c, mp_d, mp_c, mp_d, mp_e, mp_f>;
	StaticAssertTypeEq<R,A>();
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
