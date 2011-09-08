// standart libarys

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// GLUT libarys wiht corrct including for MAC

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// pre-declaring from my function

void keyboard(unsigned char key, int x, int y); // this function is for the key processing
void display(void); // the startscreen ^^
void PokePicReverser(); // in this function genarate the picture arrays via bruteforce
void ShowPokePic(); // show the picture
void TestPic(); // This function is for testing whether the DS can also recognize the images produced.
float PokeBit(float n, bool isY); // genrate the bitfield

//my variable

float PokePic[4 * 4]; // Bitfield of the picture

// Thhis main function is a standart GLUT-Main

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initialization of GLUT
    glutCreateWindow("Pokedex 3D - AR-Code Genarator"); // Create a window whit the title
    glutKeyboardFunc(&keyboard); // Tells the keys to their functions.
    glutDisplayFunc(&display); // Tells GLUT to main scene.
    glutMainLoop(); // Main loop from GLUT
    return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '\x1B': // If pressing escap then exit.
        exit(EXIT_SUCCESS);
        break;
    case 's': // If pressing "s" then generate the picture or ar-codes.
        PokePicReverser();
        break;
    case 't': // If pressing "t" then 2 working AR codes are displayed.
        TestPic();
        break;
    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen.

    glBegin(GL_POLYGON); // Create a colorfull screen.
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
    int a = 0; // This variable is the running number.
    ShowPokePic(); // Used here to clear the screen.
    while(!(PokePic[4 * 4 + 1] == 1.0f))
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
    int z = 0;
    for(int y = 1; y < 5; y++)
    {
        for(int x = 1; x < 5; x++)
        {
            glBegin(GL_POLYGON);
            glColor3f(PokePic[z], PokePic[z], PokePic[z]);
            glVertex2f(PokeBit(x, 0), PokeBit(y, 1));
            glVertex2f(PokeBit(x + 1, 0), PokeBit(y, 1));
            glVertex2f(PokeBit(x + 1, 0), PokeBit(y + 1, 1));
            glVertex2f(PokeBit(x, 0), PokeBit(y + 1, 1));
            glEnd();
            z++;
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

void TestPic()
{
    PokePic = {1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f};
    ShowPokePic();
    PokePic = {1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f};
    ShowPokePic();
}

