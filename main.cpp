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

#include <SOIL/SOIL.h>

#include "geometry.h"
#include "scene.h"
#include "render.h"
#include "view.h"

Scene *myscene;

int init_resources();
void onDisplay();
void onIdle();
void onReshape(int width, int height);
void free_resources();

int WIDTH = 640;
int HEIGHT = 480;


int main(int argc, char* argv[]) {
  glutInit(&argc, argv);
  glutInitContextVersion(2,0);
  glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(WIDTH, HEIGHT);
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
    glutReshapeFunc(onReshape);
    glutIdleFunc(onIdle);
    glEnable(GL_BLEND);
    //glEnable(GL_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
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
    tri->add_texture("texture/text01.jpg");

    Cube *c = new Cube();
    c->make_mesh();

    Square *sq = new Square();
    sq->make_mesh();
    //sq->add_texture("texture/text01.jpg");

    Cylinder *cyl = new Cylinder();
    cyl->make_mesh(4.0, 1, 3, 50);

    Circle *cic = new Circle();
    cic->make_mesh(2, 40);

    View *camera = new View();
    glm::vec3 eye(0,1,-2);
    glm::vec3 target(0,0,0);
    //camera->Eye(eye);


    //Triangle *tri2 = new Triangle();
    //tri2->make_mesh(g_vertex_buffer_data2, g_color_buffer_data);
   // glm::vec3 xaxis(1.0, 0.0, 0.0);
    //tri->rotate(glm::rotate(glm::mat4(1.0), 45.0, xaxis));

    Scene *sc = new Scene();
    assert(sc->initShader("shader/triangle.v.glsl", "shader/triangle.f.glsl") == 1);
    sc->addChild(tri);

    myscene = sc;


    //GLint loc = glGetUniformLocation(myscene->Program(), "mvp");
    //assert(loc != -1);
     //glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(vvv));



}

void onDisplay()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  //glm::mat4 vvv = glm::lookAt(glm::vec3(0,0,2), glm::vec3(0,0,0), glm::vec3(0,1,0));

  //glm::mat4 mvp(1.0f);
  /*
  glm::mat4 mvp = glm::translate(glm::mat4(1.0f),glm::vec3(0,0,5));
  //glm::rotate(mvp, 45.0f, 0.0f,1.0f,0.0f);
  GLint loc = glGetUniformLocation(myscene->Program(), "mvp");
  if(loc != -1)
      glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));
      */

  glUseProgram(myscene->Program());
  GLint text1 = glGetUniformLocation(myscene->Program(), "texture0");
  glUniform1i(text1, 0);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, text1);
     
  Render *r = new Render(myscene); 
  r->drawScene();

  glutSwapBuffers();
}

void onIdle()
{
  float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 45;  // 45° per second
  glm::vec3 axis_y(0, 1, 0);
  glm::mat4 anim = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis_y);

  glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
  glm::mat4 view = glm::lookAt(glm::vec3(0.0, 6.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
  glm::mat4 projection = glm::perspective(45.0f, 1.0f*WIDTH/HEIGHT, 0.1f, 10.0f);

  glm::mat4 mvp = projection * view * model * anim;

  glUseProgram(myscene->Program());
  GLint loc = glGetUniformLocation(myscene->Program(), "mvp");
  //glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
  glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));
  /*
  float alpha = sinf(glutGet(GLUT_ELAPSED_TIME) / 1000.0 * (2*M_PI) / 5) + 0.5;
  float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 ;
  glm::vec3 yaxis(0,1,0);

  glm::mat4 v = glm::lookAt(glm::vec3(0,0,1), glm::vec3(0,0,0), glm::vec3(0,1,0));
  glm::mat4 mvp = glm::rotate(glm::mat4(1.0f), angle, yaxis);

  glUseProgram(myscene->Program());
  GLint loc = glGetUniformLocation(myscene->Program(), "alpha");
  if(loc != -1)
      //glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));
      glUniform1f(loc, 1.0);

  loc = glGetUniformLocation(myscene->Program(), "mvp");
  if(loc != -1)
      glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(v * mvp));
      //glUniform1f(loc, alpha);
      */


  glutPostRedisplay();
}

void onReshape(int width, int height)
{
    WIDTH = width;
    HEIGHT = height;
    glViewport(0,0,WIDTH, HEIGHT);
}

void free_resources()
{
  delete myscene;
}
