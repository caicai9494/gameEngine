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


class Object2D : public Object
{
	protected:
		glm::mat4 matrix;
		GLuint vao;
		GLuint vbo[3];
		GLuint ibo;
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
	void make_mesh();
	void make_mesh(GLfloat* vertex, GLfloat* color);
	~Triangle(){}
};

class Square : public Object2D
{
    public:
	void make_mesh();
	~Square(){}
};



#endif
