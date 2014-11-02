#ifndef TEXTURE_H
#define TEXTURE_H

#include "geometry.h"
#include <SOIL/SOIL.h>

class Texture : public Object
{

    private:
	GLuint textureID;
	static int count;
    public:
	Texture(const char* path);
	void load_texture(const char* path);
	GLint textureUniform;
	int get_count() { return count;}
};


#endif
