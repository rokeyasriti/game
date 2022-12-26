#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position = 0.0f; //FOR TRAINGLE
GLfloat speed = 0.1f;

GLfloat Gposition = 0.0f;   //FOR GUN
GLfloat Gspeed = 0.0f;

GLfloat Bposition = 0.0f;   //FOR BULLET
GLfloat Bspeed = 0.0f;

void update(int value) {

    if(position <- 2.5)
     position = 1.5f;       //FOR TRAINGLE
     position -= speed;


    if(Bposition > 1.5)
    Bposition = 0.0f;        // FOR BULLET
    Bposition += Bspeed;

    if(Gposition > 1.5)
    Gposition = 0.0f;        //FOR GUN RIGHTSHOOT
    Gposition += Gspeed;

    if(Gposition > -1.5)
    Gposition = 0.0f;        //FOR GUN LEFTSHOOT
    Gposition -= Gspeed;


    glutPostRedisplay();

glutTimerFunc(100, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

   case 'D':
    Bposition=0.0;   //FOR SHOOT
    Bspeed = 0.0f;
    break;

   case 'S':
   Bspeed += 0.1f;   //STOP SHOOT
    break;

    case 'L':
   Gspeed += 0.1f;   //GUN RIGHT MOVE
    break;

    case 'R':
   Gspeed -= 0.1f;   //GUN LEFT MOVE
    break;


glutPostRedisplay();


	}
}


void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();

glPushMatrix();
glTranslatef(Gposition,0.0f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, -1.0f);
      glVertex2f( -0.2f, -0.7f);
      glVertex2f( 0.2f,  -0.7f);
      glVertex2f(0.2f,  -1.0f);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(0.2f, -0.8f);
      glVertex2f( 0.25f, -0.8f);
      glVertex2f( 0.25f,  -0.9f);
      glVertex2f(0.2f,  -0.9f);
   glEnd();

   glBegin(GL_QUADS);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.2f, -0.8f);
      glVertex2f( -0.25f, -0.8f);
      glVertex2f( -0.25f,  -0.9f);
      glVertex2f(-0.2f,  -0.9f);
   glEnd();

  glPushMatrix();
  glTranslatef(0.0f,Bposition, 0.0f);

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.1f,-0.7f);
   glVertex2f(0.1f, -0.7f);
   glVertex2f(0.0f, -0.5f);
   glEnd();

   glPopMatrix();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.0f,position, 0.0f);

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2f(0.3f,1.0f);
   glVertex2f(0.7f, 1.0f);
   glVertex2f(0.5f, 0.7f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2f(-0.3f,1.0f);
   glVertex2f(-0.7f, 1.0f);
   glVertex2f(-0.5f, 0.7f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2f(0.0f,1.1f);
   glVertex2f(-0.2f, 1.4f);
   glVertex2f(0.2f, 1.4f);
   glEnd();

   glPopMatrix();
   glFlush();
}



int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(320, 320);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   //glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
