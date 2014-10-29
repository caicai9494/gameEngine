#include "mainWindow.h"



MainWindow::MainWindow(int width, int height, const char* name, int argc, char* argv[])
{
  windowW = width;
  windowH = height;

  glutInit(&argc, argv);
  glutInitContextVersion(2,0);
  glutInitDisplayMode(GLUT_RGBA|GLUT_ALPHA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize(width, height);
  glutCreateWindow(name);
}

int MainWindow::init_resources()
{

 //triangle = new Geometry();
 //triangle->set_attribute_buffer();
 //
// cube = new Cube();
 //cube->set_attribute_buffer();
 //cube->load_texture("text01.jpg",
//	 cube->texture->width,
//	 cube->texture->height);
 //cube->set_attribute_buffer();

 //shader = new Shader();
 //assert(shader->initShader() == 1);
 //assert(shader->setupAttribute(cube->attribute_vertex, "vertex_position") == 1);
 //assert(shader->setupAttribute(cube->attribute_color, "vertex_color") == 1);
 //assert(shader->setupAttribute(cube->texture->attribute_texture_coord, "vertex_texture") == 1);

 //assert(shader->setupUniform(cube->texture->uniform_texture, "texture") == 1);
 //
// assert(shader->setupUniform(cube->uniform_mvp, "MVP") == 1);

    Triangle *tri = new Triangle();
    tri->make_mesh();

    Scene *sc = new Scene();
    sc->initShader();
    sc->addChild(tri);

    myscene = sc;


  return 1;
}


void MainWindow::Display()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glUseProgram(shader->program);

  //cube->draw_buffer();
  
  Render *r = new Render(myscene); 
  r->drawScene();

  glutSwapBuffers();
}

void MainWindow::onIdle()
{
    /*
	//float move = sinf(glutGet(GLUT_ELAPSED_TIME) / 1000.0 * (2*M_PI) / 5.0);
	float angle = glutGet(GLUT_ELAPSED_TIME) /  300.0;
	//glm::mat4 m_transform = glm::translate(glm::mat4(1.0f), glm::vec3(move, 0, 0)) *
	//				glm::rotate(glm::mat4(1.0f), angle, zaxis);
	glm::mat4 model = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0, 0.0, 1.0)) * glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));
	glm::mat4 view = glm::lookAt(glm::vec3(0.0, 2.0, 0.0), glm::vec3(0.0,0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
	glm::mat4 projection = glm::perspective(45.0f, 1.0f * windowW / windowH, 0.1f, 10.0f);
	glm::mat4 mvp = projection * view * model;

	glUseProgram(shader->program);
	glUniformMatrix4fv(cube->uniform_mvp, 1, GL_FALSE, glm::value_ptr(mvp));
	//glUniform1f(triangle->uniform_fade, move);
	//glUniformMatrix4fv(cube->uniform_transform, 1, GL_FALSE, glm::value_ptr(m_transform));
	glutPostRedisplay();
	*/
}


void MainWindow::free_resources()
{
    /*
  glDeleteProgram(shader->program);
  glDeleteBuffers(1, &cube->vertexID);
  //glDeleteBuffers(1, &cube->colorID);
  glDeleteBuffers(1, &cube->indexID);
  glDeleteBuffers(1, &cube->texture->textureCoordID);
  glDeleteTextures(1, &cube->texture->textureID);
  */
}



