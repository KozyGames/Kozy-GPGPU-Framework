#ifndef WINDOWINFO_HPP
#define WINDOWINFO_HPP

/*

*/

#include <string>

#include "DataStructures/Image_PixelArray.hpp"

namespace Kozy {

struct WindowInfo {
friend struct GPU_API_Wrapper_Interface;

    WindowInfo(
        const char* arg_title,
        bool arg_fullscreen, 
        unsigned resolutionX, unsigned resolutionY
    ) :
        title(arg_title),
        fullscreen(arg_fullscreen),
        resX(resolutionX), resY(resolutionY)


     
    {

    }

    WindowInfo() :
        title("Untitled"),
        fullscreen(false),
        resX(800), resY(640)

    {

    }

    WindowInfo(const WindowInfo& cpy) :
        title(cpy.title),
        fullscreen(cpy.fullscreen),
        resX(cpy.resX), resY(cpy.resY)

    {

    }

    WindowInfo(WindowInfo&& mv) :
        title(std::move(mv.title)),
        fullscreen(mv.fullscreen),
        resX(mv.resX), resY(mv.resY)
    {

    }

    WindowInfo& operator=(const WindowInfo& cpy) {
        title = cpy.title;
        fullscreen = cpy.fullscreen;
        resX = cpy.resX, resY = cpy.resX;

        return *this;
    }

    WindowInfo& operator=(WindowInfo&& mv) {
        title = std::move(mv.title);
        fullscreen = mv.fullscreen;
        resX = mv.resX, resY = mv.resX;

        return *this;
    }


    ~WindowInfo() {
        delete icon;
    }


    bool fullscreen;
    std::string title;
    unsigned resX, resY;

    struct Status {
        bool isLoaded = false; 
    };

    const Status& get_Status() const {
        return status;
    }
    
    /*
        Icon width and height must be the same.
        Recommended dimensions are 16x16, 32x32 and 48x48

        If setting an icon fails, the icon stays unchanged.
    */
    inline void set_windowIcon(KozyLibrary::Image_RGBA&& img) {
        hidden_set_windowIcon(new KozyLibrary::Image_RGBA(std::move(img)));
    }

    inline void set_windowIcon(const KozyLibrary::Image_RGBA& img) {
        hidden_set_windowIcon(new KozyLibrary::Image_RGBA(img));
    }

    inline void clear_windowIcon() {
        hidden_set_windowIcon(nullptr);
    }

    

private:

    void hidden_set_windowIcon(KozyLibrary::Image_RGBA* img) {
        if (img == nullptr || img.height == img.width){
            delete icon;
            icon = img;
        } else {
            //TODO: proper logging
            throw "Icon Error: Width and height must be the same!" // temp log
        }
         
    }
    //TODO: ensure safe switching of icon at runtime

    Status status{};

    KozyLibrary::Image_RGBA* icon; 





};

}

#endif