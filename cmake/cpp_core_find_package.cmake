cmake_minimum_required (VERSION 3.24 FATAL_ERROR)

function(cpp_core_find_package NAME)
  cmake_parse_arguments(CCFP
    "EXCLUDE_FROM_ALL" # options
    "URL;VERSION" # single-value arguments
    "" # multi-value arguments
    ${ARGN}
    )

  if (DEFINED CCFP_URL)
    set(URL ${CCFP_URL})
  else()
    set(URL https://github.com/cpp-core/${NAME})
  endif()
  
  message("-- cpp_core_find_package NAME: ${NAME}")
  message("-- cpp_core_find_package URL: ${URL}")
  message("-- cpp_core_find_package VERSION: ${CCFP_VERSION}")
  
  include(FetchContent)

  if (DEFINED CCFP_VERSION)
    FetchContent_Declare(
      ${NAME}
      GIT_REPOSITORY ${URL}
      GIT_TAG ${CCFP_VERSION}
      GIT_SHALLOW TRUE
      FIND_PACKAGE_ARGS
      )
  else()
    FetchContent_Declare(
      ${NAME}
      GIT_REPOSITORY ${URL}
      GIT_TAG main
      GIT_SHALLOW TRUE
      FIND_PACKAGE_ARGS
      )
  endif()

  FetchContent_GetProperties(${NAME})
  string(TOLOWER "${NAME}" lc_name)
  
  if (NOT ${lc_name}_POPULATED)
    FetchContent_Populate(${NAME})
    if (${CCFP_EXCLUDE_FROM_ALL})
      add_subdirectory(${${lc_name}_SOURCE_DIR} ${${lc_name}_BINARY_DIR} EXCLUDE_FROM_ALL)
    else()
      add_subdirectory(${${lc_name}_SOURCE_DIR} ${${lc_name}_BINARY_DIR})
    endif()
  endif()
  
endfunction()

function(cpp_core_find_package_local NAME URL)
  message("-- cpp_core_find_package_local NAME: ${NAME}")
  message("-- cpp_core_find_package_local URL: ${URL}")
  
  include(FetchContent)

  FetchContent_Declare(
    ${NAME}
    GIT_REPOSITORY ${URL}
    GIT_TAG main
    GIT_SHALLOW TRUE
    FIND_PACKAGE_ARGS
    )
  FetchContent_MakeAvailable(${NAME})
  
endfunction()
