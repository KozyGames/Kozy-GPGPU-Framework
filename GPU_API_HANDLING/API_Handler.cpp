#include "API_Handler.hpp"
#include "API_Handler_OpenGL.hpp"


#include <stdexcept>
#include <string>



namespace Kozy {
    
API_Handler API_Handler::get_API_Handler(const GPU_API_ID& apiTag) {
    using enum Kozy::Implemented_API;


    switch (Kozy::Implemented_API(apiTag.api_ID)) {
        case OpenGL:
            try{
                return Kozy::load_API_Handler_OpenGL(apiTag);
            }
        default:
            throw std::invalid_argument(
                "Error: get_API_Handler\n"
                "The given apiTag " + apiTag.str() + " can not be used to create an API_Handler.\n"
            );
        
    }

}

}