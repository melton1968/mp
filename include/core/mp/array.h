// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <algorithm>
#include <array>

namespace core::mp {

template<class T, size_t N, class... Us>
requires (sizeof...(Us) > 0)
consteval auto array_append(const std::array<T, N>& arr, Us... elements) {
    std::array<T, N + sizeof...(Us)> r;
    std::copy(arr.begin(), arr.end(), r.begin());

    std::array<T, sizeof...(Us)> other{T(elements)...};
    std::copy(other.begin(), other.end(), r.begin() + N);
    return r;
}

template<class T, size_t N>
requires (N > 0)
consteval auto array_append(const std::array<T, N>& arr) {
    std::array<T, N> r;
    std::copy(arr.begin(), arr.end(), r.begin());
    return r;
}

template<class T, size_t N>
requires (N == 0)
consteval auto array_append(const std::array<T, N>& arr) {
    return std::array<T, N>{};
}

template<size_t M, class T, size_t N>
consteval auto array_drop(const std::array<T, N>& arr) {
    std::array<T, N - M> r;
    for (auto i = 0; i < r.size(); ++i)
	r[i] = arr[i + M];
    return r;
}

template<size_t M, class T, size_t N>
requires (M == N)
consteval auto array_drop(const std::array<T, N>& arr) {
    return std::array<T, 0>{};
}

template<class T, size_t N, class F>
consteval auto array_filter(const std::array<T, N>& arr, const F&& f) {
    std::array<T, N> r{};
    size_t rdx{0};
    for (auto elem : arr)
	if (f(elem))
	    r[rdx++] = elem;
    return std::pair{r, rdx};
}

template<size_t M, class T, size_t N>
consteval auto array_resize(const std::array<T, N>& arr) {
    std::array<T, M> r{};
    for (auto i = 0; i < std::min(N, M); ++i)
	r[i] = arr[i];
    return r;
}

}; // core::mp
