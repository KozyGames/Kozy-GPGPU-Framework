#include "Events_Manager.hpp"




#include "BuildConfig.hpp"
#include "OpenGL_Wrapper.hpp"

#include <utility>
#include <thread>
#include <chrono>
#include <vector>

namespace Kozy {


namespace Internal {
    GPU_API_Wrapper_Interface* gpuContext = nullptr;
}


void Events_Manager::init() {
    using enum GPU_API_T;

    
    switch(options.gpuAPI) {
        case AUTOMATIC:
            options.gpuAPI = check_best_GPU_API();  

        case OpenGL:
            Internal::gpuContext = static_cast<GPU_API_Wrapper_Interface*>(new OpenGL_Wrapper(3,3));
            break;

        default:
            ;
    }
    
}


void Events_Manager::start() {
    if (status.isRunning ){
        // Already running
    } else {
        if (Internal::gpuContext){
            Internal::gpuContext->run();
            terminate();

        } else { // API of gpu could not be initialized
            logs.msg_error += "Events_Manager::start\n""tried to start rendering, but there was a problem with initializing the rendering context";
        }
    }
}


void Events_Manager::pause() {
    status.isRequestPause = true;

}


void Events_Manager::unpause() {
    status.isRequestPause = false;
    
}


void Events_Manager::stop() {
    pause();

    status.isRequestStop = true;
    while (!status.isPaused){
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    unpause();
}


WindowInfo& Events_Manager::create_Window(const WindowInfo& winfo) {
    windows.push_back(new WindowInfo(Internal::gpuContext->create_Window(winfo)));
    windows.shrink_to_fit();
    return *windows.back();
}


void Events_Manager::update_Window(const WindowInfo& winfo) {
    
}


GPU_API_T Events_Manager::check_best_GPU_API() {

    return GPU_API_T::OpenGL;
}

void Events_Manager::terminate() {
    delete Internal::gpuContext;
    for(WindowInfo* e : windows){
        delete e;
    }

}



}