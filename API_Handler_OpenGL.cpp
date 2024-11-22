#include "API_Handler_OpenGL.hpp"


#include <stdexcept>
#include <string>

#define TEMPI_TEMP return Kozy::API_Handler_OpenGL<Kozy::GPU_API_ID(Kozy::Implemented_API::OpenGL, 3, 0)>{};

namespace Kozy {

namespace { // hidden
    API_Handler load_OpenGL_3_0_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID(Kozy::Implemented_API::OpenGL, 3, 0)>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_3_1_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 3, 1>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_3_2_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 3, 2>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_3_3_Extensions(const Kozy::GPU_API_ID& apiTag) {
        // TODO at runtime, check for OpenGL extensions and maybe test what the optimal solution for the users computer is.
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 3, 3>>;
        TEMPI_TEMP
    }

    API_Handler load_OpenGL_3(const Kozy::GPU_API_ID& apiTag) {
        switch(apiTag.minor){
            case 0:
                return (load_OpenGL_3_0_Extensions(apiTag));
            case 1:
                return (load_OpenGL_3_1_Extensions(apiTag));
            case 2:
                return (load_OpenGL_3_2_Extensions(apiTag));
            case 3:
                return (load_OpenGL_3_3_Extensions(apiTag));
            default:
                throw std::invalid_argument("There is no OpenGL 3." + std::to_string(apiTag.minor) + std::string("!"));
        }
    }

    API_Handler load_OpenGL_4_0_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 0>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_1_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 1>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_2_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 2>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_3_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 3>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_4_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 4>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_5_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 5>>;
        TEMPI_TEMP
    }
    API_Handler load_OpenGL_4_6_Extensions(const Kozy::GPU_API_ID& apiTag) {
        //return API_Handler_OpenGL<Kozy::GPU_API_ID<Implemented_API::OpenGL, 4, 6>>;
        TEMPI_TEMP
    }

    API_Handler load_OpenGL_4(const Kozy::GPU_API_ID& apiTag) {
        switch(apiTag.minor){
            case 0:
                return (load_OpenGL_4_0_Extensions(apiTag));
            case 1:
                return (load_OpenGL_4_1_Extensions(apiTag));
            case 2:
                return (load_OpenGL_4_2_Extensions(apiTag));
            case 3:
                return (load_OpenGL_4_3_Extensions(apiTag));
            case 4:
                return (load_OpenGL_4_4_Extensions(apiTag));
            case 5:
                return (load_OpenGL_4_5_Extensions(apiTag));
            case 6:
                return (load_OpenGL_4_6_Extensions(apiTag));
            default:
                throw std::invalid_argument("There is no OpenGL 4." + std::to_string(apiTag.minor) + std::string("!"));
        }
    }
}


API_Handler load_API_Handler_OpenGL(const Kozy::GPU_API_ID& apiTag) {

    switch(apiTag.major){
        case 1:
            throw std::invalid_argument("OpenGL 1 is not being supported.");
        case 2:
            throw std::invalid_argument("OpenGL 2 is not being supported.");
        case 3:
            return load_OpenGL_3(apiTag);

        case 4:
            return load_OpenGL_4(apiTag);
        
        default:
            throw std::invalid_argument("There is no OpenGL " + std::to_string(apiTag.major) + std::string(".x!"));

    }
}


}