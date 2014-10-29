attribute vec3 vertex_position;
//attribute vec3 vertex_color;
attribute vec2 vertex_texture;

uniform mat4 MVP;

//varying vec3 frag_color;
varying vec2 f_vertex_texture;

void main(void) {
  f_vertex_texture = vertex_texture;
  gl_Position = MVP * vec4(vertex_position, 1.0);
  //gl_Position = vec4(vertex_position, 0.0, 1.0);
}
