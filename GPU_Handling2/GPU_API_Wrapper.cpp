#include "GPU_API_Wrapper.hpp"

#include <stdexcept>

namespace Kozy {

    GPU_API_Wrapper::GPU_API_Wrapper() {
        using enum GPU_API_T;
        GPU_API_T mostPerformant = OpenGL;

        (*this) = GPU_API_Wrapper(mostPerformant);
    }
//TODO 1
    
    GPU_API_Wrapper::GPU_API_Wrapper(GPU_API_T apiT) {
        using enum GPU_API_T;

        if (is_implemented(apiT)){
            switch(apiT) {
                case OpenGL:
                unload_GPU = nullptr;
                    break;
                default:
                    throw std::runtime_error("Shouldn't be here!");
            }
        } else {
            throw std::invalid_argument("The requested GPU-API is not yet implemented!");
        }

    }

}