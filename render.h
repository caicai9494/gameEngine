#ifndef __RENDER_H__
#define __RENDER_H__
#include <GL/glew.h>
#include "common/shader_utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "geometry.h"
#include "view.h"
#include "texture.h"
#include <vector>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "scene.h"


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
	void buildMatrix(SceneNode *sn, mat4 stack = mat4(1.0f), bool keep = true);
	void drawTexture(SceneNode *sn);

	~Render() {delete _scene;}
};




#endif
