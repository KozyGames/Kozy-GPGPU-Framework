#include <iostream>

#include "../GPU_API_ID.hpp"

using namespace std;




int main(int argLen, const char** args) {
    //static constexpr Kozy::GPU_API_ID tag(Kozy::Implemented_API::OpenGL, 3, 3);
    static constexpr Kozy::GPU_API_ID tag;
    //static constexpr auto sss = "ABC";
    //static constexpr Kozy::GPU_API_ID tag(sss, 200, 3, 3);

    constexpr auto sv = Kozy::api_toString<tag>();
    
    cout    << tag.str() << endl
            << sv << endl;

    return 0;
}