varying vec2 f_texture;

uniform sampler2D texture0;

void main(void) {
 
  gl_FragColor = texture2D(texture0, f_texture);
}
