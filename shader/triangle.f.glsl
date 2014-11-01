//varying vec3 f_color;
varying vec2 f_texture;

uniform sampler2D texture0;
//uniform float alpha;

void main(void) {
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
  //gl_FragColor = vec4(f_color, 1.0);
  //gl_FragColor = texture2D(texture, f_vertex_texture);
 
  gl_FragColor = texture2D(texture0, f_texture);
}
