// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "mp/list.h"
#include "mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Rename)
{
    {
	using L = std::tuple<mp_a>;
	using A = mp::rename_t<L,mp::list>;
	using R = mp::list<mp_a>;
	StaticAssertTypeEq<R,A>();
    }
}

TEST(MP, RenameToVoidFunction)
{
    {
	using L = std::tuple<int,std::string,float>;
	using A = mp::rename_to_void_function_t<L>;
	using R = std::function<void(int,std::string,float)>;
	StaticAssertTypeEq<R,A>();
    }
}

TEST(MP, Head)
{
    // {
    // 	using L = mp_list<>;
    // 	using R = mp_head<L>::type;
    // }
    
    {
	using L = mp::list<mp_a>;
	using R = mp::head_t<L>;
	StaticAssertTypeEq<R,mp_a>();
    }

    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::head_t<L>;
	StaticAssertTypeEq<R,mp_a>();
    }
}

TEST(MP, Second)
{
    // {
    // 	using L = mp::list<>;
    // 	using R = mp::second<L>::type;
    // }

    // {
    // 	using L = mp::list<mp::a>;
    // 	using R = typename mp::second<L>::type;
    // }

    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::second_t<L>;
	StaticAssertTypeEq<R,mp_b>();
    }
}

TEST(MP, Tail)
{
    // {
    // 	using L = mp::list<>;
    // 	using R = mp::tail<L>::type;
    // }

    {
    	using L = mp::list<mp_a>;
	using R = mp::tail_t<L>;
	StaticAssertTypeEq<R, mp::list<>>();
    }

    {
     	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = mp::tail_t<L>;
	StaticAssertTypeEq<R, mp::list<mp_b,mp_c,mp_d,mp_e>>();
    }
}

TEST(MP, Size)
{
    {
	using L = mp::list<>;
	using R = typename mp::size<L>::type;
	EXPECT_EQ(R::value, 0u);
    }

    {
	using L = mp::list<mp_a>;
	using R = typename mp::size<L>::type;
	EXPECT_EQ(R::value, 1u);
    }

    {
	using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
	using R = typename mp::size<L>::type;
	EXPECT_EQ(R::value, 5u);
	EXPECT_EQ(mp::size_v<L>, 5u);
    }
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
