# Learning-OpenGL
Simple application to learn the basics of OpenGL.

# Requirements
## Windows
Visual Studio 2017 (v141)
Windows SDK 10.0.17134.0
Graphics card with support to OpenGL 3.3

## Others
I've not tested nor built this application in any other platform. You do need a compiler supporting C++17.

# Build instructions
## Windows
### Visual Studio
Open the dependencies solutions and build them (Release and RelWithDebInfo):
- GLEW 2.1.0
  - external\glew-2.1.0\build\vc15\glew.sln
- GLFW 3.2.1
  - external\glfw-3.2.1\build\vc15\GLFW.sln

## Others
It will probably work under other platforms. You will have to build it manually though.

# Dependencies
GLFW 3.2.1
GLEW 2.1.0
OpenGL 3.3