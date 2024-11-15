#include <iostream>
//#include "KozyTools/Types.hpp"

#include "BuildConfig.h"

//#include "DataStructures/K_Tree.hpp"

//#include "K_Tree.hpp"
#include "../Kozy_CPP_Library/DataStructures/K_Tree.hpp"


using namespace std;




bool foo(const int& a, const int& b) {
    return a < b;
}
inline static constexpr decltype(&foo) fooArr2[] = {foo };




int main(int argLen, const char** args) {
	cout << "Hello" << endl;

//	cout << Kozy::Build_Config::DEFAULT_FRAMES_PER_SECOND << endl;
	

	//static int arr[] = {4, 5, 6, 3, 2, 4, 5};
    
    KozyLibrary::K_Tree<int, 1, fooArr2> tree1;

	//cout << "hello " << a <<  endl;
	
	//cin.get();

	cout << "bye" << endl;

	return 0;
}