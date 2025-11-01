cmake_minimum_required(VERSION 3.22)

# Нужно изменить CMAKE_SOURCE_DIR, так как cubeMX генерирует список включаемых файлов 
# относительно CMAKE_SOURCE_DIR, а мы находимся в подпроекте
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME gen-stm32f103-lame-project)

# Include toolchain file
# include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
# add_executable(${CMAKE_PROJECT_NAME})
add_library(${CMAKE_PROJECT_NAME} OBJECT)
add_library(cubemx ALIAS ${CMAKE_PROJECT_NAME})


# Add STM32CubeMX generated sources
include(cmake/stm32cubemx/CMakeLists.txt)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
