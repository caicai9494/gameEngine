#ifndef _GEOMETRY
#define _GEOMETRY

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <SOIL/SOIL.h>

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

		Texture *texture = new Texture();

		virtual void set_attribute_buffer();
		virtual void draw_buffer();

		virtual void load_texture(const char* name, int &width, int &height);
};

#endif
