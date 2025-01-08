cmake_minimum_required(VERSION 3.21)

project(Kozy_GPGPU VERSION 1.0.0 LANGUAGES CXX)

include(ExternalProject)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Debug Version may contain runtime checks and experimental features/implementations
add_compile_definitions(M_IS_DEBUG=true)

# 
set(m_architecture "x64")
set(PATH_OPENGL_PARTIAL "C:\\Program Files (x86)\\Windows Kits\\10\\Lib\\10.0.26100.0\\um")

if(${m_architecture} STREQUAL "x64")
    set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}"\\x64")
elseif(${m_architecture} STREQUAL "x86")
    set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}"\\x86")
elseif(${m_architecture} STREQUAL "arm64")
    set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}"\\arm64")
else()
    message(STATUS "Bad")
endif()




configure_file(BuildConfig.hpp.in BuildConfig.hpp)

add_subdirectory(Events)

add_executable(Kozy_GPGPU
OpenGL32.Lib
external/glad/glad.c
test/Basic/compileTest.cpp
)

target_link_libraries(Kozy_GPGPU
    EVENTS_MODULE
)




#if(EXISTS "${PROJECT_BINARY_DIR}/external")
    
#else()
#    make_directory("external")
     
#endif()

#ExternalProject_Add(Kozy_CPP_Library
#    GIT_REPOSITORY    https://github.com/KozyGames/Kozy_CPP_Library.git
#    GIT_TAG           main
#    SOURCE_DIR        "${PROJECT_BINARY_DIR}/external"
#   )



target_include_directories(Kozy_GPGPU PUBLIC


    "${PROJECT_BINARY_DIR}"
    #"${PROJECT_BINARY_DIR}/external"

    "${PROJECT_SOURCE_DIR}/Events"

    # necessary resources:
    # Kozy_CPP_Library
    # GLFW: include folder and built library of GLFW
    # This is a temporary solution until I get how to do this properly in cmake
    "${PROJECT_SOURCE_DIR}/external"
    "${PATH_OPENGL_FULL}"


)
