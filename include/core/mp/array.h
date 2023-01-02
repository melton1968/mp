// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include <algorithm>
#include <array>

namespace core::mp {

template<class T, size_t N> requires std::is_integral_v<T>
consteval uint64_t array_product(const std::array<T, N>& arr) {
    T product{1};
    for (auto element : arr)
	product *= element;
    return product;
}

template<class T, T Elem, class U, size_t N>
requires std::is_same_v<T, U>
consteval int array_find(const std::array<U, N>& arr) {
    for (auto i = 0; i < arr.size(); ++i)
	if (arr[i] == Elem)
	    return i;
    return arr.size();
}

template<size_t From, size_t To, class T, size_t N>
consteval auto array_slice(const std::array<T, N>& arr) {
    std::array<T, To - From> r;
    for (auto i = 0; i < r.size(); ++i)
	r[i] = arr[i + From];
    return r;
}

template<size_t From, class T, size_t N>
requires (From < N)
consteval auto array_slice_from(const std::array<T, N>& arr) {
    std::array<T, N - From> r;
    for (auto i = 0; i < r.size(); ++i)
	r[i] = arr[i + From];
    return r;
}

template<size_t From, class T, size_t N>
requires (From >= N)
consteval auto array_slice_from(const std::array<T, N>& arr) {
    return std::array<T, 0>{};
}

template<size_t To, class T, size_t N>
requires (To <= N)
consteval auto array_slice_to(const std::array<T, N>& arr) {
    std::array<T, To> r;
    for (auto i = 0; i < r.size(); ++i)
	r[i] = arr[i];
    return r;
}

template<class T, T delim, T... Ts>
consteval auto array_split() {
    constexpr auto arr = std::array<T, sizeof...(Ts)>{Ts...};
    constexpr auto n = array_find<T, delim>(arr);
    constexpr auto avalid = n > 0, bvalid = n + 1 < arr.size();
    if constexpr (avalid and bvalid) 
	return std::pair{array_slice_to<n>(arr), array_slice_from<n + 1>(arr)};
    else if constexpr (avalid and not bvalid)
	return std::pair{array_slice_to<n>(arr), std::array<T, 0>{}};
    else if constexpr (not avalid and bvalid)
	return std::pair{std::array<T, 0>{}, array_slice_from<n + 1>(arr)};
    else if constexpr (not avalid and not bvalid)
	return std::pair{std::array<T, 0>{}, std::array<T, 0>{}};
}

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

template<class T, size_t N> requires (N > 0 and std::is_integral_v<T>)
consteval std::array<T, N> array_bit_or(const std::array<T, N>& arr, const auto n) {
    std::array<T, N> r = arr;
    r[0] |= n;
    return r;
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

template<class T, size_t N> requires (N > 0 and std::is_integral_v<T>)
consteval std::array<T, N> array_shift_left(const std::array<T, N>& arr, const int n) {
    std::array<T, N> r;
    r[0] = arr[0] << n;
    for (auto i = 1; i < N; ++i)
	r[i] = (arr[i] << n) bitor (arr[i-1] >> (sizeof(T) * CHAR_BIT - n));
    return r;
}

template<size_t M, class T, size_t N>
consteval auto array_resize(const std::array<T, N>& arr) {
    std::array<T, M> r{};
    for (auto i = 0; i < std::min(N, M); ++i)
	r[i] = arr[i];
    return r;
}

}; // core::mp
