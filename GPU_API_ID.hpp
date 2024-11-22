#ifndef GPU_API_ID_HPP
#define GPU_API_ID_HPP


/*
This contains: 
- enum class "Implemented_API", which represents an id for GPU/GPGPU API's that are targeted by the Framework.
== although many APIs are available, only OpenGL has been implemented so far. 
- struct "GPU_API_ID", which represents 
*/
#include <cstdint>
#include <string_view>
#include <type_traits>

#include "../Kozy_CPP_Library/DataStructures/CompileTime_String.hpp"




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
using API_ID_T = std::underlying_type_t<Implemented_API>;

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

/*

*/
constexpr std::string_view api_enum_toString(Implemented_API name) noexcept {
	using enum Implemented_API;

	switch(name){
		case OpenGL:
			return "OpenGL";
		case OpenGL_ES:
			return "OpenGL_ES";
		case Vulcan:
			return "Vulcan";
		case Metal:
			return "Metal";
		case CUDA:
			return "CUDA";
		case OpenCL:
			return "OpenCL";
		default:
			return "UNKNOWN API";
	}
}
inline constexpr std::string_view api_enum_toString(API_ID_T id) noexcept {return api_enum_toString(Implemented_API(id));}
	
/*
    Use this as a key to differentiate between various APIs and their respective variants.

	It is recommended to dynamically determinate what kind of API you want to use and then create an object, that has its respective GPU_API_ID as a compile-time object, so that
	one can check inside of its methods what api-calls and features to use. For example, using if constexpr(apiID.major == 4){ do Stuff}.
*/
struct GPU_API_ID {

	/*
		use this constructor for custom API's
	*/
	constexpr GPU_API_ID(const std::string_view& name, API_ID_T apiID, uint16_t majorVersion, uint16_t minorVersion):
		API_Name(name.data()), 
        api_ID(apiID), 
		major(majorVersion), 
		minor(minorVersion)
    {
	
	}

	/*
		use this constructor if you want to use an implemented API 
	*/
	constexpr GPU_API_ID(Implemented_API api, uint16_t majorVersion, uint16_t minorVersion) noexcept :
		GPU_API_ID( 
			api_enum_toString(api), 
			static_cast<API_ID_T>(api), 
			majorVersion, 
			minorVersion
		)
    {
	
	}

	constexpr GPU_API_ID(const GPU_API_ID& cpy) noexcept : 
		GPU_API_ID(
			cpy.API_Name,
			cpy.api_ID,
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

		const string out = string(API_Name) + ' ' + std::to_string(major) + '.' + std::to_string(minor);
		return out;
	}


    const char* API_Name;
    API_ID_T api_ID;				
    uint16_t major, minor;
};


template<const GPU_API_ID& v>
consteval auto api_toString() {
	using namespace KozyLibrary;
	
	return concat_CT<std::string_view(v.API_Name),
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