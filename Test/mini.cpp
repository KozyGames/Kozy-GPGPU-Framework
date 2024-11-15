#include <iostream>

#include "../GPU_API_ID.hpp"

using namespace std;



template<const Kozy::GPU_API_ID& api> 
void foo(){
    cout << "Hello" << endl;
}

int main(int argLen, const char** args) {
    //static constexpr Kozy::GPU_API_ID tag(Kozy::Implemented_API::OpenGL, 3, 3);
    static constexpr Kozy::GPU_API_ID tag;
    //static constexpr auto sss = "ABC";
    //static constexpr Kozy::GPU_API_ID tag(sss, 200, 3, 3);

    constexpr auto sv = Kozy::m_to_string<tag>();
    //foo<tag>();
    cout    << tag.str() << endl
            << sv << endl;

    return 0;
}