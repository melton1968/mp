// Copyright (C) 2017, 2018, 2019, 2022, 2023 by Mark Melton
//

#pragma once
#include <string>
#include <cstdint>

namespace core::mp {

template<typename T>
struct type_traits
{ };

template<>
struct type_traits<std::string>
{ constexpr static char const *name = "string"; };

template<>
struct type_traits<signed char>
{ constexpr static char const *name = "signed char"; };

template<>
struct type_traits<signed short>
{ constexpr static char const *name = "signed short"; };

template<>
struct type_traits<signed int>
{ constexpr static char const *name = "signed int"; };

template<>
struct type_traits<signed long>
{ constexpr static char const *name = "signed long"; };

template<>
struct type_traits<signed long long>
{ constexpr static char const *name = "signed long long"; };

template<>
struct type_traits<unsigned char>
{ constexpr static char const *name = "unsigned char"; };

template<>
struct type_traits<unsigned short>
{ constexpr static char const *name = "unsigned short"; };

template<>
struct type_traits<unsigned int>
{ constexpr static char const *name = "unsigned int"; };

template<>
struct type_traits<unsigned long>
{ constexpr static char const *name = "unsigned long"; };

template<>
struct type_traits<unsigned long long>
{ constexpr static char const *name = "unsigned long long"; };


template<>
struct type_traits<float>
{ constexpr static char const *name = "float"; };

template<>
struct type_traits<double>
{ constexpr static char const *name = "double"; };

template<>
struct type_traits<long double>
{ constexpr static char const *name = "long double"; };

}; // end ns core
