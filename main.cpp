#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* Use glew.h instead of gl.h to get all the GL prototypes declared */
#include <GL/glew.h>
/* Using the GLUT library for the base windowing setup */
#include <GL/freeglut.h>
#include "common/shader_utils.h"

#include "geometry.h"
#include "scene.h"
#include "render.h"

Scene *myscene;

int init_resources();
void onDisplay();
void onIdle();
void free_resources();


int main(int argc, char* argv[]) {

  glutInit(&argc, argv);
  glutInitContextVersion(2,0);
  glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("game engine");

  GLenum glew_status = glewInit();
  if (glew_status != GLEW_OK) {
    fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_status));
    return 1;
  }

  if (!GLEW_VERSION_2_0) {
    fprintf(stderr, "Error: your graphic card does not support OpenGL 2.0\n");
    return 1;
  }

  if (init_resources()) {
    glutDisplayFunc(onDisplay);
    glutIdleFunc(onIdle);
    glEnable(GL_BLEND);
    //glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
  }

  free_resources();
  return 0;
}

int init_resources()
{
    Triangle *tri = new Triangle();
    tri->make_mesh();

    Scene *sc = new Scene();
    assert(sc->initShader() == 1);
    sc->addChild(tri);

    myscene = sc;
}

void onDisplay()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  Render *r = new Render(myscene); 
  r->drawScene();

  glutSwapBuffers();
}

void onIdle()
{
  glutPostRedisplay();
}

void free_resources()
{
  delete myscene;
}
