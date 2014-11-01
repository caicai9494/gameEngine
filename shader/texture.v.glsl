attribute vec3 vertex;
attribute vec2 texture_uv;

uniform mat4 mvp;

varying vec2 f_texture;

void main(void) {
  f_texture = texture_uv;
  gl_Position = mvp * vec4(vertex, 1.0);
}
