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
#include "texture.h"

SceneNode *myscene;
SceneNode *myscene2;
Render *myrender;
Render *myrender2;

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
    Texture *tex = new Texture("texture/textmarble.jpg");

    Texture *tex2 = new Texture("texture/blackwhite.jpeg");

    Texture *tex3 = new Texture("texture/text01.jpg");


    Shader *colorShader = new Shader();
    assert(colorShader->initShader("shader/color.v.glsl", "shader/color.f.glsl") == 1);


    Shader *textShader = new Shader();
    assert(textShader->initShader("shader/texture.v.glsl", "shader/texture.f.glsl") == 1);

    Square *sq = new Square();
    sq->make_mesh();
    //SceneNode *root = new SceneNode(sq, textShader, tex2);
    glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(5.0, 5.0, 5.0));
    SceneNode *root = new SceneNode(sq, textShader, tex3);
    root->scale(model);


    Cylinder *cyl = new Cylinder();
    cyl->make_mesh(2*M_PI, 1);
    glm::vec3 xaxis = glm::vec3(1, 0, 0);
    //root->addChild(cylnode);


    Sphere *sp = new Sphere();
    sp->make_mesh(3);
    //model = glm::rotate(90.0f, glm::vec3(1.0, 0.0, 0.0));
    model = 
	 //glm::rotate(glm::mat4(1.0f), 90.0f, xaxis)*
	glm::translate(glm::mat4(1.0f), glm::vec3(0, 2.0f, 0)) ;
    SceneNode *spnode = new SceneNode(sp, colorShader);
    spnode->rotate(model);
    //model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, -3.0, 0.0));
    //spnode->translate(model);
    //root->addChild(spnode);

    /*
    Square *sq = new Square();
    sq->make_mesh();
    SceneNode *root = new SceneNode(sq, textShader);

    Triangle *tri = new Triangle();
    tri->make_mesh();
    SceneNode *trinode = new SceneNode(tri, colorShader);
    root->addChild(trinode);

    Cube *c = new Cube();
    c->make_mesh();
    SceneNode *cubenode = new SceneNode(c, colorShader);
    root->addChild(cubenode);


    Cylinder *cyl = new Cylinder();
    cyl->make_mesh(4.0, 1, 3, 50);
    SceneNode *cylnode = new SceneNode(cyl, colorShader);
    root->addChild(cylnode);

    Circle *cic = new Circle();
    cic->make_mesh(2, 40);

    Sphere *sp = new Sphere();
    sp->make_mesh(3);
    SceneNode *spnode = new SceneNode(sp, colorShader);
    cylnode->addChild(spnode);
    */

    View *camera = new View();
    glm::vec3 eye(0,1,-2);
    glm::vec3 target(0,0,0);
    //camera->Eye(eye);


    //Triangle *tri2 = new Triangle();
    //tri2->make_mesh(g_vertex_buffer_data2, g_color_buffer_data);
   // glm::vec3 xaxis(1.0, 0.0, 0.0);
    //tri->rotate(glm::rotate(glm::mat4(1.0), 45.0, xaxis));

    //Scene *sc = new Scene();
    //assert(sc->initShader("shader/triangle.v.glsl", "shader/triangle.f.glsl") == 1);
    //assert(sc->initShader("shader/color.v.glsl", "shader/color.f.glsl") == 1);
    //sc->addChild(sp);

    myscene = root;
    myscene2 = spnode;


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

 /* 
  glUseProgram(myscene->get_program());
  GLint text1 = glGetUniformLocation(myscene->get_program(), "texture0");
  glUniform1i(text1, 0);
  glActiveTexture(GL_TEXTURE9);
  glBindTexture(GL_TEXTURE_2D, text1);
  */

     
  myrender = new Render(myscene); 
  myrender->drawTexture(myscene);
  myrender->drawScene(myscene);

  myrender2 = new Render(myscene2);
  myrender2->drawScene(myscene2);

  glutSwapBuffers();
}

void onIdle()
{

  float angle = glutGet(GLUT_ELAPSED_TIME) / 1000.0 * 45;  // 45° per second
  glm::vec3 axis_y(1, 0, 0);
  glm::mat4 anim = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis_y);

  glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
  glm::mat4 view = glm::lookAt(glm::vec3(0.0, -6.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
  glm::mat4 projection = glm::perspective(45.0f, 1.0f*WIDTH/HEIGHT, 0.1f, 100.0f);

  glm::mat4 mvp = projection * view * model;// * anim;
  glm::mat4 mvp2 = projection * view * model * anim;


  myrender->buildMatrix(myscene, mvp);
  myrender2->buildMatrix(myscene2, mvp);
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
