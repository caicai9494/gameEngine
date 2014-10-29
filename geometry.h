#ifndef _GEOMETRY
#define _GEOMETRY

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <SOIL/SOIL.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Object
{
    public:
	Object(){}
	virtual ~Object(){}
};

class View : public Object
{
	protected:
		glm::mat4 matrix;
		glm::vec3 eye;
		glm::vec3 target;
		glm::vec3 up;
	public:
		View(){up = glm::vec3(0, 1, 0); matrix = glm::mat4(1.0);}

		float* lookAt();
		
		void Eye(glm::vec3 &e) { eye = e;}
		void Target(glm::vec3 &t) { eye = t;}


};



class Object2D : public Object
{
	protected:
		glm::mat4 matrix;
		GLuint vao;
		GLuint vbo[3];
	public:

		Object2D(){matrix = glm::mat4(1.0);}

		void translate(glm::mat4 &tr) {matrix *= tr;}
		void rotate(glm::mat4 &rt) {matrix *= rt;}
		void scale(glm::mat4 &sc) {matrix *= sc;}

		float* get_matrix() { return glm::value_ptr(matrix);}

		GLuint VAO() {return vao;}
		~Object2D();

};

class Triangle : public Object2D
{
    public:
	//void make_mesh();
	void make_mesh(GLfloat* vertex, GLfloat* color);
	~Triangle(){}
};


#endif
