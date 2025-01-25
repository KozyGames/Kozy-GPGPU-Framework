#include "OpenGL_Wrapper.hpp"

#include "Events_Manager.hpp"

#include "glad/glad.h"
#include "glfw/glfw3.h"

#include <thread>
#include <chrono>


#include <iostream>
#include <string>

namespace Kozy {


    OpenGL_Wrapper::OpenGL_Wrapper(int major, int minor) : version_major(major),version_minor(minor) {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    }


    void OpenGL_Wrapper::run() {
        // preperations
        

        Events_Manager::status.isRunning = true;

        while (!Events_Manager::status.isRequestStop) {

        //    unsigned i = 0;

            while (!Events_Manager::status.isRequestPause) {    // render-loop
                std::this_thread::sleep_for(std::chrono::seconds(1));
       //         std::cout << std::string("Render: ") + std::to_string(++i) << std::endl; 
            }


            if (Events_Manager::status.isRequestPause) {
                Events_Manager::status.isPaused = true;

                while(Events_Manager::status.isRequestPause) { // pausing and clean-up
                    std::this_thread::sleep_for(std::chrono::microseconds(10));
                }

                Events_Manager::status.isPaused = false;

            } 
        }

        Events_Manager::status.isRunning = false;
    }


    WindowInfo OpenGL_Wrapper::create_Window(WindowInfo&& winfo) {
        
        return WindowInfo(std::move(winfo));
    }



    OpenGL_Wrapper::~OpenGL_Wrapper() {

    }
}




