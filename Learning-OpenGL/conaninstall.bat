@echo off 

mkdir debug32 && cd debug32
echo conan install debug - Start
conan install .. -s arch=x86 -s build_type=Debug
echo conan install debug - Finish
cd ../
mkdir release32 && cd release32
echo conan install release - Start
conan install .. -s arch=x86 -s build_type=Release
echo conan install release - Finish
cd ../
echo Success