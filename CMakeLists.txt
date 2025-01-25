cmake_minimum_required(VERSION 3.21)

project(Kozy_GPGPU VERSION 1.0.0 LANGUAGES CXX)

include(ExternalProject)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



# necessary resources :
# a) Kozy_CPP_Library : 
#  1) clone https://github.com/KozyGames/Kozy_CPP_Library.git into 'external_path' seen below
#
# b) GLFW :
#   1) clone https://github.com/glfw/glfw.git
#   2) copy 'glfw3.h' and 'glfw3native.h' from glfw/include/GLFW and paste into a folder called 'glfw'. That folder needs to be in 'external_path' 
#   3) generate your glfw build folder through cmake. I personally used the cmake gui variant and set gcc/g++ via 'mingw64' as the compiler and 'ninja' as the make-program.
#   4) using your console go to the build folder and invoke your make-program('ninja' for me)
#   5) copy the library file from your build/src and put it into the folder 'external_path'. Name it 'libglfw3.a'  
#
# c) setting the path to the OpenGL-Library on your OS
#  Sidenote : you only need the path to it on your (compiling-)machine
#  On Windows : the OpenGL-Library is called OpenGL32.Lib no matter what architecture
#   1) change 'k_architecture' to the architecture you want your program to run on
#  On Linux :
#
# d) GLAD :
#   1) go to https://glad.dav1d.de/
#   2) you need to configure it to your liking. set API-gl to 'Version 4.6' and profile to 'Core'
#   3) download the archive and extract of the folder 'include' the folders 'KHR' and 'glad' and place them into 'external_path'
#   4) copy 'glad.c' from 'src' and put it into the just extracted folder 'glad'
#

# path to any additional external resources needed.
# this is temporary and will change as soon as I get a better grasp of CMake and become hopefully fully/mostly automated
set(external_path "${PROJECT_SOURCE_DIR}../external")


# if you do not use Windows or have a different path to your OS's OpenGL library, you need to set PATH_OPENGL_FULL to yours
set(PATH_OPENGL_FULL "auto")

# filename of your OS's OpenGL library.
# Windows standard filename for no matter what architecture is 'OpenGL32.Lib'
set(k_OpenGL_Library_Name "OpenGL32.Lib")

# k_architecture represents the devices architecture.
set(k_architecture "x64")

set(PATH_OPENGL_PARTIAL "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.22621.0/um")

if(${PATH_OPENGL_FULL} STREQUAL "auto")
    if(${k_architecture} STREQUAL "x64")
        set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}/x64)
    elseif(${k_architecture} STREQUAL "x86")
        set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}/x86)
    elseif(${k_architecture} STREQUAL "arm")
        set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}/arm)
    elseif(${k_architecture} STREQUAL "arm64")
        set(PATH_OPENGL_FULL ${PATH_OPENGL_PARTIAL}/arm64)
    else()
        message(FATAL_ERROR "ARCHITECTURE UNKNOWN.")
    endif()

else()
    message(FATAL_ERROR "PATH TO OPENGL LIBRARY NOT SET.")
endif()

# Debug Version may contain runtime checks and experimental features/implementations
add_compile_definitions(M_IS_DEBUG=true)


configure_file(BuildConfig.hpp.in BuildConfig.hpp)

add_subdirectory(Events)
add_subdirectory(external)

set_target_properties(EXTERNAL_LIBRARIES PROPERTIES LINKER_LANGUAGE CXX)

set(TEST_COMPILATION OFF)
set(TEST_TEMP ON)

if(TEST_COMPILATION)
    add_executable(Kozy_GPGPU
    #${PATH_OPENGL_FULL}/${k_OpenGL_Library_Name}

    test/Basic/compileTest.cpp
    )



    target_link_libraries(Kozy_GPGPU
        ${PATH_OPENGL_FULL}/${k_OpenGL_Library_Name}
        EXTERNAL_LIBRARIES
        EVENTS_MODULE

    )


    target_include_directories(Kozy_GPGPU PUBLIC

        "${PROJECT_BINARY_DIR}"
        #"${PROJECT_BINARY_DIR}/external"

        "${PROJECT_SOURCE_DIR}/Events"

    
        "${PROJECT_SOURCE_DIR}/external"
        "${PATH_OPENGL_FULL}"

    )

endif()


if(TEST_TEMP)
    add_executable(tempTest Test/Temp/tempTest.cpp)

    target_link_libraries(tempTest
    ${PATH_OPENGL_FULL}/${k_OpenGL_Library_Name}
    EXTERNAL_LIBRARIES
    EVENTS_MODULE

    )

    target_include_directories(tempTest PUBLIC

    "${PROJECT_BINARY_DIR}"
    #"${PROJECT_BINARY_DIR}/external"

    "${PROJECT_SOURCE_DIR}/Events"

    
    "${PROJECT_SOURCE_DIR}/external"
    "${PATH_OPENGL_FULL}"

    )

endif()


#if(EXISTS "${PROJECT_BINARY_DIR}/external")
    
#else()
#    make_directory("external")
     
#endif()

#ExternalProject_Add(Kozy_CPP_Library
#    GIT_REPOSITORY    https://github.com/KozyGames/Kozy_CPP_Library.git
#    GIT_TAG           main
#    SOURCE_DIR        "${PROJECT_BINARY_DIR}/external"
#   )

