cmake_minimum_required(VERSION 3.21)

project(miniTest VERSION 1.0.0 LANGUAGES CXX)

# Debug Version may contain runtime checks and experimental features/implementations
 set(MM_IS_DEBUG true)

configure_file(BuildConfig.h.in BuildConfig.h)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(GPU_API_HANDLING)

#add_subdirectory(Kozy_GPGPU)

add_executable(miniTest 
#main.cpp
Test/compileTest.cpp

)
target_link_libraries(miniTest
    GPU_API_HANDLING
)


add_compile_definitions(M_IS_DEBUG=${MM_IS_DEBUG})
#add_compile_definitions(M_IS_DEBUG=${true})



target_include_directories(miniTest PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/../Kozy_CPP_Library"
    "${PROJECT_SOURCE_DIR}/GPU_API_HANDLING"

)

