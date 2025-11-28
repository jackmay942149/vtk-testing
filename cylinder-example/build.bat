vcvarsall.bat x64 & cmake -S . -B build -G "Ninja" -DVTK_DIR=../vtk/build/lib/cmake/vtk-9.5 & cmake --build build --config Debug
