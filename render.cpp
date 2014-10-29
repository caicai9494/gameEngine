#include "render.h"

void render::drawScene()
{
    for(int i = 0; i < _scene.length(); i++)
    {
	Object2D* obj = _scene.childAt(i);

	glBindVertexArray(obj->VAO());
	glUseProgram(_scene->program);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
    }
}
