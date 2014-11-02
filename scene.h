#include <GL/glew.h>
#include <GL/freeglut.h>
#include "common/shader_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "geometry.h"
#include "view.h"
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#ifndef __SCENE
#define __SCENE

extern const char* VERTEX;
extern const char* COLOR;
extern const char* TEXTURE_UV;
extern const char* NORMAL;


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


class SceneNode : public Object
{
    private:
    	typedef std::vector<SceneNode*> vectorScene;
	typedef glm::mat4 mat4;
    	Shader *_shader;
    	Object2D *_obj;
	vectorScene _sceneList;
	mat4 _matrix;
	
    public:
	SceneNode(Object2D *obj, Shader* shader);

	Object2D* get_object() { return _obj;}
	SceneNode* childAt(int index) {return _sceneList.at(index);}
	void addChild(SceneNode *node){_sceneList.push_back(node);}
	int length() {return _sceneList.size();}

	void set_shader(Shader *shader) { _shader = shader;}
	GLuint get_program() { return _shader->Program();}


	void translate(glm::mat4 &tr) {_matrix *= tr;}
	void rotate(glm::mat4 &rt) {_matrix *= rt;}
	void scale(glm::mat4 &sc) {_matrix *= sc;}
	mat4& get_matrix() {return _matrix;}

	~SceneNode(){}

};


#endif
