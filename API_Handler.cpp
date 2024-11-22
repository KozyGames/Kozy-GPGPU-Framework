#include "API_Handler.hpp"
#include "API_Handler_OpenGL.hpp"


#include <stdexcept>

namespace Kozy {
    
API_Handler API_Handler::get_API_Handler(const Kozy::GPU_API_ID& apiTag) {
    using enum Kozy::Implemented_API;

    switch (apiTag.api_ID) {
        case OpenGL:
            return Kozy::load_API_Handler_OpenGL(apiTag);
        default:
            throw std::invalid_argument(
                "Error: get_API_Handler\n"
                "The given apiTag " + apiTag.str() + " can not be used to create an API_Handler.\n"
            );
    }
}

}