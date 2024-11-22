#ifndef BUILD_CONFIG_HPP
#define BUILD_CONFIG_HPP

#include "../STD_Global.hpp"

/*

*/


namespace Kozy {

/*
Any build changes shall be done here


*/	
struct BuildConfig {
    BuildConfig() = delete;
	
    inline static constexpr unsigned VERSION_MAJOR = 1;
    inline static constexpr unsigned VERSION_MINOR = 0; 

// * General DEBUG Settings *


	inline static constexpr bool IS_DEBUG = M_IS_DEBUG;

	inline static constexpr bool DEFAULT_IS_FULLSCREEN =  (IS_DEBUG)? false : true;
	
	/* 
		0 is the ID of the native primary monitor.
		If the value is higher than there are monitors, then it reverts to the native monitor.

	*/
	inline static constexpr uint_fast8_t DEFAULT_ID_MONITOR = (IS_DEBUG)? 1 : 0;
	/*
		if the program is in an error state or stuck, 
		this repesents in seconds for how long the program waits and tries to recover
	*/  
	inline static constexpr uint_fast16_t TIMEOUT_LENGTH_SECONDS = (IS_DEBUG)? 30 : 60;


// * Hardware Info *

	/*
		32x Systems : false
		64x Systems : true, biggest primitive type holds at least 2^64 numbers
	*/
	inline static constexpr bool IS_AT_LEAST_64_BIT_WORD = ( sizeof(size_t)*8 >= 64 ); 	
	

// * Window Settings *
/*
	These are used for when the program is started for the first time or if reading/creating the Settings-file failed

*/

	/*
		reprents the target fps. Actual fps may vary.
		0 : as many fps as possible

	*/
	inline static constexpr uint_fast16_t DEFAULT_FRAMES_PER_SECOND = (IS_DEBUG)? 90 : 120;
	/*
			
	*/
	enum class WindowMode : uint_fast8_t {
		windowed =			0,
		fullscreen = 		1,
		windowedMax =		2
	};
	/*
		
	*/
	inline static constexpr WindowMode WINDOWMODE_V = (IS_DEBUG)? WindowMode::windowed : WindowMode::fullscreen;
	/*
		Whether the created windows try to force focus on them.
		Depending on the OS and its settings, for some devices forceful focus is disabled. 

	*/
	inline static constexpr bool IS_FORCE_FOCUS_ON_STARTUP = (IS_DEBUG)? false : true;

};

/* 
Soft limits of the framework.
It is highly discouraged to break these. 
Breaking these results in undefined behavior. 

Framework is only tested and guaranteed within these limits.

*/
struct Framework_Limits {
	Framework_Limits() = delete;

	inline static constexpr uint_fast8_t MAX_INSTANCES_OF_WINDOWS			= 1;
	inline static constexpr uint_fast8_t MAX_FRAMES_PER_SECOND				= uint_fast8_t(-1);


	inline static constexpr uint_fast8_t MIN_BIGGEST_WORD_SIZE_IN_BIT		= 32;		


};

	
}

#endif
