#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <GL/glut.h>

GLint WINDOW_WIDTH  = 500,
      WINDOW_HEIGHT = 500;

void init();
void draw_test();

void mouse_test(GLint button, GLint action, GLint x, GLint y);
void mouse_test2(GLint x, GLint y);
void mouse_test3(GLint x, GLint y);

void keybord_test(GLubyte key, GLint x, GLint y);
void keybord_test2(GLint key, GLint x, GLint y);

void test_create_menu();
void menu_test(GLint item_number);


//=================================================================================================

int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  GLint screen_width  = glutGet(GLUT_SCREEN_WIDTH),
        screen_height = glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
  glutCreateWindow("OpenGL manipulação de entradas (teclado/mouse)");

  init();

  glutDisplayFunc(draw_test);

  glutMouseFunc(mouse_test);
  glutPassiveMotionFunc(mouse_test2);
  glutMotionFunc(mouse_test3);

  glutKeyboardFunc(keybord_test);
  glutSpecialFunc(keybord_test2);

  glutMainLoop();


  return EXIT_SUCCESS;
}

void init()
{
  glClearColor(1.0, 1.0, 1.0, 1.0);

  gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void draw_test()
{
  glClear(GL_COLOR_BUFFER_BIT);

  std::cout<<"Desenho\n";

  glFlush();
}

void mouse_test(GLint button, GLint action, GLint x, GLint y)
{
  switch(button)
  {
    case GLUT_LEFT_BUTTON:
    {
      std::cout<<"Esquerda";
      break;
    }
    case GLUT_MIDDLE_BUTTON:
    {
      std::cout<<"Meio";
      break;
    }
    case GLUT_RIGHT_BUTTON:
    {
      std::cout<<"Direita";
      break;
    }
    default: break;
  }

  if(action == GLUT_DOWN)
    std::cout<<" preciona";
  else //GLUT_UP
    std::cout<<" libera";

// x cresce da esquerda pra direita. O y cresce de cima para baixo
  std::cout<<" em (x:"<<x<<", y:"<<y<<")";

  std::cout<<"\n";
}

void mouse_test2(GLint x, GLint y)
{
  std::cout<<"Movendo mouse sem clicar para posicao (x:"<<x<<", y:"<<y<<")\n";
}

void mouse_test3(GLint x, GLint y)
{
  std::cout<<"Arrastando o mouse para posicao (x:"<<x<<", y:"<<y<<")\n";
}

void keybord_test(GLubyte key, GLint x, GLint y)
{
  GLint m = glutGetModifiers();

  if(m == GLUT_ACTIVE_SHIFT)
    std::cout<<"Shift ou Caps ";
  else if(m == GLUT_ACTIVE_CTRL)
    std::cout<<"Control ";
  else if(m == GLUT_ACTIVE_ALT)
    std::cout<<"Alt ";

//VERIFICAR TABELA ASCII QUANDO O CTRL ESTIVER PRECIONADO COM ALGUMA LETRA
  if(m == GLUT_ACTIVE_CTRL && (GLint) key == 4)
    exit(EXIT_SUCCESS);

  std::cout<<"Tecla: "<<(GLint) key<<" (x:"<<x<<", y:"<<y<<")\n";

  //ESC = 27
  if (key == 27)
    glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void keybord_test2(GLint key, GLint x, GLint y)
{
//GLUT_KEY_F1 .. GLUT_KEY_F12
//GLUT_KEY_UP, GLUT_KEY_DOWN, GLUT_KEY_LEFT, GLUT_KEY_RIGHT
//GLUT_KEY_PAGE_DOWN, GLUT_KEY_HOME etc.

  std::cout<<"Tecla especial: "<<key<<" (x:"<<x<<", y:"<<y<<")\n";

  if(key == GLUT_KEY_F11)
    glutFullScreen();
}