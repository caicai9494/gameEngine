
#include "texture.h"

Texture::Texture(const char* path)
{
    load_texture(path);

    count++;
}

int Texture::count = 0;

void Texture::load_texture(const char* path)
{
    int img_w, img_h;
    unsigned char* img = SOIL_load_image(path, &img_w, &img_h, NULL, 0);

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_w, img_h, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
}
