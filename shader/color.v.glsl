attribute vec3 vertex;
attribute vec3 color;

uniform mat4 mvp;

varying vec3 f_color;

void main(void) {
  f_color = color;
  gl_Position = mvp * vec4(vertex, 1.0);
  //gl_Position =  vec4(vertex, 1.0);
}
