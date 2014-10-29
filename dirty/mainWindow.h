/**
 * From the OpenGL Programming wikibook: http://en.wikibooks.org/wiki/OpenGL_Programming
 * This file is in the public domain.
 * Contributors: Sylvain Beucler
 */
#ifndef _MAINWINDOW
#define _MAINWINDOW

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
#include "shader.h"
#include "render.h"


class MainWindow
{
	private:
		Geometry* triangle;
		Cube* cube;
		Shader *shader;
		int windowW;
		int windowH;
	public:
		MainWindow(int width, int height, const char* name, int argc, char* argv[]);
		int init_resources();
		void free_resources();
		void Display();
		void onIdle();
		Scene *myscene;
};


#endif
