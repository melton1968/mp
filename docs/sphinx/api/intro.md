
# Introduction

A central concept in C++ metaprogramming is a list of types. Variadic
templates are handy containers for lists of types and the variadic
template `core::mp::list_t` is the canonical list type for this
library. In most cases, any variadic template, e.g. std::tuple, will
work equally well. There is even an operation, `core::mp::rename_t`,
designed to provide interoperation between different variadic template
types.
