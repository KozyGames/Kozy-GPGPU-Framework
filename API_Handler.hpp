#ifndef API_HANDLER_HPP
#define API_HANDLER_HPP

#include "GPU_API_ID.hpp"



namespace Kozy {

class API_Handler {



public:
    static API_Handler get_API_Handler(const GPU_API_ID& apiTag);

    virtual ~API_Handler() {
        
    }
    
protected:

    API_Handler() {

    }

private:




};


}


#endif