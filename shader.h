#include <GL/glew.h>
#include <GL/freeglut.h>
#include "common/shader_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef __SHADER
#define __SHADER

class Shader
{
	public:
		GLuint program;
		//return 0 if fail
		//	 1 if succeed
		int initShader();
		//return 0 if fail
		//	 1 if succeed
		int setupAttribute(GLint &attrID, const char* name);
		int setupUniform(GLint &uniformID, const char* name);
		//int setupTexture(GLenum context, GLint &uniformID, const char* name);
};

#endif
