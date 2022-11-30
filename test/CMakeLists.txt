cmake_minimum_required (VERSION 3.24 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test/bin)

find_package(Threads REQUIRED)

set(TESTS
  mp/append
  mp/array
  mp/array_from_pack
  mp/at
  mp/cat
  mp/contains
  mp/enable_if
  mp/find_index
  mp/foreach
  mp/generate
  mp/homogeneous
  mp/if
  mp/intersect
  mp/is_integral_constant
  mp/is_subset_of
  mp/iterator
  mp/list
  mp/make_index_range
  mp/map_find
  mp/permutation
  mp/push_front
  mp/remove
  mp/same
  mp/sort
  mp/subtract
  mp/swap
  mp/traits/extrema
  mp/traits/number
  mp/traits/type
  mp/transform
  mp/type_name
  mp/union
  mp/unique
  )

set(LIBRARIES
  mp
  GTest::gtest
  Threads::Threads
  )

configure_tests("core" "${LIBRARIES}" ${TESTS})
