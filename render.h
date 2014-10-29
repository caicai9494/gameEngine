#ifndef __RENDER.H__
#define __RENDER.H__
#include "shader.h"

class render : public object
{
    private:
	scene *_scene;
    public:
	render(scene *sc){ _scene = sc;}
	void drawScene();
};


#endif
