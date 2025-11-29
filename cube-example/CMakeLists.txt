cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

set(CMAKE_PREFIX_PATH "C:/dev/vtk-testing/vtk/build")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(cube-example)

find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "cube-example: Unable to find the VTK build folder.")
endif()

# Prevent a "command line is too long" failure in Windows.
set(CMAKE_NINJA_FORCE_RESPONSE_FILE "ON" CACHE BOOL "Force Ninja to use response files.")
add_executable(cube-example MACOSX_BUNDLE main.cxx )
  target_link_libraries(cube-example PRIVATE ${VTK_LIBRARIES}
)

# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS cube-example
  MODULES ${VTK_LIBRARIES}
)
