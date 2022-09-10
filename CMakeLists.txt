cmake_minimum_required (VERSION 3.22 FATAL_ERROR)
project (cxx-core-mp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET cxx_core_mp)
  return()
endif()

# Configuration variables.
#
# Build the tests and set directories if this is the master project
#
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(CORE_MP_TEST ON CACHE BOOL "Generate the tests.")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_DOCS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
  
  # Have cmake output the compilation commands
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# Options for generating tests and documentation.
#
option(CORE_MP_TEST "Generate the tests." OFF)
option(CORE_MP_DOCS "Generate the docs." OFF)

# Add our dependencies
#
add_subdirectory(extern/cxx-depends)
add_dependencies(cxx_depends cxx_core_pp)

# Output configuration
#
message("-- cxx-core: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- cxx-core: Included from: ${CMAKE_SOURCE_DIR}")
message("-- cxx-core: CORE_MP_TEST ${CORE_MP_TEST}")
message("-- cxx-core: CORE_MP_DOCS ${CORE_MP_DOCS}")
message("-- cxx-core: DEPENDS_BUILD_DIR ${DEPENDS_BUILD_DIR}")
message("-- cxx-core: DEPENDS_INSTALL_DIR ${DEPENDS_INSTALL_DIR}")

# Compilation
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-stdlib=libc++)
add_compile_options(-O)
add_link_options(-stdlib=libc++)

add_library(cxx_core_mp INTERFACE)
target_include_directories(cxx_core_mp INTERFACE include)

# set(SOURCES
#   )

# foreach(NAME ${SOURCES})
#   list(APPEND FILES "src/core/${NAME}.cpp")
# endforeach()

# add_library(cxx_core_mp ${FILES})
# target_link_libraries(cxx_core_mp)
# target_include_directories(cxx_core_mp PUBLIC include)

# set(TOOLS
#   )

# foreach(NAME ${TOOLS})
#   add_executable(${NAME} src/tools/${NAME}.cpp)
#   target_link_libraries(${NAME} PUBLIC cxx_core_mp Threads::Threads)
# endforeach()

# Optionally configure the tests
#
if(CORE_MP_TEST)
  enable_testing()
  if (NOT TARGET check)
    add_custom_target(check ${CMAKE_CTEST_COMMAND})
    add_custom_target(check_detail ${CMAKE_CTEST_COMMAND} -V)
  endif()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(CORE_MP_DOCS)
  add_subdirectory(docs)
endif()
