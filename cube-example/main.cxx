#include <cassert>

#include <vtkNew.h>
#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkCubeSource.h>
#include <vtkNamedColors.h>
#include <vtkRenderWindow.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindowInteractor.h>

int
main(int, char*[]) {
  // Create colours
  vtkNew<vtkNamedColors> colours;
  colours->SetColor("background_colour", 1.0, 0.0, 0.0);
  colours->SetColor("cube_colour", 0.0, 1.0, 0.0);

  // Create the cube
  vtkNew<vtkCubeSource> cube;
  vtkNew<vtkPolyDataMapper> mapper;
  mapper->SetInputConnection(cube->GetOutputPort());

  vtkNew<vtkActor> cube_actor;
  cube_actor->SetMapper(mapper);
  cube_actor->GetProperty()->SetColor(colours->GetColor4d("cube_colour").GetData());


  // Create a renderer
  vtkNew<vtkRenderer> renderer;
  if (colours->ColorExists("background_colour")) {
    renderer->SetBackground(colours->GetColor3d("background_colour").GetData());
  } else {
    assert(false);
  }

  // Add cube to scene
  renderer->AddActor(cube_actor);

  // Create a window
  vtkNew<vtkRenderWindow> render_window;
  render_window->SetSize(1000, 1000);
  render_window->AddRenderer(renderer);
  render_window->SetWindowName("Cube Example");
  render_window->Render();

  // Create inreactor for keeping the window open
  vtkNew<vtkRenderWindowInteractor> render_window_interactor;
  render_window_interactor->SetRenderWindow(render_window);

  // Start the event loop
  while (true) {
    render_window->Render();
    renderer->GetActiveCamera()->Azimuth(1);
    render_window_interactor->ProcessEvents();
  }
  return  EXIT_SUCCESS;
}
