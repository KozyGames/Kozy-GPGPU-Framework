#ifndef EVENTS_MANAGER_HPP
#define EVENTS_MANAGER_HPP

#include "Kozy_CPP_Library/DataStructures/ThreadPool.hpp"

#include <utility>

/*

*/

namespace Kozy {


/*

*/
class Events_Manager {
public:
    Events_Manager() = delete;


/*
    initializes the environment using the information from 'options'.
    Any changes after init() are ignored except otherwise stated.
*/
    static void init();

/*
    Defined Behavior only if invoked by the main thread! 
*/
    static void start();

/*

*/
    static void pause();

/*

*/
    static void stop();
 
/*

*/
    static struct Options {


        
    } options;


 //   static KozyLibrary::ThreadPool threadpool;

private:

   

};
//TODO: handling of logs: 
//+ error and technical


}


#endif