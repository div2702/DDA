
#include<windows.h>
#include<GL/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

void display()
{
      int i;
    float x=0.0;
    float y=0.0;
    float dx=4.0;
    float dy=6.0;
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    int steps =6;
    float sf=float(steps);
    float xinc=dx/sf;
    float yinc=dy/sf;
    for(i=1;i<=steps;i++)
    {

        x=x+xinc;
        y=y+yinc;
        draw_pixel(myround(x),myround(y));
    }
}

int myround(float a)
{
    int remain, actual;
    int val;
    actual = a*10;
    remain = actual%10;
    if(remain >5 )
    {
        val = actual + 10 - remain ;
    }
    else
    {
        val = actual - remain ;
    }
    return val/10;
}
void draw_pixel(int xc,int yc)
{
    glColor3f(0.6, 0.0, 0.9);
    glBegin(GL_POINT);
    glVertex2i(xc,yc);
    glFlush();
    glEnd();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("My first OPENGL Program\n");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
