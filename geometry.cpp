#include "geometry.h"

void Object2D::bindVAO()
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindVertexArray(0);
}

void Object2D::bindVBO(vectorFloat &data, int id, int size, int offset)
{
    	glGenBuffers(1, &vbo[id]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[id]);
	glBufferData(GL_ARRAY_BUFFER, data.size()*sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		id,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		size,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(id);
}

void Object2D::bindIBO(vectorUbyte &data)
{

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GLubyte), &data[0], GL_STATIC_DRAW);
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

	//vectorFloat vtest(g_vertex_buffer_data);

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
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
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

void Cylinder::make_mesh(float height, float radius, int hstack)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vectorFloat g_vertex_buffer_data;
	vectorFloat g_color_buffer_data;
	vectorFloat g_uv_buffer_data;
	vectorFloat g_normal_buffer_data;
	vectorUbyte cylinder_elements;


	float seg_angle = 2.0 * M_PI / hstack;
	

	for(int h = 0; h < 2*hstack; h++)
	{
	        int sign = (h < hstack)? 1.0 : -1.0;

		g_vertex_buffer_data.push_back(radius * cos(seg_angle * h));
		g_vertex_buffer_data.push_back(sign * height / 2.0);
		g_vertex_buffer_data.push_back(radius * sin(seg_angle * h));

		g_normal_buffer_data.push_back(radius * cos(seg_angle * h));
		g_normal_buffer_data.push_back(0);
		g_normal_buffer_data.push_back(radius * sin(seg_angle * h));

		g_color_buffer_data.push_back(1);
		g_color_buffer_data.push_back(0);
		g_color_buffer_data.push_back(0);


		g_uv_buffer_data.push_back(1.0 / h);
		g_uv_buffer_data.push_back(sign/2 + 0.5);

	}

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

	glGenBuffers(4, vbo);

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

	glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	glBufferData(GL_ARRAY_BUFFER, g_uv_buffer_data.size()*sizeof(GLfloat), &g_uv_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		2,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ARRAY_BUFFER, g_normal_buffer_data.size()*sizeof(GLfloat), &g_normal_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		3,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(3);

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

void Sphere::make_mesh(float radius, int hstack, int vstack)
{

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vectorFloat g_vertex_buffer_data;
	vectorFloat g_color_buffer_data;
	vectorFloat g_normal_buffer_data;
	vectorUbyte circle_elements;

	//hstack = 20;
	//vstack = 20;

	float seg_h_angle = 2.0 * M_PI / hstack; 
	float seg_v_angle =  M_PI / vstack; 

	for(int v = 0; v < vstack; v++)
	{
	    float r = radius * sin(seg_v_angle * v);

	    for(int h = 0; h < hstack; h++)
	    {
	    	g_vertex_buffer_data.push_back(r * cos(seg_h_angle * h));
	    	g_vertex_buffer_data.push_back(radius * cos(seg_v_angle * v));
	    	g_vertex_buffer_data.push_back(r * sin(seg_h_angle * h));

	    	g_color_buffer_data.push_back(sin(v *seg_v_angle));
	    	g_color_buffer_data.push_back(0);
	    	g_color_buffer_data.push_back(0);

	    	g_normal_buffer_data.push_back(r * cos(seg_h_angle * h));
	    	g_normal_buffer_data.push_back(radius * cos(seg_v_angle * v));
	    	g_normal_buffer_data.push_back(r * sin(seg_h_angle * h));

	    }
	}

	for(int v = 0; v < vstack; v++)
	{
	    for(int h = 0; h < hstack; h++)
	    {
	   	circle_elements.push_back(v * hstack + h);
	   	circle_elements.push_back((v+1) * hstack + h);
	   	circle_elements.push_back((v+1) * hstack + (h+1)%hstack);

	   	circle_elements.push_back(v * hstack + h);
	   	circle_elements.push_back((v+1) * hstack + (h+1)%hstack);
	   	circle_elements.push_back(v * hstack + (h+1) %hstack);
	    }
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

	glBindBuffer(GL_ARRAY_BUFFER, vbo[3]);
	glBufferData(GL_ARRAY_BUFFER, g_normal_buffer_data.size() * sizeof(GLfloat),  &g_normal_buffer_data[0], GL_STATIC_DRAW);
	glVertexAttribPointer(
		3,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glEnableVertexAttribArray(3);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
