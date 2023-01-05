#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdlib.h>
#include <windows.h>
#include <math.h>

float xRotated = 90.0, yRotated = 0.0, zRotated = 0.0;



//void moon (){
//glColor3f (0.5, 0.5, 0.8);
  //  glPushMatrix ();
    //   glTranslatef    (-0.1, 1.0, 0.0);
      // glRotatef       (60.0, 1,0,0);
      //glRotatef       (zRotated, 0,0,1);

       //glutSolidSphere (0.2, 30, 30);
    //glPopMatrix ();

//}
int x;
int y;
double rotatebykey=0;
 double rotate_x=0.5;
void key (int key,int x,int y){
 if(key==27)
        exit(0);
 if(key==GLUT_KEY_UP)
    rotate_x+=0.04;
        if(key==GLUT_KEY_DOWN)
    rotate_x-=0.04;

glutPostRedisplay();
}
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);

}
void timer(int);
//------------------------------  display   -------------------------------
float _angle = 53.0f;
float _cameraAngle = 0.0f;

float step=0;



void display (void)
{
    glClear        (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    glTranslatef    (0.0, 0.0, -15.0);
    glPushMatrix();
    glColor3f(0,0,0);

glPopMatrix();
     //moon();
      glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex2f(0,0);
    glVertex2f(-5,-5);
    glEnd();

    glFlush();
	//Your code is written here


 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-_cameraAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    glRotatef(_angle, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);
     glClear (GL_COLOR_BUFFER_BIT);

    /*left rec*/
    glColor3f(1.0 ,0.5 ,0.0 );
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glEnd();

    /*right rec*/
    //right
    glColor3f(1.0 ,0.5 ,0.0 );
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.2, 0.575, 0.5);
    glEnd();

    /* left rec */
    glColor3f (0, 1, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.9,0.1,0 );
    glVertex3f (0.2, 0.1, 0.0);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.001, 0.575, 0.5);
    glEnd();

    /* right rec */
    glColor3f (1, 0 ,0);
    glBegin(GL_POLYGON);
    glVertex3f (0.9, 0.1, 0.5);
    glVertex3f (0.9, 0.1, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glEnd();
//he5o be5o 
    /* back tri */
    glColor3f (1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glEnd();

    /* front tri */
    glColor3f (1, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*  left roof */
    glColor3f (1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.0);
    glVertex3f (0.9, 0.575, 0.0);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();

    /*right  roof */
    glColor3f (1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f (0.2, 0.575, 0.5);
    glVertex3f (0.9, 0.575, 0.5);
    glVertex3f (0.9, 0.8, 0.25);
    glVertex3f (0.2, 0.8, 0.25);
    glEnd();


    /* door */
    glColor3f (.15, 0.2, .3);
    glBegin(GL_POLYGON);
    glVertex3f (0.47, 0.105, 0.0);
    glVertex3f (0.65, 0.105, 0.0);
    glVertex3f (0.65, 0.46, 0.0);
    glVertex3f (0.47, 0.46, 0.0);
    glEnd();

    /* window 1 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.72, 0.25, 0.0);
    glVertex3f (0.83, 0.25, 0.0);
    glVertex3f (0.83, 0.4, 0.0);
    glVertex3f (0.72, 0.4, 0.0);
    glEnd();

    /* window 2 */
    glColor3f (.3, 0.2, .1);
    glBegin(GL_POLYGON);
    glVertex3f (0.27, 0.25, 0.0);
    glVertex3f (0.38, 0.25, 0.0);
    glVertex3f (0.38, 0.4, 0.0);
    glVertex3f (0.27, 0.4, 0.0);
    glEnd();
    glColor3f (0.5,0.5,0.5);


     //nose1
      glPushMatrix ();
      glColor3f(1,0,0);
     glTranslated(-0.6,0.6,0);
     glutSolidCone(0.009,0.2,10,10);
    glPopMatrix ();

    //nose2
    glPushMatrix ();
      glColor3f(1,0,0);
     glTranslated(-0.999+step,0.6,0);
     glutSolidCone(0.009,0.2,10,10);
    glPopMatrix ();


//-----------------------------------------------------------------

   //snowman1
   glColor3f(1,1,1);
   glPushMatrix ();
       glTranslatef    (-0.6,0.59, 0.0);
       glutSolidSphere (0.05, 30, 30);
    glPopMatrix ();


    glPushMatrix ();

       glTranslatef    (-0.6,0.44, 0.0);
       glutSolidSphere (0.10, 30, 30);
    glPopMatrix ();



    glPushMatrix ();

       glTranslatef    (-0.6,0.2, 0.0);
       glutSolidSphere (0.15, 30, 30);
    glPopMatrix ();
    //------------------------------------------------------------------------------
//snowman2

     glColor3f (1,1,1);
   glPushMatrix ();
       glTranslatef    (-1.04+step,0.59, 0.0);
       glutSolidSphere (0.05, 30, 30);
    glPopMatrix ();


    glPushMatrix ();

       glTranslatef    (-1.05+step,0.44, 0.0);
       glutSolidSphere (0.10, 30, 30);
    glPopMatrix ();



    glPushMatrix ();

       glTranslatef    (-1.05+step,0.2, 0.0);
       glutSolidSphere (0.15, 30, 30);
    glPopMatrix ();
    //----------------------------------------------------------------
    //moon2
glColor3f (0.5, 0.5, 0.8);
    glPushMatrix ();
       glTranslatef    (-0.1, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.2, 30, 30);
    glPopMatrix ();
//starstar
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.5+step, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//--------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.4+step, 0.7, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//-----------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (0.99+step, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//-----------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (0.7+step, 1.2, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//----------------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.8+step, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//--------------------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.88, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.009, 30, 30);
    glPopMatrix ();
//-------------------------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.7, 1.0, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.0099, 30, 30);
    glPopMatrix ();

    //-------------------------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.55+step, 0.88, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.0099, 30, 30);
    glPopMatrix ();
//-------------------------------------------------------------------------------------
glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.66+step, 0.9, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.0099, 30, 30);
    glPopMatrix ();
    //-------------------------------------------------------------------------------------------
    glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.52+step, 0.9, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.0099, 30, 30);
    glPopMatrix ();
    //--------------------------------------------------------------------------------
     glColor3f (1, 1, 1);
    glPushMatrix ();
       glTranslatef    (-0.44+step, 0.9, 0.0);
       glRotatef       (60.0, 1,0,0);
      glRotatef       (zRotated, 0,0,1);

       glutSolidSphere (0.0099, 30, 30);
    glPopMatrix ();
//-------------------------------------------------------------------------------------
//cloud

     glColor3f (1,1,1);
   glPushMatrix ();
       glTranslatef    (-1.04+step,0.8, 0.0);
       glutSolidSphere (0.05, 30, 30);
    glPopMatrix ();


     glColor3f (1,1,1);
   glPushMatrix ();
       glTranslatef    (-0.99+step,0.8, 0.0);
       glutSolidSphere (0.05, 30, 30);
    glPopMatrix ();


     glColor3f (1,1,1);
   glPushMatrix ();
       glTranslatef    (-1.07+step,0.78, 0.0);
       glutSolidSphere (0.05, 30, 30);
    glPopMatrix ();




// stars
    glPushMatrix ();
glColor3f(1,0,0);

glBegin (GL_POLYGON);
    glVertex3f(0.0,0.8,0);
    glVertex3f(0.1,0.8,0);
    glVertex3f(0.2,0.8,0);
    glVertex3f(0.1,0.8,0);
    glVertex3f(0.2,0.8,0);
    glVertex3f(0.0,0.8,0);
    glVertex3f(-0.2,0.8,0);
    glVertex3f(-0.1,0.8,0);
    glVertex3f(-0.2,0.8,0);
    glVertex3f(-0.1,0.8,0);
    glEnd();

    glPopMatrix ();
    //star2
    glBegin (GL_POLYGON);
    glVertex2f(0.0-step,8.3);
    glVertex2f(0.1-step,8.2);
    glVertex2f(0.2-step,8.06);
    glVertex2f(0.1-step,8.1);
    glVertex2f(0.2-step,8.2);
    glVertex2f(0.0-step,8.05);
    glVertex2f(-0.2-step,8.2);
    glVertex2f(-0.1-step,8.1);
    glVertex2f(-0.2-step,8.06);
    glVertex2f(-0.1-step,8.2);
    glEnd();

    //star3

    glPushMatrix ();
    glBegin (GL_POLYGON);
    glVertex2f(3.0,6.3);
    glVertex2f(3.1,6.2);
    glVertex2f(3.2,6.06);
    glVertex2f(3.1,6.1);
    glVertex2f(3.2,6.2);
    glVertex2f(3.0,6.05);
    glVertex2f(2.8,6.2);
    glVertex2f(2.9,6.1);
    glVertex2f(2.8,6.06);
    glVertex2f(2.9,6.2);
    glEnd();
glPopMatrix();
    //star4
    glBegin (GL_POLYGON);
    glVertex2f(-3.0,6.3);
    glVertex2f(-3.1,6.2);
    glVertex2f(-3.2,6.06);
    glVertex2f(-3.1,6.1);
    glVertex2f(-3.2,6.2);
    glVertex2f(-3.0,6.05);
    glVertex2f(-2.8,6.2);
    glVertex2f(-2.9,6.1);
    glVertex2f(-2.8,6.06);
    glVertex2f(-2.9,6.2);
    glEnd();

    //star5
    glBegin (GL_POLYGON);
    glVertex2f(-3.0,6.3+step);
    glVertex2f(-3.1,6.2+step);
    glVertex2f(-3.2,6.06+step);
    glVertex2f(-3.1,6.1+step);
    glVertex2f(-3.2,6.2+step);
    glVertex2f(-3.0,6.05+step);
    glVertex2f(-2.8,6.2+step);
    glVertex2f(-2.9,6.1+step);
    glVertex2f(-2.8,6.06+step);
    glVertex2f(-2.9,6.2+step);
    glEnd();






    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,15.0f);
        glVertex3f(40.0f,-15.0f,15.0f);
        glVertex3f(40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glVertex3f(-40.0f,0.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,-15.0f);
        glColor3f(1, 1.0, 1.0);
        glVertex3f(40.0f,-15.0f,-15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-40.0f,0.0f,15.0f);
        glVertex3f(-40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,-15.0f);
        glVertex3f(40.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-40.0f,-15.0f,15.0f);
        glVertex3f(-40.0f,-15.0f,-15.0f);
        glVertex3f(40.0f,-15.0f,-15.0f);
        glVertex3f(40.0f,-15.0f,15.0f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-20.0f,0.0f,15.0f);
        glVertex3f(-10.0f,10.0f,15.0f);
        glVertex3f(20.0f,10.0f,15.0f);
        glVertex3f(25.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-20.0f,0.0f,-15.0f);
        glVertex3f(-10.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glVertex3f(25.0f,0.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-10.0f,10.0f,15.0f);
        glVertex3f(-10.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glVertex3f(20.0f,10.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-10.0f,10.0f,15.0f);
        glVertex3f(-20.0f,0.0f,15.0f);
        glVertex3f(-20.0f,0.0f,-15.0f);
        glVertex3f(-10.0f,10.0f,-15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(20.0f,10.0f,15.0f);
        glVertex3f(20.0f,10.0f,-15.0f);
        glVertex3f(25.0f,0.0f,-15.0f);
        glVertex3f(25.0f,0.0f,15.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-30.0f,-15.0f,15.0f);
        glVertex3f(-30.0f,-15.0f,-15.0f);
        glVertex3f(30.0f,-15.0f,-15.0f);
        glVertex3f(30.0f,-15.0f,15.0f);
    glEnd();


    glBegin(GL_3D);
    glColor3f(1, 1, 1);
    glTranslated(-20.0f,-15.0f,15.0f);
    glutSolidTorus(2,5,5,100);



    glTranslated(0.0f,0.0f,-30.0f);
    glutSolidTorus(2,5,5,100);
    glTranslated(45.0f,0.0f,0.0f);
    glutSolidTorus(2,5,5,100);
    glTranslated(0.0f,0.0f,30.0f);
    glutSolidTorus(2,5,5,100);
    glEnd();






    glutSwapBuffers();

}

//--------------------------------  idleFunc  ----------------------------------
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    step+=0.005;}


void idleFunc (void)
{
    zRotated += 0.1;
    glutPostRedisplay();
}

void texture (void){

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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


}

//----------------------------------  main  ------------------------------------


int main (int argc, char **argv)
{
    glutInit               (&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // buffer mode
    glutInitWindowSize     (1600, 1600);
    glutInitWindowPosition (70, 70);
    glutCreateWindow       ("20109594");
    glutSpecialFunc(key);

    glClearColor (1.0, 1.0, 1.0, 0.0);

    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutIdleFunc    (idleFunc);

    glutTimerFunc(1000/60,timer,0);
    glClearColor(0.0f,1.0f,1.0f,1.0f);
    texture(); // Lighting and textures


    glutMainLoop();
}
