#ifndef __RENDER_H__
#define __RENDER_H__
#include "scene.h"

#include <GL/glew.h>
#include <GL/freeglut.h>

class Render : public Object
{
    private:
	typedef glm::mat4 mat4;
	Scene *_scene;
	SceneNode *_sceneNode;
    public:
	Render(Scene *sc){ _scene = sc;}
	Render(SceneNode *sn){ _sceneNode = sn;}
	void drawScene();
	void drawScene(SceneNode *sn);
	void buildMatrix(SceneNode *sn, mat4 stack = mat4(1.0f));

	~Render() {delete _scene;}
};




#endif
