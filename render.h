#ifndef __RENDER_H__
#define __RENDER_H__
#include "shader.h"

class Render : public Object
{
    private:
	Scene *_scene;
    public:
	Render(Scene *sc){ _scene = sc;}
	void drawScene();
};


#endif
