#include "SkyBox.hpp"

#define GL_CLAMP_TO_EDGE 0x812F


// Função para carregar as texturas da skybox
void SkyBox::loadSkyboxTextures()
{
    glGenTextures(6, textureIDs);

    // Nomes dos arquivos das texturas da Skybox
    const char* skyboxFileNames[] = {
        "right.jpg",
        "left.jpg",
        "top.jpg",
        "bottom.jpg",
        "front.jpg",
        "back.jpg"
    };

    for (int i = 0; i < 6; ++i)
    {
        int width, height, channels;
        unsigned char* image = stbi_load(skyboxFileNames[i], &width, &height, &channels, 0);

        if (image != nullptr)
        {
            glBindTexture(GL_TEXTURE_2D, textureIDs[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
            stbi_image_free(image);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }
        else
        {
            // Trate o erro ao carregar a textura
            std::cout << "Erro ao carregar a textura da skybox" << std::endl;
        }
    }
}


// Função para desenhar a skybox
void SkyBox::drawSkybox()
{
    // Desabilitando o teste de profundidade para desenhar a skybox no fundo
    glDisable(GL_DEPTH_TEST);

    // Desabilitando a iluminação para evitar que a skybox seja afetada pelas luzes da cena
    glDisable(GL_LIGHTING);

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);

    // Desenhando a skybox
    glBegin(GL_QUADS);

    // Lado direito
    glBindTexture(GL_TEXTURE_2D, textureIDs[0]);
    glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1); glVertex3f(1, 1, -1);

    // Lado esquerdo
    glBindTexture(GL_TEXTURE_2D, textureIDs[1]);
    glTexCoord2f(0, 0); glVertex3f(-1, -1, 1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(-1, 1, -1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);

    // Topo
    glBindTexture(GL_TEXTURE_2D, textureIDs[2]);
    glTexCoord2f(0, 0); glVertex3f(-1, 1, -1);
    glTexCoord2f(1, 0); glVertex3f(1, 1, -1);
    glTexCoord2f(1, 1); glVertex3f(1, 1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);

    // Base
    glBindTexture(GL_TEXTURE_2D, textureIDs[3]);
    glTexCoord2f(0, 0); glVertex3f(1, -1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(-1, -1, 1);
    glTexCoord2f(0, 1); glVertex3f(1, -1, 1);

    // Fundo
    glBindTexture(GL_TEXTURE_2D, textureIDs[4]);
    glTexCoord2f(0, 0); glVertex3f(1, 1, 1);
    glTexCoord2f(1, 0); glVertex3f(1, -1, 1);
    glTexCoord2f(1, 1); glVertex3f(-1, -1, 1);
    glTexCoord2f(0, 1); glVertex3f(-1, 1, 1);

    // Frente
    glBindTexture(GL_TEXTURE_2D, textureIDs[5]);
    glTexCoord2f(0, 0); glVertex3f(-1, 1, -1);
    glTexCoord2f(1, 0); glVertex3f(-1, -1, -1);
    glTexCoord2f(1, 1); glVertex3f(1, -1, -1);
    glTexCoord2f(0, 1); glVertex3f(1, 1, -1);
    glEnd();

    // Desenhe as outras faces da Skybox da mesma maneira

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_TEXTURE_2D);
}