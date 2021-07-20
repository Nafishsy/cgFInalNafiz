#include <windows.h>
#include <GL/glut.h>
#include<math.h>>
# define PI           3.14159265358979323846

void window()
{
    glBegin(GL_QUADS);
    glColor3ub(256, 256, 256);
    glVertex2f(0.12,-0.12);
    glVertex2f(-0.12,-0.12);
    glVertex2f(-0.12,0.12);
    glVertex2f(0.12,0.12);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(114, 207, 248);
    glVertex2f(0.1,-0.1);
    glVertex2f(-0.1,-0.1);
    glVertex2f(-0.1,0.1);
    glVertex2f(0.1,0.1);
    glEnd();
}

void apart()
{
    //bottom
    glBegin(GL_QUADS);
    glColor3ub(138,164,179);
    glVertex2f(0.7,-0.9);
    glVertex2f(-0.7,-0.9);
    glVertex2f(-0.7,-0.0);
    glVertex2f(0.7,-0.0);
    glEnd();
    //1st
    glBegin(GL_QUADS);
    glColor3ub(138,164,179);
    glVertex2f(0.5,-0.0);
    glVertex2f(-0.5,-0.0);
    glVertex2f(-0.5,0.30);
    glVertex2f(0.5,0.30);
    glEnd();
    //2nd
    glBegin(GL_QUADS);
    glColor3ub(138,164,179);
    glVertex2f(0.3,0.30);
    glVertex2f(-0.3,0.30);
    glVertex2f(-0.3,0.60);
    glVertex2f(0.3,0.60);
    glEnd();

    //top
    glBegin(GL_QUADS);
    glColor3ub(138,164,179);
    glVertex2f(0.1,0.50);
    glVertex2f(-0.1,0.50);
    glVertex2f(-0.1,0.90);
    glVertex2f(0.1,0.90);

    glEnd();

    float bttmWindowUD = (-0.60);
    float bttmWindowLR =  (-0.60);

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<=6; j++)
        {
            glTranslated(bttmWindowLR,bttmWindowUD,0);
            glScaled(0.3,0.3,0);
            window();
            glLoadIdentity();
            bttmWindowLR += 0.2;
        }
        bttmWindowLR = (-0.60);
        bttmWindowUD += 0.2;
    }

    float FirstWindowUD = (-0.0);
    float FirstWindowLR = (-0.60 + 0.2);
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<=4; j++)
        {
            glTranslated(FirstWindowLR,FirstWindowUD,0);
            glScaled(0.3,0.3,0);
            window();
            glLoadIdentity();
            FirstWindowLR += 0.2;
        }
        FirstWindowLR = (-0.60 + 0.2);
        FirstWindowUD += 0.2;
    }

    float SecondtWindowUD = (0.35);
    float SecondtWindowLR = -0.60 + 0.2*2;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<=2; j++)
        {
            glTranslated(SecondtWindowLR,SecondtWindowUD,0);
            glScaled(0.3,0.3,0);
            window();
            glLoadIdentity();
            SecondtWindowLR += 0.2;
        }
        SecondtWindowLR = -0.60 + 0.2*2;
        SecondtWindowUD += 0.2;
    }

    //bottom mat
    glBegin(GL_QUADS);
    glColor3ub(42, 56, 54);
    glVertex2f(0.2,-0.90);
    glVertex2f(-0.2,-0.9);
    glVertex2f(-0.2,-0.86);
    glVertex2f(0.2,-0.86);
    glEnd();


    //Entrance outline black
    glBegin(GL_QUADS);
    glColor3ub(256, 256, 256);
    glVertex2f(0.1,-0.86);
    glVertex2f(-0.1,-0.86);
    glVertex2f(-0.1,-0.75);
    glVertex2f(0.1,-0.75);
    glEnd();

    //Entrance glass view
    glBegin(GL_QUADS);
    glColor3ub(185, 233, 249);
    glVertex2f(0.09,-0.86);
    glVertex2f(-0.09,-0.86);
    glVertex2f(-0.09,-0.77);
    glVertex2f(0.09,-0.77);
    glEnd();

    //glass reflection
    glTranslated(-0.02,-0.18,0);
    glScaled(-1,0.88,0);
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(231, 247, 253);
    glVertex2f(-0.07,-0.77);
    glVertex2f(-0.09,-0.67);
    glEnd();
    glLoadIdentity();

    //glass reflection
    float posOfLine = -0.04;
    for(int i=0; i<6; i++)
    {
        glTranslated(posOfLine,-0.18,0);
        glScaled(-1,0.88,0);
        glLineWidth(9);
        glBegin(GL_LINES);
        glColor3ub(231, 247, 253);
        glVertex2f(-0.07,-0.77);
        glVertex2f(-0.09,-0.67);
        glEnd();
        glLoadIdentity();
        posOfLine -= 0.02;
    }

    glBegin(GL_QUADS);
    glColor3ub(256, 256, 256);
    glVertex2f(0.0,-0.86);
    glVertex2f(-0.01,-0.86);
    glVertex2f(-0.01,-0.75);
    glVertex2f(0.0,-0.75);
    glEnd();
}
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    apart();


    glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}




