varying vec2 f_vertex_texture;

//uniform float fade;
uniform sampler2D texture;

void main(void) {
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
  //gl_FragColor = vec4(frag_color, 1.0);
  gl_FragColor = texture2D(texture, f_vertex_texture);
}
