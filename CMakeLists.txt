cmake_minimum_required(VERSION 3.21)

project(GPGPU-Test VERSION 1.0.0 LANGUAGES CXX)

# Debug Version may contain runtime checks and experimental features/implementations
set(MM_IS_DEBUG true)

configure_file(BuildConfig.h.in BuildConfig.h)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(GPGPU-Test main.cpp)


add_compile_definitions(M_IS_DEBUG=${MM_IS_DEBUG})


target_include_directories(GPGPU-Test PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

