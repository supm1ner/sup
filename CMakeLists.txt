cmake_minimum_required(VERSION 3.14)
project(SupCompiler VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(COMPILER_SOURCES
    src/Lexer.cpp
    src/Parser.cpp
    src/SemanticAnalyzer.cpp
    src/CodeGenerator.cpp
)

# Create compiler library
add_library(sup_compiler_lib ${COMPILER_SOURCES})

# Main executable
add_executable(sup src/main.cpp)
target_link_libraries(sup sup_compiler_lib)

# Testing
enable_testing()

# Google Test setup
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Test executable
file(GLOB_RECURSE TEST_SOURCES "tests/*.cpp")
add_executable(sup_tests ${TEST_SOURCES})
target_link_libraries(sup_tests sup_compiler_lib gtest_main)

# Add tests
include(GoogleTest)
gtest_discover_tests(sup_tests)

# Installation
install(TARGETS sup DESTINATION bin)
