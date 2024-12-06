#ifndef GPU_API_ID_HPP
#define GPU_API_ID_HPP


/*
This contains: 
- enum class "Implemented_API", which represents an id for GPU/GPGPU API's that are targeted by the Framework.
== although many APIs are available, only OpenGL has been implemented so far.

- struct "GPU_API_ID", which represents an in-depth representation of a GPU-API and its active features and settings.
*/


#include <cstdint>
#include <string_view>
#include <type_traits>

#include "DataStructures/CompileTime_String.hpp"


namespace Kozy {

/*
	All numbers between 0 and 127 are reserved and must not be used for custom APIs / API-Wrappers.
*/
enum class Implemented_API: uint_fast8_t {
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
constexpr bool is_implemented(Implemented_API name) noexcept {
	using enum Implemented_API;

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

namespace Details{
	inline static constexpr const char* const GPU_API_OpenGL_Str = "OpenGL";
	inline static constexpr const char* const GPU_API_OpenGL_ES_Str = "OpenGL_ES";
	inline static constexpr const char* const GPU_API_Vulcan_Str = "Vulcan";
	inline static constexpr const char* const GPU_API_Metal_Str = "Metal";
	inline static constexpr const char* const GPU_API_CUDA_Str = "CUDA";
	inline static constexpr const char* const GPU_API_OpenCL_Str = "OpenCL";
	inline static constexpr const char* const GPU_API_Unkown_Str = "UNKNOWN API";
}

/*

*/
constexpr const char* api_enum_toString(Implemented_API name) noexcept {
	using enum Implemented_API;
	using namespace Details;

	switch(name){
		case OpenGL:
			return GPU_API_OpenGL_Str;
		case OpenGL_ES:
			return GPU_API_OpenGL_ES_Str;
		case Vulcan:
			return GPU_API_Vulcan_Str;
		case Metal:
			return GPU_API_Metal_Str;
		case CUDA:
			return GPU_API_CUDA_Str;
		case OpenCL:
			return GPU_API_OpenCL_Str;
		default:
			return GPU_API_Unkown_Str;
	}

}

/*
    Use this as a key to differentiate between various APIs and their respective variants.

	It is recommended to dynamically determinate what kind of API you want to use and then create an object, that has its respective GPU_API_ID as a compile-time object, so that
	one can check inside of its methods what api-calls and features to use. For example, using if constexpr(apiID.major == 4){ do Stuff}.
*/
struct GPU_API_ID {

	/*
		use this constructor for custom API's.

		Make sure that your apiID does not already exist nor is reserved. See Implemented_API.
	*/
	constexpr GPU_API_ID(const char* const* name, std::underlying_type_t<Implemented_API> apiID, uint16_t majorVersion, uint16_t minorVersion):
		API_Name(name), 
        api_ID(static_cast<Implemented_API>(apiID)), 
		major(majorVersion), 
		minor(minorVersion)
    {
	
	}

	/*
		use this constructor if you want to use an implemented API 
	*/
	constexpr GPU_API_ID(Implemented_API api, uint16_t majorVersion, uint16_t minorVersion) noexcept 

    {
		api_ID = api;
		major = majorVersion;
		minor = minorVersion;

    	using enum Kozy::Implemented_API;
		using namespace Details;

		switch(api){
			case OpenGL:
				API_Name = &GPU_API_OpenGL_Str;
				break;
			case OpenGL_ES:
				API_Name = &GPU_API_OpenGL_ES_Str;
				break;
			case Vulcan:
			 	API_Name = &GPU_API_Vulcan_Str;
				break;
			case Metal:
			 	API_Name = &GPU_API_Metal_Str;
				break;
			case CUDA:
			 	API_Name = &GPU_API_CUDA_Str;
			 	break;
			case OpenCL:
				API_Name = &GPU_API_OpenCL_Str;
			 	break;
			default:
				API_Name = &GPU_API_Unkown_Str;
		}
	
	}

	constexpr GPU_API_ID(const GPU_API_ID& cpy) noexcept : 
		GPU_API_ID(
			cpy.API_Name,
			static_cast<std::underlying_type_t<Implemented_API>>(cpy.api_ID),
			cpy.major,
			cpy.minor	
		)
	{

	}


	/*
		Default
	*/
	constexpr GPU_API_ID() noexcept : 
		GPU_API_ID(Implemented_API::OpenGL, 3, 3)
	{

	}
	
	constexpr ~GPU_API_ID() noexcept {

	}

	/*

	*/
	constexpr bool operator==(const GPU_API_ID& rhs) const noexcept {
		return api_ID == rhs.api_ID && major == rhs.major && minor == rhs.minor;
	}
	inline constexpr bool operator!=(const GPU_API_ID& rhs) const noexcept {return !(*this == rhs);}

	GPU_API_ID& operator=(const GPU_API_ID& cpy) noexcept {
		API_Name = cpy.API_Name;
		api_ID = cpy.api_ID;
		major = cpy.major;
		minor = cpy.minor;

		return *this;
	}

	std::string str() const {
		using std::string;

		const string out = string(*API_Name) + ' ' + std::to_string(major) + '.' + std::to_string(minor);
		return out;
	}


    const char* const* API_Name;
    Implemented_API api_ID;				
    uint16_t major, minor;

	
};


template<const GPU_API_ID& v>
consteval auto api_toString() {
	using namespace KozyLibrary;
	
	return concat_CT<std::string_view(*v.API_Name),
		concat_CT<
			concat_CT<" ", KozyLibrary::number_toString<v.major>()>(),
	        concat_CT<".", KozyLibrary::number_toString<v.minor>()>()
	    >()
	>();
}


}

#endif

/* TODO:
- add handling of Extensions
*/