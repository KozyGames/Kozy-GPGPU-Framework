#include <iostream>
#include <string>
#include <string_view>


//#include "../GPU_API_ID.hpp"
#include "../API_Handler.hpp"

using namespace std;




int main(int argLen, const char** args) {
    static constexpr Kozy::GPU_API_ID tag;

    Kozy::API_Handler::create_API_Handler(tag);
    

    return 0;
}