#include "main.h"

#define FPS 60

void init();
void display();
void reshape(int, int);
void timer(int);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    
    glutInitWindowSize(640,640);
    glutCreateWindow("Infinity Race");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    
    return 0;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    #pragma region GAME
    game();
    #pragma endregion

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    camera(60.0, 1.0, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    srand(time(NULL));
    glutTimerFunc(1000/FPS, timer, 0);

    update();
}