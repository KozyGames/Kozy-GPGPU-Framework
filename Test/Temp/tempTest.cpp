#include "BuildConfig.hpp"
#include "Kozy_CPP_Library/Math/Basic_Math.hpp"

#include "Kozy_CPP_Library/KozyLibrary_Complete.hpp"

#include "Events_Manager.hpp"

#include <thread>
#include <chrono>
#include <iostream>

using std::cout; using std::endl;

void stop_foo() {

  for(unsigned i = 10; i != 0; --i){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << i << endl;
  }

  Kozy::Events_Manager::stop();
 
}


int main(int argLen, const char** args) {
  cout << "TEST: Creating a window" << endl;

  //KozyLibrary::Image_RGB bbb(nullptr, 0, 0);
   
  Kozy::Events_Manager::init();
  std::thread t(stop_foo);

  Kozy::Events_Manager::start();

  t.join();
  
  cout << "\nGoodbye\n";
  return 0;
}