#include "geometry.h"

void Object2D::add_texture(const char* file)
{
    int img_w, img_h;
    unsigned char* img = SOIL_load_image(file, &img_w, &img_h, NULL, 0);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_w, img_h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
}

void Triangle::make_mesh()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 0.0f,  1.0f, 0.0f,
	};

	GLfloat g_color_buffer_data[] = {
		1.0f, 0.0f, 0.0f,
		 0.0f, 1.0f, 0.0f,
		 0.0f,  0.0f, 1.0f,
	};

	GLfloat g_uv_data[] = {
	    0.0f, 0.0f,
	    1.0f, 0.0f,
	    0.5f, 1.0f,

	};
	
	GLubyte triangle_elements[] = {
		0, 1, 2,
	};

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_elements), triangle_elements, GL_STATIC_DRAW);

	glGenBuffers(3, vbo);

	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_data), g_uv_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		2,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

Object2D::~Object2D()
{
    glDeleteBuffers(3, vbo);
    glDeleteBuffers(1, &ibo);
    glDeleteVertexArrays(1, &vao);
}



void Triangle::make_mesh(GLfloat *vertex, GLfloat *color)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLubyte triangle_elements[] = {
		0, 1, 2,
	};

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangle_elements), triangle_elements, GL_STATIC_DRAW);

	glGenBuffers(3, vbo);
	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 9*sizeof(GLfloat), vertex, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, 9*sizeof(GLfloat), color, GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Square::make_mesh()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		 1.0f, -1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f
	};

	GLfloat g_color_buffer_data[] = {
		1.0f, 0.0f, 0.0f,
		 0.0f, 1.0f, 0.0f,
		 0.0f,  0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
	};

	GLfloat g_uv_buffer_data[] = {
	    0.0f, 0.0f,
	    1.0f, 0.0f,
	    1.0f, 1.0f,
	    0.0f, 1.0f,
	};

	GLubyte square_elements[] = {
		0, 1, 2,
		0, 2, 3
	};

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(square_elements), square_elements, GL_STATIC_DRAW);

	glGenBuffers(3, vbo);

	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cube::make_mesh()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);


	GLfloat g_vertex_buffer_data[] = {
    -1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0,
    // back
    -1.0, -1.0, -1.0,
     1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
    -1.0,  1.0, -1.0,
	};

	GLfloat g_color_buffer_data[] = {
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
    // back colors
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
	};

	GLubyte square_elements[] = {
    // front
    0, 1, 2,
    2, 3, 0,
    // top
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // bottom
    4, 0, 3,
    3, 7, 4,
    // left
    4, 5, 1,
    1, 0, 4,
    // right
    3, 2, 6,
    6, 7, 3,
	};

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(square_elements), square_elements, GL_STATIC_DRAW);

	glGenBuffers(3, vbo);

	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Cylinder::make_mesh(float height, float up_radius, float down_radius, int hstack)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vectorFloat g_vertex_buffer_data;
	vectorFloat g_color_buffer_data;
	vectorUbyte cylinder_elements;


	float seg_angle = 2.0 * M_PI / hstack;
	

	for(int h = 0; h < 2*hstack; h++)
	{
	        int sign = (h < hstack)? 1 : -1;
		int radius = (h < hstack) ? up_radius : down_radius;

		g_vertex_buffer_data.push_back(radius * cos(seg_angle * h));
		g_vertex_buffer_data.push_back(sign * height / 2.0);
		g_vertex_buffer_data.push_back(radius * sin(seg_angle * h));

		g_color_buffer_data.push_back(1);
		g_color_buffer_data.push_back(0);
		g_color_buffer_data.push_back(0);
	}

	/*
	for(int v = 0; v < vstack; v++)
	{
	    for(int h = 0; h < hstack; h++)
	    {
		g_vertex_buffer_data.push_back(radius * cos(seg_angle * h));
		g_vertex_buffer_data.push_back(height / 2.0 - seg_height * v);
		g_vertex_buffer_data.push_back(radius * sin(seg_angle * h));

		g_color_buffer_data.push_back(1);
		g_color_buffer_data.push_back(0);
		g_color_buffer_data.push_back(0);
		g_vertex_buffer_data[h * vstack + v + 0] = cos(seg_angle * h);
		g_vertex_buffer_data[h * 3*vstack + v] [ 1] = height / 2.0 - seg_height * v;
		g_vertex_buffer_data[h * 3*vstack + v] [ 2] = sin(seg_angle * h);

	    }
	}
	*/

	/*
		cylinder_elements.push_back(0);
		cylinder_elements.push_back(1);
		cylinder_elements.push_back(vstack+1);

		cylinder_elements.push_back(0);
		cylinder_elements.push_back(vstack+1);
		cylinder_elements.push_back(vstack);
		*/

	/*
	for(int v = 0; v < vstack-1; v++)
	{
	    for(int h = 0; h < hstack; h++)
	    {
		cylinder_elements.push_back(v * (hstack) + h);
		cylinder_elements.push_back((v+1)*(hstack) + (h+1) % hstack);
		cylinder_elements.push_back((v+1)*(hstack) + h);

		cylinder_elements.push_back(v * (hstack) + h);
		cylinder_elements.push_back(v*(hstack) + (h+1)%hstack);
		cylinder_elements.push_back((v+1)*(hstack) + (h+1)%hstack);

	    }
	}
	*/
	for(int h = 0; h < hstack; h++)
	{
		cylinder_elements.push_back(0 * (hstack) + h);
		cylinder_elements.push_back((0+1)*(hstack) + h);
		cylinder_elements.push_back((0+1)*(hstack) + (h+1) % hstack);

		cylinder_elements.push_back(0 * (hstack) + h);
		cylinder_elements.push_back((0+1)*(hstack) + (h+1)%hstack);
		cylinder_elements.push_back(0*(hstack) + (h+1)%hstack);
	}




	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cylinder_elements.size() * sizeof(GLubyte), &cylinder_elements[0], GL_STATIC_DRAW);

	glGenBuffers(3, vbo);

	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, g_vertex_buffer_data.size() * sizeof(GLfloat), &g_vertex_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, g_color_buffer_data.size()*sizeof(GLfloat), &g_color_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Circle::make_mesh(float radius, int stack)
{

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vectorFloat g_vertex_buffer_data;
	vectorFloat g_color_buffer_data;
	vectorUbyte circle_elements;

	float seg_angle = 2.0 * M_PI / stack; 

	for(int i = 0; i < stack; i++)
	{
	    g_vertex_buffer_data.push_back(radius * cos(seg_angle * i));
	    g_vertex_buffer_data.push_back(0);
	    g_vertex_buffer_data.push_back(radius * sin(seg_angle * i));

	    g_color_buffer_data.push_back(1);
	    g_color_buffer_data.push_back(0);
	    g_color_buffer_data.push_back(0);
	}
	g_vertex_buffer_data.push_back(0);
	g_vertex_buffer_data.push_back(0);
	g_vertex_buffer_data.push_back(0);

	g_color_buffer_data.push_back(1);
	g_color_buffer_data.push_back(0);
	g_color_buffer_data.push_back(0);


	for(int i = 0; i < stack; i++)
	{
	   circle_elements.push_back(stack + 1);
	   circle_elements.push_back(i);
	   circle_elements.push_back((i+1) %stack);
	}

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, circle_elements.size() * sizeof(GLubyte), &circle_elements[0], GL_STATIC_DRAW);

	glGenBuffers(3, vbo);

	/////////////1st buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, g_vertex_buffer_data.size() * sizeof(GLfloat), &g_vertex_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(0);
	//////


	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, g_color_buffer_data.size() * sizeof(GLfloat),  &g_color_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
///////////////////junk

/*
void Geometry::set_attribute_buffer()
{
  Attributes triangle_attributes[] = {
	  {{0.0,  0.8, 0.0},{1.0, 0.0, 0.0}},
	  {{-0.8, -0.8, 1.0},{0.0, 1.0, 0.0}},
	  {{0.8, -0.8, 0.0},{0.0, 0.0, 1.0}}
  };
///////////////////junk

/
void Geometry::set_attribute_buffer()
{
  Attributes triangle_attributes[] = {
	  {{0.0,  0.8, 0.0},{1.0, 0.0, 0.0}},
	  {{-0.8, -0.8, 1.0},{0.0, 1.0, 0.0}},
	  {{0.8, -0.8, 0.0},{0.0, 0.0, 1.0}}
  };
  glGenBuffers(1, &vboID);
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_attributes), triangle_attributes, GL_STATIC_DRAW);

}

void Geometry::draw_buffer()
{
  glEnableVertexAttribArray(attribute_vertex);
  glEnableVertexAttribArray(attribute_color);

  //glUniform1f(triangle->uniform_fade, 1.0);
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  glVertexAttribPointer(
    attribute_vertex, // attribute
    3,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    sizeof(Attributes),                 // no extra data between each position
    0                  // offset of first element
  );

  //glBindBuffer(GL_ARRAY_BUFFER, vbo_triangle);

  glVertexAttribPointer(
   attribute_color, // attribute
    3,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    sizeof(Attributes),                 // no extra data between each position
    (GLvoid*)(sizeof(GLfloat) * 3)                  // offset of first element
  );


  glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(attribute_vertex);
  glDisableVertexAttribArray(attribute_color);
}

void Cube::set_attribute_buffer()
{
  GLfloat cube_vertices[] = {
    // front
    -1.0, -1.0,  1.0,
     1.0, -1.0,  1.0,
     1.0,  1.0,  1.0,
    -1.0,  1.0,  1.0//,
    // back
    -1.0, -1.0, -1.0,
     1.0, -1.0, -1.0,
     1.0,  1.0, -1.0,
    -1.0,  1.0, -1.0,
  };

  glGenBuffers(1, &vertexID);
  glBindBuffer(GL_ARRAY_BUFFER, vertexID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

  GLfloat cube_colors[] = {
    // front colors
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
    // back colors
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
  };
  glGenBuffers(1, &colorID);
  glBindBuffer(GL_ARRAY_BUFFER, colorID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(cube_colors), cube_colors, GL_STATIC_DRAW);

  GLfloat texture_coord[] = {
    // front colors
    0.0, 0.0,
    1.0, 0.0,
    1.0, 1.0,
    0.0, 1.0//,
    // back colors
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,
    1.0, 1.0, 1.0,
  };
  glGenBuffers(1, &texture->textureCoordID);
  glBindBuffer(GL_ARRAY_BUFFER, texture->textureCoordID);
  glBufferData(GL_ARRAY_BUFFER, sizeof(texture_coord), texture_coord, GL_STATIC_DRAW);

  GLushort cube_elements[] = {
    // front
    0, 1, 2,
    2, 3, 0
    // top
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // bottom
    4, 0, 3,
    3, 7, 4,
    // left
    4, 5, 1,
    1, 0, 4,
    // right
    3, 2, 6,
    6, 7, 3,
  };
  glGenBuffers(1, &indexID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_elements), cube_elements, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


}
void Cube::draw_buffer()
{

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture->textureID);
  glUniform1i(texture->uniform_texture, 0);

  glEnableVertexAttribArray(attribute_vertex);

  //glUniform1f(triangle->uniform_fade, 1.0);
  glBindBuffer(GL_ARRAY_BUFFER, vertexID);
  glVertexAttribPointer(
    attribute_vertex, // attribute
    3,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    0                  // offset of first element
  );

  glEnableVertexAttribArray(attribute_color);

  glBindBuffer(GL_ARRAY_BUFFER, colorID);
  glVertexAttribPointer(
    attribute_color, // attribute
    3,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    0                  // offset of first element
  );

  glEnableVertexAttribArray(texture->attribute_texture_coord);

  glBindBuffer(GL_ARRAY_BUFFER, texture->textureCoordID);
  glVertexAttribPointer(
    texture->attribute_texture_coord, // attribute
    2,                 // number of elements per vertex, here (x,y)
    GL_FLOAT,          // the type of each element
    GL_FALSE,          // take our values as-is
    0,                 // no extra data between each position
    0                  // offset of first element
  );

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexID);
  int size;  glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
  //glDrawElements(GL_TRIANGLES, size/sizeof(GLushort), GL_UNSIGNED_SHORT, 0);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);

  //glDrawArrays(GL_TRIANGLES, 0, 3);

  glDisableVertexAttribArray(attribute_vertex);
  glDisableVertexAttribArray(texture->attribute_texture_coord);

  //glDisableVertexAttribArray(attribute_color);
}

void Cube::load_texture(const char* name, int &width, int &height)
{

  unsigned char* img = SOIL_load_image(name, &width, &height, NULL, 0);
  glGenTextures(1, &texture->textureID);
  glBindTexture(GL_TEXTURE_2D, texture->textureID);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, img); // target
}
*/
