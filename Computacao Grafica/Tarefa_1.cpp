#include <GL/glut.h>


void init(void);
void display(void);


void init(void)
{
  // define a cor de background da janela
  glClearColor(1.0, 1.0, 1.0, 1.0);

  // define o sistema de visualização - tipo de projeção
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity();
  glOrtho (-250, 250, -250, 250, -250, 250);
}

void display() {

    // Limpa a janela, colocando na tela a cor definida pela função glClearColor
    glClear(GL_COLOR_BUFFER_BIT);


    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.5, 0.7);
    glVertex3f(-125, 125, 0);
    glVertex3f(125, 125, 0);
    glVertex3f(0, 250, 0);
    glEnd();

  	glBegin(GL_POLYGON);
    glColor3f(0.1, 0.3, 0.5);
  	glVertex3f(-125, -125, 0);
  	glVertex3f(125, -125, 0);;
  	glVertex3f(125, 125, 0);
  	glVertex3f(-125, 125, 0);
  	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.9, 1.0);
  	glVertex3f(-75, -125, 0);
  	glVertex3f(-25, -125, 0);;
  	glVertex3f(-25, 25, 0);
  	glVertex3f(-75, 25, 0);
  	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
  	glVertex3f(25, 0, 0);
  	glVertex3f(25, -50, 0);;
  	glVertex3f(75, -50, 0);
  	glVertex3f(75, 0, 0);
  	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.3, 0.5);
  	glVertex3f(25, -20, 0);
  	glVertex3f(25, -30, 0);;
  	glVertex3f(75, -30, 0);
  	glVertex3f(75, -20, 0);
  	glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.3, 0.5);
  	glVertex3f(45, 0, 0);
  	glVertex3f(45, -50, 0);;
  	glVertex3f(55, -50, 0);
  	glVertex3f(55, 0, 0);
  	glEnd();
    
    // Libera o buffer de comando de desenho para fazer o desenho acontecer o mais rápido possível.
    glFlush();
}

void keyboard( unsigned char key, int x, int y )
{
  GLfloat colors[][3] = { { 0.0, 0.0, 0.0}, {1.0, 1.0, 1.0} };
  static int back;
  switch (key) {
    case ' ':
        back ^= 1;
        glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0);
        glutPostRedisplay();
  }
  display();
}


int main(int argc, char** argv)
{

 //Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas.
 //É possível passar argumentos para a função glutInit provenientes da linha de execução, tais como informações sobre a geometria da tela
  glutInit(&argc, argv);

  //Informa à biblioteca GLUT o modo do display a ser utilizado quando a janela gráfica for criada.
  // O flag GLUT_SINGLE força o uso de uma janela com buffer simples, significando que todos os desenhos serão feitos diretamente nesta janela.
  // O flag GLUT_RGB determina que o modelo de cor utilizado será o modelo RGB.
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

  //Define o tamanho inicial da janela, 256x256 pixels, e a posição inicial do seu canto superior esquerdo na tela, (x, y)=(100, 100).
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (200, 200);

  // Cria uma janela e define seu título
  glutCreateWindow ("Casinha");

  //Nesta função é definido o estado inicial do OpenGL. Ajustes podem ser feitos para o usuário nessa função.
  init();

  // Define display() como a função de desenho (display callback) para a janela corrente.
  // Quando GLUT determina que esta janela deve ser redesenhada, a função de desenho é chamada.
  glutDisplayFunc(display);

  // Indica que sempre que uma tecla for pressionada no teclado, GLUT deverá chama a função keyboard() para tratar eventos de teclado (keyboard callback).
  // A função de teclado deve possuir o seguinte protótipo:
  glutKeyboardFunc(keyboard);


  glutMainLoop();

  return 0;

}