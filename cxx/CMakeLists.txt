# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.0)

# Set the project name
project (SlatorKosterFT)

find_package( SWIG REQUIRED )
include( ${SWIG_USE_FILE} )

find_package( PythonLibs 3.6 REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

include_directories( ${PROJECT_SOURCE_DIR}/include )

# Set compiler clang++
set (CMAKE_CXX_COMPILER clang++)
# c11 features required
set (CMAKE_CXX_STANDARD 11)
# Compiler flags
set (CMAKE_CXX_FLAGS "-O3")

# Create a sources variable with a link to all cpp files to compile
set (SLATOR_KOSTER
     src/SlatorKoster.cpp
     src/test.cpp
)

set (SIMPSON_2D
	 src/testSimpson2d.cpp
)

set (SWIG_SLATOR_KOSTER
	 include/SlatorKoster.h
	 src/SlatorKoster.cpp
	 src/SlatorKoster.i
)

set (CMAKE_SWIG_FLAGS "")

# Add an executable with the above sources
add_executable(testSlatorKoster ${SLATOR_KOSTER})

# Set the direcoties that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
target_include_directories(testSlatorKoster
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

add_executable(testSimpson2d ${SIMPSON_2D})

target_include_directories(testSimpson2d
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

set_source_files_properties(src/SlatorKoster.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(src/SlatorKoster.i PROPERTIES SWIG_FLAGS "-I${PROJECT_SOURCE_DIR}/include")
swig_add_module(SlatorKoster python ${SWIG_SLATOR_KOSTER})

swig_link_libraries(SlatorKoster ${PYTHON_LIBRARIES})