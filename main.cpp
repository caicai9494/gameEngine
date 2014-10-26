
#include "mainWindow.h"

MainWindow *myWindow;

void draw();
void idle();

void draw()
{
	myWindow->Display();	
}

void idle()
{
	myWindow->onIdle();
}
int main(int argc, char* argv[]) {

  myWindow = new MainWindow(600, 500, "test", argc, argv);

  GLenum glew_status = glewInit();
  if (glew_status != GLEW_OK) {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
    return 1;
  }

  if (!GLEW_VERSION_2_0) {
    fprintf(stderr, "Error: your graphic card does not support OpenGL 2.0\n");
    return 1;
  }

  if (myWindow->init_resources()) {
    glutDisplayFunc(draw);
    glutIdleFunc(idle);
    glEnable(GL_BLEND);
    //glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
  }

  myWindow->free_resources();
  return 0;
}
