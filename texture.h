#ifndef TEXTURE_H
#define TEXTURE_H

#include "geometry.h"
#include <SOIL/SOIL.h>

class Texture : public Object
{

    private:
	GLuint textureID;
    public:
	void load_texture(const char* path);
};


#endif
