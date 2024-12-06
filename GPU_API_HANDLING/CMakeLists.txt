
add_library(GPU_API_HANDLING STATIC
    API_Handler.cpp
    API_Handler_OpenGL.cpp
    GPGPU_Manager.cpp
)


target_include_directories(GPU_API_HANDLING PRIVATE
    "${PROJECT_SOURCE_DIR}/../Kozy_CPP_Library"
)