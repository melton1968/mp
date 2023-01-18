// Copyright (C) 2017, 2018, 2019, 2021, 2022, 2023 by Mark Melton
//

#pragma once
#include <cstdlib>
#include <memory>
#include <string>
#include <cxxabi.h>

namespace core::mp {

inline std::string demangle(const char* name)
{
    int status = -4;
    std::unique_ptr<char, void(*)(void*)> result
    { abi::__cxa_demangle(name, NULL, NULL, &status), std::free };
    return (status == 0) ? result.get() : name;
}

template<class T>
std::string decorate(const std::string& name) {
    std::string r = std::is_const_v<std::remove_reference_t<T>> ? "const " : "";
    r += std::is_pointer_v<T> ? "*" : "";
    r += name;
    r += std::is_lvalue_reference_v<T> ? "&" : "";
    r += std::is_rvalue_reference_v<T> ? "&&" : "";
    return r;
}

inline std::string demangle(std::string const& name)
{ return demangle(name.c_str()); }

template <class T>
std::string type_name()
{
    if constexpr (std::is_same_v<std::decay_t<T>, __int128_t>)
	return decorate<T>("int128");
    else if constexpr (std::is_same_v<std::decay_t<T>, __uint128_t>)
	return decorate<T>("unsigned int128");
    else if constexpr (std::is_same_v<std::decay_t<T>, std::string>)
	return decorate<T>("string");
    else 
	return decorate<T>(demangle(typeid(T).name()));
}

template <class T>
std::string type_name(const T& t)
{ return type_name<T>(); }


template<class T>
constexpr std::string_view function_name()
{
    char const* p = __PRETTY_FUNCTION__;
    while (*p++ != '=');
    for (; *p == ' '; ++p);
    char const* p2 = p;
    int count = 1;
    for (;;++p2)
    {
        switch (*p2)
        {
        case '[':
            ++count;
            break;
        case ']':
            --count;
            if (!count)
                return {p, std::size_t(p2 - p)};
        }
    }
    return {};
}

template<class T>
inline static auto type_name_v = type_name<T>();

template<class T>
struct custom_type_name {
    inline static auto value = type_name<T>();
};

template<class T>
inline static auto custom_type_name_v = custom_type_name<T>::value;

}; // core::mp
