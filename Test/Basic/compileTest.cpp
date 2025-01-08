#include <iostream>


using namespace std;

#include <GLFW/glfw3.h>

#include "BuildConfig.hpp"
#include "Kozy_CPP_Library/Math/Basic_Math.hpp"


int main(int argLen, const char** args) {
   
  cout << KozyLibrary::Math::power(2,4) << endl;

  return 0;
}