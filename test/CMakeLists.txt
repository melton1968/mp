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
  mp/union
  mp/unique
  )


include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/configure_tests.cmake)
set(LIBS "cxx_core_mp;googletest::cxx-googletest;Threads::Threads")
configure_tests("core" "${LIBS}" ${TESTS})

# foreach(NAME ${TESTS})
#   get_filename_component(DIRNAME ${NAME} DIRECTORY)
#   get_filename_component(BASENAME ${NAME} NAME_WE)
#   string(REPLACE / _ CATNAME ${NAME})
  
#   set(TEST_NAME test_${CATNAME})
#   set(TEST_FILE1 ${PROJECT_SOURCE_DIR}/test/src/core/${DIRNAME}/test_${BASENAME}.cpp)
#   set(TEST_FILE2 ${PROJECT_SOURCE_DIR}/test/src/core/${DIRNAME}/test_${CATNAME}.cpp)
#   if(EXISTS ${TEST_FILE1})
#     set(TEST_FILE ${TEST_FILE1})
#   elseif(EXISTS ${TEST_FILE2})
#     set(TEST_FILE ${TEST_FILE2})
#   else()
#     message(FATAL "Cannot find test file for ${NAME}")
#   endif()

#   add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${TEST_FILE})
#   add_test(${TEST_NAME} bin/${TEST_NAME})
  
#   target_link_libraries(${TEST_NAME}
#     PUBLIC cxx_core_mp googletest::cxx-googletest Threads::Threads)
  
#   target_include_directories(${TEST_NAME}
#     PUBLIC ../include/core)
  
#   add_dependencies(check ${TEST_NAME})
#   add_dependencies(check_detail ${TEST_NAME})
# endforeach(NAME)

