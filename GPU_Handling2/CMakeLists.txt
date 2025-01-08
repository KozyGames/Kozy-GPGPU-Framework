
add_library(GPU_API_HANDLING2 STATIC
    "OpenGL_Functions.cpp"
    "GPU_API_Wrapper.cpp"
    "GPU_Manager.cpp"
)


target_include_directories(GPU_API_HANDLING2 PRIVATE
    "${PROJECT_SOURCE_DIR}/../Kozy_CPP_Library"
)