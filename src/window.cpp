#include "window.h"

int windowWidth = 800;
int windowHeight = 600;
bool windowFullScreen = false;
bool glfwInitiated = false;


Window::Window()
{
       if(!glfwInit())
       {
          //report not initiated
       }
       glfwInitiated = true;
}

Window::~Window()
{
                 //fail-safe in case not called
                 Destroy();
}

void Window::Create()
{
     
     if(!glfwCreateWindow(640, 480, "Ecrase", NULL, NULL))
     {
                                     glfwTerminate();
                                     
     }
    
}

void Window::SetKeyCallback(GLFWkeyfun func)
{
     glfwSetKeyCallback(func);
}

void Window::SetMouseMoveCallback(GLFWmousepsfun func)
{
     glfwSetMousePosCallback(func);
}

void Window::SetMouseBtnCallback(GLFWmousebuttonfun func)
{
     glfwSetMouseButtonCallback(func);
}

void Window::Destroy()
{
     if(glfwInitiated)
     {
                      glfwTerminate();
                      glfwInitiated = false;
     }
}

void Window::Swap()
{
     glfwSwapBuffers();
} 

void Window::Close()
{
     glfwCloseWindow();
}

bool Window::isOpen()
{
     return glfwGetWindowParam(GLFW_OPENED);
}               
