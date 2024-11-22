#include "API_Handler_OpenGL.hpp"




namespace Kozy {

// here 
API_Handler load_API_Handler_OpenGL(const Kozy::GPU_API_ID& apiTag) {
    inline static constexpr Implemented_API OPENGL_ID = Implemented_API::OpenGL;
    return API_Handler_OpenGL<Kozy::GPU_API_ID(OPENGL_ID, 3, 3)>{};
}


}