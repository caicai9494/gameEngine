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

void Render::drawScene(SceneNode* sn)
{
    Object2D *obj = sn->get_object();
    assert(obj != NULL);

    glBindVertexArray(obj->VAO());
    glUseProgram(sn->get_program());

    int size;
    glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
    glDrawElements(GL_TRIANGLES, size/sizeof(GLubyte), GL_UNSIGNED_BYTE, 0);

    glBindVertexArray(0);

    int sceneLength = sn->length();
    if(sceneLength)
    {

	for(int i = 0; i < sceneLength; i++)
	    drawScene(sn->childAt(i));

    }
    else
    	return;
}

void Render::buildMatrix(SceneNode *sn, mat4 stack, bool keep)
{   
    
    mat4 mvp = stack * sn->get_matrix();
    glUseProgram(sn->get_program());
    GLint loc = glGetUniformLocation(sn->get_program(), "mvp");
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mvp));

    int sceneLength = sn->length();
    if(sceneLength)
    {

	for(int i = 0; i < sceneLength; i++)
	{
	    if(keep)
	    	buildMatrix(sn->childAt(i), mvp);
	    else
	    	buildMatrix(sn->childAt(i), stack);
	}

    }
    else
    	return;
}

void Render::drawTexture(SceneNode *sn)
{
  Texture *text = sn->get_texture();
  if(sn->get_texture() != NULL)
  {
  	glUseProgram(sn->get_program());
  	text->textureUniform = glGetUniformLocation(sn->get_program(), "texture0");
  	//glUniform1i(text->textureUniform, text->get_count());
  	//glActiveTexture(GL_TEXTURE0 + text->get_count());
	glUniform1i(text->textureUniform, 2);
  	glActiveTexture(GL_TEXTURE0 +2);
  	glBindTexture(GL_TEXTURE_2D, text->textureUniform);
  }

    int sceneLength = sn->length();
    if(sceneLength)
    {

	for(int i = 0; i < sceneLength; i++)
	    drawTexture(sn->childAt(i));
    }
    else
    	return;
}
