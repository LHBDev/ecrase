#include <cstdlib>
#include <iostream>
#include <GLFW/glfw3.h>

int main(int argc, char *argv[])
{
    std::cout<<"Ecrase Creative R* Adventure Scripting Engine"<<std::endl;
    std::cout<<"----------Copyright (c) 2013 jmf-------------"<<std::endl;
    GLFWwindow* window;
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
