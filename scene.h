#include <GL/glew.h>
#include <GL/freeglut.h>
#include "common/shader_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "geometry.h"
#include "view.h"
#include <vector>

#ifndef __SCENE
#define __SCENE

extern const char* VERTEX;
extern const char* COLOR;
extern const char* TEXTURE_UV;


class Shader:public Object
{
    protected:
		GLuint program;
	public:
		GLuint Program() {return program;}
		//return 0 if fail
		//	 1 if succeed
		int initShader(const char* vshader, const char* fshader);
		~Shader() {glDeleteProgram(program);}
		//return 0 if fail
		//	 1 if succeed
		//int setupAttribute(GLint &attrID, const char* name);
		//int setupUniform(GLint &uniformID, const char* name);
		//int setupTexture(GLenum context, GLint &uniformID, const char* name);
};

class Scene : public Shader
{
    typedef std::vector<Object2D*> vector;
    private:
    	vector array;
	View *view;
    public:
	void addChild(Object2D *obj){array.push_back(obj);}
	Object2D* childAt(int index) {return array.at(index);}
	int length() {return array.size();}

	void addView(View *v) { view = v;}

	~Scene(){}
};

#endif
