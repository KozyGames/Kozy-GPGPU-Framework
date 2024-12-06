#ifndef API_HANDLER_OPENGL_HPP
#define API_HANDLER_OPENGL_HPP

#include "API_Handler.hpp"

namespace Kozy {
    
Kozy::API_Handler load_API_Handler_OpenGL(const Kozy::GPU_API_ID&);

template<Kozy::GPU_API_ID apiTag>
class API_Handler_OpenGL : public API_Handler {

friend Kozy::API_Handler Kozy::API_Handler::get_API_Handler(const Kozy::GPU_API_ID&);
friend Kozy::API_Handler Kozy::load_API_Handler_OpenGL(const Kozy::GPU_API_ID&);

public:
    //inline static constexpr Kozy::GPU_API_ID& apiVariant = apiTag;

    ~API_Handler_OpenGL() final {

    }


private:

    API_Handler_OpenGL() {

    }

};


}

#endif