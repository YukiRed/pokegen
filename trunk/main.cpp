#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void keyboard(unsigned char key, int x, int y);
void display(void);
void PokePicReverser();
void ShowPokePic();

float PokePic[4 * 4];
float PokeBit(float n, bool isY);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Pokedex 3D - AR-Code Genarator");
    glutKeyboardFunc(&keyboard);
    glutDisplayFunc(&display);
    glutMainLoop();
    return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\x1B':
        exit(EXIT_SUCCESS);
        break;
    case 's':
        PokePicReverser();
        break;
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f( 1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex2f( 1.0f,  1.0f);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(-1.0f,  1.0f);
    glEnd();

    glFlush();
}

void PokePicReverser()
{
    int a = 0;
    float PokePicTemp[4 * 4];
    for(int i = 0; i < 17; i++)
    {
        PokePicTemp[i] = 1.0f;
    }
    ShowPokePic();
    while(!(PokePic == PokePicTemp))
    {
        PokePic[a]++;
        if(PokePic[a] == 2.0f)
        {
            PokePic[a] = 0.0f;
            a++;
            while(-1)
            {
                if(PokePic[a] == 1.0f)
                {
                    a++;
                }
                else
                {
                    PokePic[a] = 1.0f;
                    while(a != 0)
                    {
                        a--;
                        PokePic[a] = 0.0f;
                    }
                    break;
                }
            }
        }
        ShowPokePic();
    }
    exit(EXIT_SUCCESS);
}

void ShowPokePic()
{
    clock_t t;
    time(&t);
    int i = t;
    glClear(GL_COLOR_BUFFER_BIT);
    {
        {
            glBegin(GL_POLYGON);
            glColor3f(PokePic[0], PokePic[0], PokePic[0]);
            glVertex2f(PokeBit(1, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(1, 0), PokeBit(2, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[1], PokePic[1], PokePic[1]);
            glVertex2f(PokeBit(2, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(2, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[2], PokePic[2], PokePic[2]);
            glVertex2f(PokeBit(3, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(2, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[3], PokePic[3], PokePic[3]);
            glVertex2f(PokeBit(4, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(1, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(2, 1));
            glEnd();
        }
        {
            glBegin(GL_POLYGON);
            glColor3f(PokePic[4], PokePic[4], PokePic[4]);
            glVertex2f(PokeBit(1, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(1, 0), PokeBit(3, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[5], PokePic[5], PokePic[5]);
            glVertex2f(PokeBit(2, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(3, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[6], PokePic[6], PokePic[6]);
            glVertex2f(PokeBit(3, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(3, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[7], PokePic[7], PokePic[7]);
            glVertex2f(PokeBit(4, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(2, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(3, 1));
            glEnd();
        }
        {
            glBegin(GL_POLYGON);
            glColor3f(PokePic[8], PokePic[8], PokePic[8]);
            glVertex2f(PokeBit(1, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(1, 0), PokeBit(4, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[9], PokePic[9], PokePic[9]);
            glVertex2f(PokeBit(2, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(4, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[10], PokePic[10], PokePic[10]);
            glVertex2f(PokeBit(3, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(4, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[11], PokePic[11], PokePic[11]);
            glVertex2f(PokeBit(4, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(3, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(4, 1));
            glEnd();
        }
        {
            glBegin(GL_POLYGON);
            glColor3f(PokePic[12], PokePic[12], PokePic[12]);
            glVertex2f(PokeBit(1, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(5, 1));
            glVertex2f(PokeBit(1, 0), PokeBit(5, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[13], PokePic[13], PokePic[13]);
            glVertex2f(PokeBit(2, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(5, 1));
            glVertex2f(PokeBit(2, 0), PokeBit(5, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[14], PokePic[14], PokePic[14]);
            glVertex2f(PokeBit(3, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(5, 1));
            glVertex2f(PokeBit(3, 0), PokeBit(5, 1));
            glEnd();
            glBegin(GL_POLYGON);
            glColor3f(PokePic[15], PokePic[15], PokePic[15]);
            glVertex2f(PokeBit(4, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(4, 1));
            glVertex2f(PokeBit(5, 0), PokeBit(5, 1));
            glVertex2f(PokeBit(4, 0), PokeBit(5, 1));
            glEnd();
        }
    }
    glFlush();
    while(-1)
    {
        time_t t;
        time(&t);
        int d = t - i;
        if (d >= 0.25) break;
    }
}

float PokeBit(float n, bool isY)
{
    n = n * 2 / 6;
    n--;
    if(isY)
    {
        n = n * (-1);
    }
    return n;
}
