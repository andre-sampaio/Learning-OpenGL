# Learning-OpenGL
Simple application to learn the basics of OpenGL.

# Requirements
## Windows
- Visual Studio 2017 (v141)
- Windows SDK 10.0.16299.0
- Graphics card with support to OpenGL 3.3
- [Conan](https://conan.io/)

# Build instructions
## Windows
### Visual Studio
1- Add https://bintray.com/andresampaio/personaluse-repo as a conan remote repo, if not already added.
  - Run `conan remote add andresampaio/personaluse-repo https://bintray.com/andresampaio/personaluse-repo`

2- Run conaninstall.bat **inside Learning-OpenGL project directory** (i.e.: Learning-OpenGL/Learning-OpenGL/conaninstall.bat).
  - `conaninstall.bat`
  - This will simply run conan install for the Debug and Release configurations
 
3- Open the solution and build

# Dependencies
- GLFW 3.2.1
- GLEW 2.1.0
- OpenGL 3.3