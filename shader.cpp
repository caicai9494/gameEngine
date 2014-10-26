#include "shader.h"


int Shader::initShader()
{
  GLint link_ok = GL_FALSE;

  GLuint vs, fs;
  if ((vs = create_shader("triangle.v.glsl", GL_VERTEX_SHADER))   == 0) return 0;
  if ((fs = create_shader("triangle.f.glsl", GL_FRAGMENT_SHADER)) == 0) return 0;

  program = glCreateProgram();
  glAttachShader(program, vs);
  glAttachShader(program, fs);
  glLinkProgram(program);
  glGetProgramiv(program, GL_LINK_STATUS, &link_ok);

  if (!link_ok) {
    fprintf(stderr, "glLinkProgram:");
    print_log(program);
    return 0;
  }
  else 
	  return 1;
}

int Shader::setupAttribute(GLint &attrID, const char* name)
{
  attrID = glGetAttribLocation(program, name);
  //printf("%d", triangle->attribute_vertex);
  if (attrID == -1) {
    fprintf(stderr, "Could not bind attribute %s\n", name);
    return 0;
  }
  else return 1;
}

int Shader::setupUniform(GLint &uniformID, const char* name)
{
  uniformID = glGetUniformLocation(program, name);
  //printf("%d", triangle->attribute_vertex);
  if (uniformID == -1) {
    fprintf(stderr, "Could not bind uniform %s\n", name);
    return 0;
  }
  else return 1;
}
