attribute vec3 vertex;
//attribute vec3 vertex_color;
//attribute vec3 color;
attribute vec2 texture_uv;

uniform mat4 mvp;

//varying vec3 frag_color;
//varying vec3 f_color;
varying vec2 f_texture;

void main(void) {
  f_texture = texture_uv;
  //f_color = color;
  gl_Position = mvp * vec4(vertex, 1.0);
  //gl_Position = vec4(vertex_position, 0.0, 1.0);
}
