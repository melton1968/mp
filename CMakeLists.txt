cmake_minimum_required (VERSION 3.22 FATAL_ERROR)
project (mp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET mp OR TARGET mp::mp)
  return()
endif()

# Options for generating tests and documentation.
#
option(MP_TEST "Generate the tests." OFF)
option(MP_DOCS "Generate the docs." OFF)

# If this is the current project.
#
if(PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME)
  # Include the cmake helpers
  #
  set(CPP_CORE_CMAKE_DIR ${CMAKE_SOURCE_DIR}/extern/pp/extern/cmake)
  include(${CPP_CORE_CMAKE_DIR}/utils/all.cmake)
  include(${CPP_CORE_CMAKE_DIR}/recipes/all.cmake)
  
  # Geneerte the tests
  #
  set(MP_TEST ON CACHE BOOL "Generate the tests." FORCE)

  # compile_commands.json
  #
  symlink_compile_commands()

  # Convenience targets for git operations
  #
  make_submodule_pull_target()
endif()

# Output configuration
#
message("-- mp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- mp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- mp: Install prefix ${CMAKE_INSTALL_PREFIX}")
message("-- mp: test ${MP_TEST}")
message("-- mp: docs ${MP_DOCS}")

# Setup compilation
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-stdlib=libc++)
add_compile_options(-O)
add_link_options(-stdlib=libc++)

# Add our dependencies
#
add_fmt()
add_pp()

# Build the library
#
add_library(mp INTERFACE)
add_library(mp::mp ALIAS mp) # Allow interop between FetchContent and FindPackage.

# Define the header files for this library.
#
file(GLOB_RECURSE PUBLIC_INCLUDE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)
target_sources(mp INTERFACE FILE_SET HEADERS BASE_DIRS include FILES ${PUBLIC_INCLUDE_FILES})

target_link_libraries(mp INTERFACE fmt::fmt pp::pp)

# Optionally configure the tests
#
if(MP_TEST)
  add_gtest()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(MP_DOCS)
  add_subdirectory(docs)
endif()

# Install config
#
install_config(mp)
