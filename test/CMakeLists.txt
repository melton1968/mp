cmake_minimum_required (VERSION 3.12 FATAL_ERROR)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

find_package(googletest REQUIRED)
find_package(Threads REQUIRED)

set(TESTS
  mp/append
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
  mp/transform
  mp/type_name
  mp/union
  mp/unique
  )


include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
set(LIBS "cxx_core_mp;googletest::cxx-googletest;Threads::Threads")
configure_tests("core" "${LIBS}" ${TESTS})
