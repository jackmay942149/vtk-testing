# Overview
This is a repo for my experimentation with VTK, I started alongside a job application for Stryker who use it as a core system. I will be looking at examples and might try some 2D, 3D, and VR visualisation if possible. I have included vtk as a submodule and it seems to have an OpenGL backend so vr should be possible.

# Getting started (Windows x64)
1) git clone [url] --recursive
2) ensure vcvarsall.exe is in PATH or use a VS terminal, I prefer powershell so it is set up for that
3) navigate to vtk folder and run build.bat
4) ensure cmake selects msvc for compiler (vtk requirement)
5) add vtk/build/bin to PATH
6) navigate to desired project folder ie. cylinder and run run.bat/build.bat
