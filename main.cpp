/*
 * GLUT Shapes Demo
 *
 * Written by Richard Sung November 2015
 *
 *
 */
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <GL\glut.h>
#include <math.h>

/*----------------------------------------------------------------------*/
using namespace std;

vector<float> vect;
vector<float> vectmirror;

GLfloat xRotated, yRotated, zRotated, xMove, yMove, zMove, xpos, ypos, zpos;


int xArray=22, zArray=22, yArray=22;


int	winWidth = 1000, winHeight = 700;
int cubenumber[45][2025];

//Struct
struct cubecolor{

    float r;
    float g;
    float b;

};

cubecolor now    = { 1.0f , 1.0f , 1.0f };
cubecolor prenow = { 0.5f , 0.5f , 0.5f };

cubecolor becomeYellow()
{
    cubecolor temp = { 1.0f , 1.0f , 0.0f };
    return temp;
}

cubecolor becomeRed()
{
    cubecolor temp = { 1.0f , 0.0f , 0.0f };
    return temp;
}

cubecolor becomeBlue()
{
    cubecolor temp = { 0.0f , 0.0f , 1.0f };
    return temp;
}

cubecolor becomeGreen()
{
    cubecolor temp = { 0.0f , 1.0f , 0.0f };
    return temp;
}

cubecolor becomeOrange()
{
    cubecolor temp = { 1.0f , 0.5f , 0.0f };
    return temp;
}

cubecolor becomeWhite()
{
    cubecolor temp = { 1.0f , 1.0f , 1.0f };
    return temp;
}



void myKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'w':
            /* go up */
            yMove+=0.4;
            yArray+=1;
            break;
        case 's':
            /* go down */
            yMove-=0.4;
            yArray-=1;
            break;
        case 'a':
            /* go left */
            xMove-=0.4;
            xArray-=1;
            break;
        case 'd':
            /* go right */
            xMove+=0.4;
            xArray+=1;
            break;

        case 'q':
            /* go farther */
            zMove-=0.4;
            zArray-=1;
            break;

        case 'e':
            /* come closer */
            zMove+=0.4;
            zArray+=1;
            break;

        case 'r':
            /* return */
            xMove=yMove=zMove=0.0;
            break;

        case 'u':
            /* draw */
            //vect.push_back(draw);
            vect.push_back(xMove);
            vect.push_back(yMove);
            vect.push_back(zMove);

            vect.push_back(now.r);
            vect.push_back(now.g);
            vect.push_back(now.b);
            /*xpos=xMove;
             ypos=yMove;
             zpos=zMove;*/

            break;

        case 'j':
            /* return */
            yRotated-=0.1;
            break;
        case 'k':
            /* return */
            yRotated=0.0;
            zRotated=0.0;
            break;
        case 'l':
            /*  */
            yRotated+=0.1;
            break;
        case 'i':
            /*  */
            zRotated-=0.1;
            break;
        case ',':
            /*  */
            zRotated+=0.1;
            break;
        case 'c':
            /*  */
            vect.clear();
            yRotated=0.0;
            zRotated=0.0;
            xMove=yMove=zMove=0.0;
            break;

        case '1':
            now = becomeRed();
            break;

        case '2':
            now = becomeOrange();
            break;

        case '3':
            now = becomeYellow();
            break;

        case '4':
            now = becomeGreen();
            break;

        case '5':
            now = becomeBlue();
            break;

        case '6':
            now = becomeWhite();
            break;
    }
    glutPostRedisplay();
}

void backgroundColor(void)
{
    glClearColor(0.7,0.7,0.7,0);
}

void CubeOrigin(void)
{
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Bottom Right Of The Quad (Top)
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Front)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Front)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Front)
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Top Right Of The Quad (Back)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Top Left Of The Quad (Back)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Bottom Right Of The Quad (Back)
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Left)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Left)
    glColor3f(1.0f,0.0f,0.0f);    // Color red
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Right)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Right)
}

void CubeIndex(void)
{
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Bottom Right Of The Quad (Top)
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Bottom)
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Front)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Front)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Front)
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Top Right Of The Quad (Back)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Top Left Of The Quad (Back)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Left)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Left)
    glColor3f(0.0f,0.0f,0.0f);    // Color white
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Right)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Right)
}

void Cube2(struct cubecolor cube2)
{
    glColor3f( cube2.r , cube2.g , cube2.b );    // Color now
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Top)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Bottom Left Of The Quad (Top)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Bottom Right Of The Quad (Top)
    glColor3f( cube2.r , cube2.g , cube2.b );    // Color now
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Bottom)
    glColor3f( cube2.r , cube2.g , cube2.b );   // Color now
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Front)
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Front)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Front)
    glColor3f( cube2.r , cube2.g , cube2.b );    // Color now
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Top Right Of The Quad (Back)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Top Left Of The Quad (Back)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Bottom Right Of The Quad (Back)
    glColor3f( cube2.r , cube2.g , cube2.b );   // Color now
    glVertex3f(-0.2f, 0.2f, 0.2f);    // Top Right Of The Quad (Left)
    glVertex3f(-0.2f, 0.2f,-0.2f);    // Top Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f,-0.2f);    // Bottom Left Of The Quad (Left)
    glVertex3f(-0.2f,-0.2f, 0.2f);    // Bottom Right Of The Quad (Left)
    glColor3f( cube2.r , cube2.g , cube2.b );   // Color now
    glVertex3f( 0.2f, 0.2f,-0.2f);    // Top Right Of The Quad (Right)
    glVertex3f( 0.2f, 0.2f, 0.2f);    // Top Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f, 0.2f);    // Bottom Left Of The Quad (Right)
    glVertex3f( 0.2f,-0.2f,-0.2f);    // Bottom Right Of The Quad (Right)
}


void drawOtherCubes(void)
{
    for(int j=0;j<vect.size();j=j+6){
        xpos=vect[j];
        ypos=vect[j+1];
        zpos=vect[j+2];
        glPushMatrix();
        glTranslatef(xpos, ypos, zpos-19.5);//0.0, 0.0, 0.0
        glBegin(GL_QUADS);
        // Draw The Cube Using quads
        prenow = { vect[j+3] , vect[j+4] , vect[j+5] };
        Cube2(prenow);
        glEnd();
        glPopMatrix();
    }
}

void DisplayCube(void)
{
    //glut tuto_2line_down
    /*if (deltaMove)
     computePos(deltaMove);*/

    glMatrixMode(GL_MODELVIEW);

    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	15*sin(yRotated*M_PI*0.125)*cos(zRotated*M_PI*0.125),
              15*sin(zRotated*M_PI*0.125),
              -19.5f+15*cos(yRotated*M_PI*0.125)*cos(zRotated*M_PI*0.125),
              0.0f, 0.0f,  -19.5f,
              0.0f, 1.0f*cos(zRotated*M_PI*0.125),  0.0f);
    // Set the camera ;Gult tuto
    /*gluLookAt(
     x, 1.0f, z,
     x+lx, 1.0f,  z+lz,
     0.0f, 1.0f,  0.0f);
     */
    //global rotate


    // draw the center cube
    glPushMatrix();
    glTranslatef(0.0,0.0,-19.5);//0.0, 0.0, 0.0
    glBegin(GL_QUADS);        //The cube at center of window,the original cube
    CubeOrigin();
    glEnd();
    glPopMatrix();

    drawOtherCubes();

    glTranslatef(xMove,yMove,zMove-19.5);//0.0, 0.0, 0.0
    glRotatef(xRotated,1.0,1.0,0.0);
    /*glRotatef(xRotated,1.0,0.0,0.0);
     // rotation about Y axis
     //glRotatef(yRotated,0.0,1.0,0.0);
     // rotation about Z axis
     //glRotatef(zRotated,0.0,0.0,1.0);*/

    glBegin(GL_QUADS);        // Draw The Cube for Index
    CubeIndex();
    glEnd();            // End Drawing The Cube

    glFlush();
}


void animation(void)
{
    /*
     xRotated += 0.02;
     DisplayCube();
     */
}


void reshape(int x, int y)
{
    if (y == 0)
        y = 1;

    float ratio =  x * 1.0 / y;
    //if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,1.0,40.0);

    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    //we initizlilze the glut. functions
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth,winHeight);
    glutCreateWindow("Cube World");//argv[0]);

    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    backgroundColor();
    glutDisplayFunc(DisplayCube);
    //glutDisplayFunc(DisplayCube2);
    glutKeyboardFunc(myKeys);

    /*
     glutMouseFunc(mouseButton);
     glutMotionFunc(mouseMove);
     */

    glutReshapeFunc(reshape);

    //Set the function for the animation.
    //glutIdleFunc();
    glutIdleFunc(animation);
    glutMainLoop();
    return 0;
}
