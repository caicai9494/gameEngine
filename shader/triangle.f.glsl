varying vec3 f_color;

//uniform float alpha;

void main(void) {
  //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
  gl_FragColor = vec4(f_color, 1.0);
  //gl_FragColor = texture2D(texture, f_vertex_texture);
}
