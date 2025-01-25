#ifndef OPENGL_WRAPPER_HPP
#define OPENGL_WRAPPER_HPP

#include "GPU_API_Wrapper_Interface.hpp"

#include <unordered_map>

struct GLFWwindow;

namespace Kozy {


class OpenGL_Wrapper : public GPU_API_Wrapper_Interface {
public:


    OpenGL_Wrapper(int major, int minor);

    OpenGL_Wrapper(): OpenGL_Wrapper(3,3) {}


    void run() override;

    WindowInfo create_Window(WindowInfo&& winfo) override;


    
    


    ~OpenGL_Wrapper();

private:
    int version_major, version_minor;

    

};

}



#endif