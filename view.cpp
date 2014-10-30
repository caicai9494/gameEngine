#include "view.h"


float* View::lookAt()
{
    matrix = glm::lookAt(eye, target, up);
    return glm::value_ptr(matrix);
}
