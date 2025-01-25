#ifndef EVENTS_MANAGER_HPP
#define EVENTS_MANAGER_HPP


/*

*/

#include "WindowInfo.hpp"

#include "Kozy_CPP_Library/DataStructures/ThreadPool.hpp"

#include <atomic>
#include <string>
#include <vector>
#include <stdexcept>

namespace Kozy {

/*
	All numbers between 0 and 127 are reserved and must not be used for custom APIs / API-Wrappers.

    AUTOMATIC : checks for the most suitable API to be used with the users device  
*/
enum class GPU_API_T: unsigned char {
	AUTOMATIC	    = 0, 

	OpenGL			= 1, 
	OpenGL_ES		= 2, // NOT IMPLEMENTED
	Vulcan			= 3, // NOT IMPLEMENTED
	Metal			= 4, // NOT IMPLEMENTED
	CUDA			= 5, // NOT IMPLEMENTED
	OpenCL			= 6, // NOT IMPLEMENTED


	FIRST			= OpenGL,
	LAST			= OpenCL
};


/*

*/
class Events_Manager {
public:
    Events_Manager() = delete;


/*
    Defined Behavior only if invoked by the main thread!

    initializes the environment using the information from 'options'.
    Any changes after init() are ignored except for those stated otherwise.
    


*/
    static void init();

/*
    Defined Behavior only if invoked by the main thread! 
    Takes over the executing thread.

*/
    static void start();

/*

*/
    static void pause();

    static void unpause();

/*
    Any calls related to the gpu are undefined behavior after calling stop()
*/
    static void stop();
 
/*

*/
    inline static struct Options {
        Options() {}

        GPU_API_T gpuAPI = GPU_API_T::AUTOMATIC;

        
    } options{};

/*

*/
    inline static struct Status {
        Status() {}

        std::atomic<bool> isRunning         = false;
        std::atomic<bool> isPaused          = false; 

        std::atomic<bool> isRequestStop     = false;
        std::atomic<bool> isRequestPause    = false;


    } status{};


    inline static struct Logs {
        Logs() {}

        std::string msg_error           = "";
        std::string msg_info            = "";


    } logs{};

/*
    Only to be accessed when running, a.i. after 'start()' has been called 
*/
    inline static KozyLibrary::ThreadPool threadpool{};
    
/*

*/
    static const std::vector<WindowInfo*>& get_Windows() {
        return windows;
    }

/*

*/
    static WindowInfo& create_Window(const WindowInfo&);
    
/*
    winfo : must be a window
*/
    static void update_Window(const WindowInfo& winfo);
   

private:

    static void terminate();

/*

*/
    static GPU_API_T check_best_GPU_API();

/*

*/
    inline static std::vector<WindowInfo*> windows{};

    
};



}


#endif