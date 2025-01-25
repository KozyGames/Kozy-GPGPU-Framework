#ifndef GPU_API_WRAPPER_INTERFACE_HPP
#define GPU_API_WRAPPER_INTERFACE_HPP

#include "WindowInfo.hpp"

namespace Kozy {


struct GPU_API_Wrapper_Interface {
    GPU_API_Wrapper_Interface() {

    }

    virtual void run() = 0;
    inline void render() {run();}

    WindowInfo create_Window(const WindowInfo& winfo) {
        WindowInfo temp(winfo);
        return create_Window(std::move(temp));
    }

    virtual WindowInfo create_Window(WindowInfo&&) = 0;

    virtual ~GPU_API_Wrapper_Interface() {

    }
        
};

}

#endif