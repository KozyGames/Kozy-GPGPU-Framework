#include "API_Handler_OpenGL.hpp"

#include <stdexcept>
 #include <string>

using namespace std;

namespace Kozy {


API_Handler load_API_Handler_OpenGL(const Kozy::GPU_API_ID& apiTag) {
    using Kozy::Implemented_API::OpenGL;

    switch(apiTag.major){
        case 1:
            throw invalid_argument("OpenGL 1.x is not supported");
            break;

        case 2:
            throw invalid_argument("OpenGL 2.x is not supported");
            break;

        case 3:
            switch(apiTag.minor){
                case 0:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 3, 0)>{};
                case 1:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 3, 1)>{};
                case 2:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 3, 2)>{};
                case 3:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 3, 3)>{};
                default:
                    throw invalid_argument("There is no OpenGL 3." + to_string(static_cast<unsigned>(apiTag.minor)));
            }

        case 4:
            switch(apiTag.minor){
                case 0:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 0)>{};
                case 1:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 1)>{};
                case 2:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 2)>{};
                case 3:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 3)>{};
                case 4:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 4)>{};
                case 5:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 5)>{};
                case 6:
                    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 4, 6)>{};
                default:
                    throw invalid_argument("There is no or at least not expected OpenGL 4." + to_string(static_cast<unsigned>(apiTag.minor)));
            }

        default:
            throw invalid_argument("At this time there is no OpenGL 5 or higher and it is unlikely to ever exist!");
        
    }
    
    return API_Handler_OpenGL<Kozy::GPU_API_ID(OpenGL, 3, 3)>{};
}
// TODO checks for whether the requested OpenGL version is fully usable. 
// TODO handle OpenGL extensions

}
