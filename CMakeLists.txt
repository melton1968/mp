cmake_minimum_required (VERSION 3.22 FATAL_ERROR)
project (cxx_core_mp VERSION 0.1 LANGUAGES C CXX)

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
include(GNUInstallDirs)
find_package(cxx_core_pp)

# Output configuration
#
message("-- cxx-core-mp: Configuration: ${CMAKE_CURRENT_SOURCE_DIR}")
message("-- cxx-core-mp: Included from: ${CMAKE_SOURCE_DIR}")
message("-- cxx-core-mp: CORE_MP_TEST ${CORE_MP_TEST}")
message("-- cxx-core-mp: CORE_MP_DOCS ${CORE_MP_DOCS}")
message("-- cxx-core-mp: DEPENDS_BUILD_DIR ${DEPENDS_BUILD_DIR}")
message("-- cxx-core-mp: DEPENDS_INSTALL_DIR ${DEPENDS_INSTALL_DIR}")

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
target_include_directories(cxx_core_mp
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

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

# Installation
#
install(TARGETS cxx_core_mp
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

# The CMake config installation
#
set(CONFIG_VERSION_NAME "${PROJECT_NAME}ConfigVersion.cmake")
set(CONFIG_NAME "${PROJECT_NAME}Config.cmake")
set(CONFIG_FILE_IN "${PROJECT_SOURCE_DIR}/cmake/${CONFIG_NAME}.in")
set(CONFIG_FILE "${PROJECT_BINARY_DIR}/${CONFIG_NAME}")

message("-- cxx-core-mp: CONFIG_VERSION_NAME ${CONFIG_VERSION_NAME}")
message("-- cxx-core-mp: CONFIG_NAME ${CONFIG_NAME}")
message("-- cxx-core-mp: CONFIG_FILE ${CONFIG_FILE}")

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CONFIG_VERSION_NAME}
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

configure_package_config_file(${CONFIG_FILE_IN} ${CONFIG_FILE}
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(EXPORT ${PROJECT_NAME}_Targets
        FILE ${PROJECT_NAME}Targets.cmake
        NAMESPACE ${PROJECT_NAME}::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(FILES
  "${CONFIG_FILE}"
  "${PROJECT_BINARY_DIR}/${CONFIG_VERSION_NAME}"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/core/mp DESTINATION include/core)

