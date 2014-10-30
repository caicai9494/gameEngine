#ifndef _VIEW_H
#define _VIEW_H

#include "geometry.h"


class View : public Object
{
	protected:
		glm::mat4 matrix;
		glm::vec3 eye;
		glm::vec3 target;
		glm::vec3 up;
	public:
		View(){up = glm::vec3(0, 1, 0); matrix = glm::mat4(1.0);}

		float* lookAt();
		
		void Eye(glm::vec3 &e) { eye = e;}
		void Target(glm::vec3 &t) { eye = t;}


};


#endif
