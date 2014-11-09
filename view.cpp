#include "view.h"

glm::vec3 position = glm::vec3(0,-6,0);
float horizontalAngle = M_PI;
float verticalAngle = 0.0f;
float initialFOV = 45.0f;
float speed = 3.0f;
float mouseSpeed = 0.005f;


extern const int WIDTH;
extern const int HEIGHT;
extern GLFWwindow *window;

View::View()
{
    static float lastTime = glfwGetTime();
    float currentTime = glfwGetTime();

    float deltaTime = lastTime - currentTime;

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    glfwSetCursorPos(window, WIDTH/2, HEIGHT/2);

    horizontalAngle -= mouseSpeed * float(WIDTH/2 - xpos);
    verticalAngle += mouseSpeed * float(HEIGHT/2 - ypos);

    glm::vec3 direction(
	   	cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
	   	cos(verticalAngle) * cos(horizontalAngle)
	    );
    glm::vec3 right(
	   	sin(horizontalAngle - M_PI/2), 
		0,
	   	cos(horizontalAngle - M_PI/2) 
	    );
    glm::vec3 up = glm::cross(right, direction);

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
	position -= direction * deltaTime * speed;
    }

    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
	position += direction * deltaTime * speed;
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
	position -= right * deltaTime * speed;
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
	position += right * deltaTime * speed;
    }

    float fov  = initialFOV;

    projectionMatrix = glm::perspective(fov, float(WIDTH/HEIGHT), 0.1f, 100.0f);
    viewMatrix = glm::lookAt(
	   	position,
	        position + direction,
		up	
	    );

    lastTime = currentTime;
}

glm::mat4 View::getProjectionMatrix()
{
    return projectionMatrix;
}

glm::mat4 View::getViewMatrix()
{
    return viewMatrix;
}
