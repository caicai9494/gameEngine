#include "geometry.h"

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
