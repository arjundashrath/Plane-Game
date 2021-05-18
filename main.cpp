/*#############################################################
###############################################################
################ CG MINI PROJECT ##############################

MADE BY: ARJUN DASHRATH 3210, ABHAY GODARA 3201

CLASS: SE COMP "A"

ENJOY THE GAME!!!*/


#include<windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
#define rad (3.1416/180)
#define EN_SIZE 20
#include"environment.h"
#include"plane.h"

using namespace std;

double score = 0;

int lookplane = 0;

int n = 1;

float camZoom= 4;

float transX = 0,transY = 0,rotZ = -8,rX=0,rY=0,rZ=4;

float transZ1=-20,transZ2=-40,transZ3=-60,transZ4=-80,transZ5=-100,transZ6=-120;

float rotX=0,rotY=0,rorotZ=0;

float speed = 0.3;

float angleBackFrac = 0.2;

int TIME=0;

bool START = false;

bool gameover = false;

bool rot = false;


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;
                                                               //PlANE
    if(rotX>11)rotX=11;
    if(rotX<-11)rotX=-11;
    if(rorotZ>10)rorotZ=10;
    if(rorotZ<-15)rorotZ=-15;

    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rorotZ,0,0,1);

        glScaled(0.4,0.4,0.4);
        plane();
    glPopMatrix();

                                                               //ENVIRONMENT
    if(transX>=4.1)transX=4.1;
    if(transX<=-4.1)transX=-4.1;
    if(transY>0.1)transY= 0.1;
    if(transY<-15)transY= -15;

   glPushMatrix();
        n = 2;
        glTranslated(transX,transY,rotZ);
        environment(n);
        if(rotZ>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }
    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ1);
        monumentEnv();
    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ2);
        n= 3;
        environment(n);
          if(transZ2>=0)
    if(transZ2>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }


    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ3);
        n = 1;
        environment(n);

        if(transZ3>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }
    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ4);
        n = 5;
        environment(n);
        if(transZ4>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }
    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ5);
        n = 4;
        environment(n);
        if(transZ5>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }
    glPopMatrix();

    glPushMatrix();
        glTranslated(transX,transY,transZ6);
        environment(2);
        if(transZ6>=0)
    {
        if(transX >= (-1*spherePosX[n])-1 && transX<=(-1*spherePosX[n])+0.5 && transY>=(-1*spherePosY[n]) &&transY<=(-1*spherePosY[n])+2)
        {
            gameover = true;
        }

    }
    glPopMatrix();

    rotZ+=speed;
    transZ1+=speed;
    transZ2+=speed;
    transZ3+=speed;
    transZ4+=speed;
    transZ5+=speed;
    transZ6+=speed;

    if(rotZ>=20)rotZ=-110;
    if(transZ1>=20)transZ1=-110;
    if(transZ2>=20)transZ2=-110;
    if(transZ3>=20)transZ3=-110;
    if(transZ4>=20)transZ4=-110;
    if(transZ5>=20)transZ5=-110;
    if(transZ6>=20)transZ6=-110;

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rorotZ>0)rorotZ-=angleBackFrac;
    if(rorotZ<0)rorotZ+=angleBackFrac;

    speed += 0.0002;
    if(speed>=0.7)speed=0.7;

    score += 0.01;
}


void drawBitmapText(char *str,float x,float y,float z)
{
	char *c;
	glRasterPos3f(x,y+8,z);

	for (c=str; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
	}
}

void drawStrokeText(char* str,float x,float y,float z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.002f,0.002f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}

void drawStrokeText2(char* str,float x,float y,float z)
{
	  char *c;
	  glPushMatrix();
	  glTranslatef(x, y+8,z);
	  glScalef(0.005f,0.005f,z);

	  for (c=str; *c != '\0'; c++)
	  {
    		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	  }
	  glPopMatrix();
}
void drawStrokeChar(char c,float x,float y,float z)
{
	  glPushMatrix();
          glTranslatef(x, y+8,z);
          glScalef(0.002f,0.002f,z);
          glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
	  glPopMatrix();
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    if(!rot){
        a=0;
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(	0.0, 4.5, 10.0,
                0, 4, 0,
                0, 1.0f, 0.0f);

    if(START&&gameover==false){


       glPushMatrix();
            glTranslated(0,0,0);
            glScaled(camZoom,camZoom,camZoom);
            glRotated(a,0,1,0);
            draw();
        glPopMatrix();

        drawStrokeText("UP: W, DOWN: S, LEFT: A, RIGHT: D, MAIN MENU: M",-5,0,0);
        drawStrokeText("TIME : ",3,0,0);
        int mod,number=0;
        while(TIME){
            mod=TIME%10;
            number=number*10+mod;
            TIME/=10;
        }
        float tmp=0;
        while(number){
            mod=number%10;
            drawStrokeChar(mod+48,4+tmp,0,0);
            number/=10;
            tmp+=0.2;
        }
    }
    else if(START && gameover==true)
    {
        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(lookplane*3,0,1,0);
            glScaled(1.5,1.5,1.5);
            plane();
        glPopMatrix();
        drawStrokeText2("GAME OVER",-2,0,0);
        drawStrokeText("Press G to Play Again or M to go back to the Menu",-3.6,-1,0);
        string str = "SCORE: " + to_string(score);
        char *cstr = &str[0];
        drawStrokeText(cstr,-1.2,-3,0);

    }
    else{

        glPushMatrix();
            glTranslated(0,3,0);
            glRotated(lookplane*3,0,1,0);
            glScaled(1.5,1.5,1.5);
            plane();
        glPopMatrix();

        drawStrokeText("Press G to Start",-1,-1,0);
        drawStrokeText("MADE BY ARJUN 3210 AND ABHAY 3201",-2.5,-2,0);
        drawStrokeText2("CG MINI PROJECT",-2.5,0,0);
        drawStrokeText("USE A AND D KEYS TO VIEW PLANE",-2.5,-8,0);
        drawStrokeText("SELECT 1, 2, 3 DIFFICULY LEVEL",-2,-9,0);
    }

    glutSwapBuffers();
}


static void keyboard(unsigned char key, int x, int y)
{
    float frac = 0.1;
    float rotFrac = 1;
    switch (key)
    {
        case 'q':
            exit(0);
            break;
        case 'r':
            rot=true;
            break;
        case 't':
            rot=false;
            break;
        case 'w':
            transY-=frac;
            rorotZ+=rotFrac;
            break;
        case 's':
            transY+=frac;
            rorotZ-=rotFrac;
            break;
        case 'a':
            transX+=frac;
            rotX-=rotFrac*3;
            rotY+=rotFrac/2;
            lookplane--;
            break;
        case 'd':
            transX-=frac;
            rotX+=rotFrac*3;
            rotY-=rotFrac/2;
            lookplane++;
            break;
        case '1':
            speed = 1 * 0.3;
            break;
        case '2':
            speed = 2 * 0.3;
            break;
        case '3':
            speed = 3 * 0.5;
            break;
        case 'g':
            START=true;
            gameover = false;
            score = 0;
            transX=0,transY=0,rotZ=-8,rX=0,rY=0,rZ=4;
            break;
        case 'm':
            START=false;
            break;
    }

    glutPostRedisplay();
}

static void idle(void)
{

    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);

	glutInitWindowSize(1366,720);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("GG MINI PROJECT");

    glutReshapeFunc(resize);

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutIdleFunc(idle);

    PlaySound("avengers.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);

    glClearColor(0.79,0.91,0.97,1);

    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return 0;
}
