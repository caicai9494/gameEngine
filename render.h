#ifndef __RENDER_H__
#define __RENDER_H__
#include "scene.h"

#include <GL/glew.h>
#include <GL/freeglut.h>

class Render : public Object
{
    private:
	Scene *_scene;
    public:
	Render(Scene *sc){ _scene = sc;}
	void drawScene();
	~Render() {delete _scene;}
};


#endif
