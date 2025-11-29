#include <vtkNew.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>

int
main(int, char*[]) {
  // Create a window
  vtkNew<vtkRenderWindow> render_window;
  render_window->SetSize(1000, 1000);
  render_window->SetWindowName("Window Example");
  render_window->Render();

  // Create inreactor for keeping the window open
  vtkNew<vtkRenderWindowInteractor> render_window_interactor;
  render_window_interactor->SetRenderWindow(render_window);

  // Start the event loop
  render_window->Render();
  render_window_interactor->Start();
  return  EXIT_SUCCESS;
}
