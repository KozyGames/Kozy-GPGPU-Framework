#ifndef GPGPU_MANAGER_HPP
#define GPGPU_MANAGER_HPP


#include "API_Handler.hpp"

namespace Kozy {


class GPGPU_Manager {


public:

    GPGPU_Manager(const GPU_API_ID& apiTag) :
        apiHandler() 
    {

    }

private:
    API_Handler apiHandler;

};


}



#endif