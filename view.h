#ifndef _VIEW_H
#define _VIEW_H

#include "geometry.h"
#include <GLFW/glfw3.h>

extern glm::vec3 position;
extern float horizontalAngle;
extern float verticalAngle;
extern float initialFOV;
extern float speed;
extern float mouseSpeed;
extern const int WIDTH;
extern const int HEIGHT;





class View : public Object
{
	protected:
		glm::mat4 viewMatrix;
		glm::mat4 projectionMatrix;
		
	public:

		View();
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();
};


#endif
