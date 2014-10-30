#include "render.h"

void Render::drawScene()
{
    for(int i = 0; i < _scene->length(); i++)
    {
	Object2D* obj = _scene->childAt(i);

	glBindVertexArray(obj->VAO());
	glUseProgram(_scene->Program());

	int size;
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glDrawElements(GL_TRIANGLES, size/sizeof(GLubyte), GL_UNSIGNED_BYTE, 0);

	glBindVertexArray(0);

	//glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}
