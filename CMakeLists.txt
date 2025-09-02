cmake_minimum_required(VERSION 4.1.1)
project(
  modern_cpp_template
  VERSION
    0.1.0
  DESCRIPTION
    "Your project description here"
  LANGUAGES
    C
    CXX
)

# Use your own name.
set(
  PROJECT_AUTHOR
    "Your name here"
)

set(
  MY_WARNINGS
    -Wall
    -Wextra
    -Wpedantic
    -Werror
)

include(FetchContent)

# >>> fmt library download
FetchContent_Declare(
  fmt
  GIT_REPOSITORY
    https://github.com/fmtlib/fmt.git
  GIT_TAG
    11.2.0
)
FetchContent_MakeAvailable(fmt)
# <<< fmt library download

# >>> cnmea library download
FetchContent_Declare(
  cnmea
  GIT_REPOSITORY
    https://github.com/timbergus/cnmea.git
  GIT_TAG
    v0.0.11
)
FetchContent_MakeAvailable(cnmea)
# <<< cnmea library download

# >>> Catch2 library download
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY
    https://github.com/catchorg/Catch2.git
  GIT_TAG
    v3.10.0
)
FetchContent_MakeAvailable(Catch2)
# <<< Catch2 library download

# >>> Include your header only library
add_library(my_ho_lib INTERFACE)
add_library(my_ho_lib::my_ho_lib
  ALIAS
    my_ho_lib
)

target_compile_options(my_ho_lib
  INTERFACE
    ${MY_WARNINGS}
)

target_include_directories(my_ho_lib
  INTERFACE
    src/include
)
# <<< Include your header only library

# >>> Include your static library
add_library(my_lib STATIC src/lib/my_lib.cpp)
add_library(my_lib::my_lib
  ALIAS
    my_lib
)

target_compile_options(my_lib
  PUBLIC
    ${MY_WARNINGS}
)

target_include_directories(my_lib
  PUBLIC
    src/include
)
# <<< Include your static library

add_executable(${PROJECT_NAME} src/main.cpp)

target_compile_options(${PROJECT_NAME}
  PRIVATE
    ${MY_WARNINGS}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    cnmea::cnmea
    fmt::fmt
    my_lib::my_lib
    my_ho_lib::my_ho_lib
)

# >>> Doxygen setup
find_package(Doxygen REQUIRED)

if (DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/docs)
  set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR}/src)

  # file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

  set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
  set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

  add_custom_target(${PROJECT_NAME}_docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
  )

  install(DIRECTORY ${DOXYGEN_OUTPUT_DIR}/html/
    DESTINATION docs
    COMPONENT docs
  )
endif()
# <<< Doxygen setup

# >>> CPack
include(InstallRequiredSystemLibraries)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR ${PROJECT_AUTHOR})
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
include(CPack)
# <<< CPack

# >>> Testing
include(CTest)
include(Catch)
enable_testing()

add_executable(congratulate_test ${CMAKE_SOURCE_DIR}/src/tests/congratulate_test.cpp)
target_link_libraries(congratulate_test
  fmt::fmt
  my_ho_lib::my_ho_lib
  Catch2::Catch2WithMain
)

catch_discover_tests(congratulate_test)
# <<< Testing
