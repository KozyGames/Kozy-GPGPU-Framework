
add_library(EVENTS_MODULE STATIC
    "OpenGL_Functions.cpp"
    "Events_Manager.cpp"
)



target_include_directories(EVENTS_MODULE PRIVATE
    "${PROJECT_SOURCE_DIR}/external"

    "${PROJECT_BINARY_DIR}"

)