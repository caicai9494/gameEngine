// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>

#include "scene.h"
#include "geometry.h"
#include "render.h"
#include "view.h"

using namespace glm;

const int WIDTH = 800;
const int HEIGHT = 600;


int main( void )
{
	// Initialise GLFW
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);


	// Open a window and create its OpenGL context
	window = glfwCreateWindow( WIDTH, HEIGHT, "engine", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS); 
	
	Shader *colorShader = new Shader();
    	assert(colorShader->initShader("shader/color.v.glsl", "shader/color.f.glsl") == 1);

	Cylinder *sq = new Cylinder();
	sq->make_mesh(2,2);

	//Texture *tex = new Texture("checkerboard.jpg");

	do{
	    	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		// Draw nothing, see you in tutorial 2 !
		SceneNode *root = new SceneNode(sq, colorShader);

		double time = glfwGetTime();

  		float angle = time * 45;  // 45° per second
  
 		glm::vec3 axis_y(1, 0, 0);
  		glm::mat4 anim = glm::rotate(glm::mat4(1.0f), glm::radians(angle), axis_y);

  		glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(0.0, 0.0, -4.0));

  		View *view = new View();

  //glm::mat4 view = glm::lookAt(glm::vec3(0.0, -6.0, 0.0), glm::vec3(0.0, 0.0, -4.0), glm::vec3(0.0, 1.0, 0.0));
  //glm::mat4 projection = glm::perspective(45.0f, 1.0f*WIDTH/HEIGHT, 0.1f, 100.0f);

  //glm::mat4 mvp = projection * view * model;// * anim;
  //glm::mat4 mvp2 = projection * view * model * anim;
  		glm::mat4 mvp = view->getProjectionMatrix() *
      		  		view->getViewMatrix() * 
		  		model * anim;



		Render *render = new Render(root);
		render->drawTexture(root);
		render->drawScene(root);
  		render->buildMatrix(root, mvp);
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();


		delete view;
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();



	return 0;
}
