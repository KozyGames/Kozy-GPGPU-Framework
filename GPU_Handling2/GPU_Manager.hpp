#ifndef GPU_MANAGER_HPP
#define GPU_MANAGER_HPP


#include "GPU_API_Wrapper.hpp"

#include <utility>

namespace Kozy {

/*

*/
struct GPU_Manager {

    template<typename GPU_API_Wrapper_T>
    GPU_Manager(GPU_API_Wrapper_T&& gpu_API) : 
        gpuCaller(std::forward<GPU_API_Wrapper_T>(gpu_API)) 
    {

    }

    ~GPU_Manager();

private:

    GPU_API_Wrapper gpuCaller;


};

}

#endif