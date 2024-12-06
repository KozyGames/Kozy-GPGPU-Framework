cmake_minimum_required(VERSION 3.21)

project(miniTest VERSION 1.0.0 LANGUAGES CXX)

# Debug Version may contain runtime checks and experimental features/implementations
set(MM_IS_DEBUG true)

#configure_file(BuildConfig.h.in BuildConfig.h)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(compileTest compileTest.cpp
    API_
)


add_compile_definitions(M_IS_DEBUG=${MM_IS_DEBUG})
#add_compile_definitions(M_IS_DEBUG=${true})


target_include_directories(miniTest PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

