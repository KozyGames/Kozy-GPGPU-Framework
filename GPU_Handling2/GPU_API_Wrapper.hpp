#ifndef GPU_API_WRAPPER_HPP
#define GPU_API_WRAPPER_HPP


namespace Kozy {

/*
	All numbers between 0 and 127 are reserved and must not be used for custom APIs / API-Wrappers.
*/
enum class GPU_API_T: unsigned char {
	M_RESERVED_0	= 0, // RESERVED
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
	true 	: if implemented
	false 	: not implemented and/or unknown
*/
constexpr bool is_implemented(GPU_API_T name) noexcept {
	using enum GPU_API_T;

	switch(name){
		case OpenGL:
			return true;
		case OpenGL_ES:
			return false;
		case Vulcan:
			return false;
		case Metal:
			return false;
		case CUDA:
			return false;
		case OpenCL:
			return false;
		default:
			return false;
	}
}

//struct required_API_Calls
struct GPU_API_Wrapper {
    using voidF = void (*)();

    /*
        checks for the most efficient Variant
    */
    GPU_API_Wrapper();

    /*
        checks for the most efficient Variant of the preferred GPU-API
    */
    GPU_API_Wrapper(GPU_API_T apiT);

    /*
        assumes all given functions are valid and coherent
    */
    GPU_API_Wrapper(voidF arg_unload_GPU) :
        unload_GPU(arg_unload_GPU)
    {

    }

    template<typename GPU_API_Wrapper_T>
    GPU_API_Wrapper(const GPU_API_Wrapper_T& customWrapper) : 
        GPU_API_Wrapper(customWrapper.unload_GPU)
    {

    }

    ~GPU_API_Wrapper() {
        unload_GPU();
    }

    inline void exec_unload_GPU() {
        unload_GPU();
    }

private:
    voidF unload_GPU;

};



}

#endif