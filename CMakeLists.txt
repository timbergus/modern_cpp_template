cmake_minimum_required(VERSION 3.10.0)
project(modern_cpp_template VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use your own name.
set(AUTHOR "Your name here")
# Set a proper description for your project.
set(DESCRIPTION "Your project description here")

add_compile_options(-Wall -Wextra -Werror -Wpedantic)

# >>> Include your own library
add_library(my_lib STATIC src/lib/my_lib.cpp)
target_include_directories(my_lib PUBLIC src/include)
# <<< Include your own library

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE my_lib)

include(CTest)
enable_testing()

# >>> Doxygen setup
find_package(Doxygen REQUIRED)

if (DOXYGEN_FOUND)
  set(DOXYGEN_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/docs)
  set(DOXYGEN_INPUT_DIR ${CMAKE_SOURCE_DIR}/src)

  # file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

  set(DOXYGEN_IN ${CMAKE_SOURCE_DIR}/Doxyfile)
  set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/Doxyfile)

  configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

  add_custom_target(docs
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

# >>> CPACK
include(InstallRequiredSystemLibraries)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${DESCRIPTION})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_VENDOR ${AUTHOR})
set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PROJECT_NAME}-${CPACK_PROJECT_VERSION}")
include(CPack)
# <<< CPACK
