#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

class Window
{

      public:
             Window() ;
             virtual ~Window();
             
             void Create();
             void Destroy();
             void Swap();
             void SetKeyCallback(GLFWkeyfun func);
             
             void SetMouseBtnCallback(GLFWmousebuttonfun func);
            // void SetMouseMoveCallback(GLFWmouseposfun func);
             void Close();
             bool isOpen();
};
             




#endif /*WINDOW_H*/
