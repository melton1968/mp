cmake_minimum_required (VERSION 3.22 FATAL_ERROR)
project (mp VERSION 0.1 LANGUAGES C CXX)

# Make including this file idempotent
#
if(TARGET mp OR TARGET mp::mp)
  return()
endif()

# Configuration variables.
#
# Build the tests and set directories if this is the master project
#
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(MP_TEST ON CACHE BOOL "Generate the tests.")
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
  set(CMAKE_DOCS_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/docs)
  
  # Have cmake output the compilation commands and create a link to it
  # from the project root directory so the language server can find
  # it.
  #
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json)
endif()

# Options for generating tests and documentation.
#
option(MP_TEST "Generate the tests." OFF)
option(MP_DOCS "Generate the docs." OFF)

# Add our dependencies
#
include(GNUInstallDirs)
include(cmake/cpp_core_find_package.cmake)

set(FMT_INSTALL ON CACHE INTERNAL "Have fmt create the install target")
cpp_core_find_package(fmt VERSION 9.1.0)
cpp_core_find_package(pp URL /Users/mmelton/work/cpp-core/pp)

# Output configuration
#
message("-- mp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- mp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- mp: MP_TEST ${MP_TEST}")
message("-- mp: MP_DOCS ${MP_DOCS}")
message("-- mp: CMAKE_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}")

# Compilation
#
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall)
add_compile_options(-stdlib=libc++)
add_compile_options(-O)
add_link_options(-stdlib=libc++)

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
  enable_testing()
  add_subdirectory(test)
endif()

# Optionally configure the documentation
#
if(MP_DOCS)
  add_subdirectory(docs)
endif()

# Install config
#
include(cmake/install_config.cmake)
install_config(mp)
