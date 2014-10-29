#ifndef _GEOMETRY
#define _GEOMETRY

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <SOIL/SOIL.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/*
struct _attribute{
	GLfloat coord2d[3];
	GLfloat color3d[3];
};

struct _text{
	GLuint textureID;
	GLuint textureCoordID;
	int width;
	int height;
	GLint uniform_texture;
	GLint attribute_texture_coord;
};
typedef struct _text Texture;
typedef struct _attribute Attributes;

class Geometry
{
	public:
		//vertex, color, normal ...
		//Attributes *VBO;
		//deprecated
		GLuint vboID;


		GLint attribute_vertex;
		GLint attribute_color;
		GLint uniform_fade;
		GLint uniform_transform;
		GLint uniform_mvp;

		//Geometry(){}
		//Geometry(Attributes *attr):VBO(attr){

		virtual void set_attribute_buffer();
		virtual void draw_buffer();

		virtual void load_texture(const char *name, int &width, int &height) = 0;

};

class Cube : public Geometry
{
	public:
		GLuint vertexID;
		GLuint colorID;
		GLuint indexID;

		Texture *texture = new Texture;

		virtual void set_attribute_buffer();
		virtual void draw_buffer();

		virtual void load_texture(const char* name, int &width, int &height);
};
*/

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
	public:
		Object2D(){matrix = glm::mat4(1.0);}

		float* get_matrix() { return glm::value_ptr(matrix);}

		void translate(glm::mat4 &tr) {matrix *= tr;}
		void rotate(glm::mat4 &rt) {matrix *= rt;}
		void scale(glm::mat4 &sc) {matrix *= sc;}
		virtual void make_mesh() = 0;

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


#endif
