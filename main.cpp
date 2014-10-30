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

const int WIDTH = 640;
const int HEIGHT = 480;


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

	GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
	};
	GLfloat g_vertex_buffer_data2[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		 -1.0f, 1.0f, 0.0f,
	};

	GLfloat g_color_buffer_data[] = {
		1.0f, 0.0f, 0.0f,
		 0.0f, 1.0f, 0.0f,
		 0.0f,  0.0f, 1.0f,
	};

    //Triangle *tri1 = new Triangle();
    //tri1->make_mesh();
    Square *sq = new Square();
    sq->make_mesh();

    //Triangle *tri2 = new Triangle();
    //tri2->make_mesh(g_vertex_buffer_data2, g_color_buffer_data);
   // glm::vec3 xaxis(1.0, 0.0, 0.0);
    //tri->rotate(glm::rotate(glm::mat4(1.0), 45.0, xaxis));

    Scene *sc = new Scene();
    assert(sc->initShader("shader/triangle.v.glsl", "shader/triangle.f.glsl") == 1);
    //sc->addChild(tri1);
    //sc->addChild(tri2);
    sc->addChild(sq);

    myscene = sc;

  //GLint loc = glGetUniformLocation(myscene->Program(), "mvp");
  //if(loc != -1)
   //   glUniformMatrix4fv(loc, 1, GL_FALSE, tri->get_matrix());
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
  float alpha = sinf(glutGet(GLUT_ELAPSED_TIME) / 1000.0 * (2*M_PI) / 5) + 0.5;

  GLint loc = glGetUniformLocation(myscene->Program(), "alpha");
  if(loc != -1)
      glUniform1f(loc, alpha);

  glutPostRedisplay();
}

void free_resources()
{
  delete myscene;
}
