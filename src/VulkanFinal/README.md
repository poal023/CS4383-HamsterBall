# CS4383-HamsterBall
Hamster Ball Project for CS4383

Credits to [vulkan-tutorial.com](vulkan-tutorial.com) for template code.

This is the directory for the Vulkan Final Project.

## Directions

Below are setup instructions for Windows. You can enable your choice of model ('cage' or 'ball') through either adding or deleting `#define BALL` on top of main.cpp

You may also choose to modify the shaders so that there is no transparency, or decrease the opaqueness. Please see the fragment shader file in the `Shaders/` directory.

### Windows

On W10, assuming you are using VS community, make sure you create a `Windows Desktop Wizard` Project, and that `Console Application` is selected as type. Make sure once you make your new project, you configure your libraries by adding additional include directories for dependencies (GLM, GLFW, stb_img and tinyobjloader) and add as necessary.

Next, also make sure you add appropriate library directories and include vulkan-1.lib and glfw3.lib as additiona libraries.

Finally, make sure that the C++ language standard is set to C++17.

Then you can compile and run!
