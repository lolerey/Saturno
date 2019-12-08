#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>

GLfloat rotA=0,rot1=0,rot2=0,rot3=0,rot4=0,rot5=0,rot6=0,rot7=0,rot8=0;
GLfloat rdS=30,rd1=6,rd2=12,rd3=9,rd4=6,rd5=18,rd6=15,rd7=12,rd8=12;
GLfloat posx=0,posz=0;


{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);//matriz de proyeccion
    glLoadIdentity();//cargamos la matriz identidad
    glOrtho(-300,300,-300,300,-300,300);
    glMatrixMode(GL_MODELVIEW);//matriz de modelado
    glLoadIdentity();//matriz identidad
    glEnable(GL_DEPTH_TEST);//activamos el Test de profundidad
    glDepthFunc(GL_LEQUAL);//funcion de borrrado buffer depth

}
void saturno()
{
     glColor3f(1.0,1.0,0.0);
     glutSolidSphere(rdS,60,60);
}
void anillos()
{
     glColor3f(1,0.6,0);
     glRotatef(1,0.4,1,0);
     glutSolidTorus(6, 45, 80,80);
}
void luna1()
{
     glColor3f(0.4,0.4,0.4);
     glutSolidSphere(rd1,60,60);
}
void luna2()
{
     glColor3f(1.0,0.2,0.0);
     glutSolidSphere(rd2,60,60);
}
void luna3()
{
     glColor3f(0.0,0.4,1.0);
     glutSolidSphere(rd3,60,60);
}
void luna4()
{
     glColor3f(0.2,0.4,0.3);
     glutSolidSphere(rd4,60,60);
}
void luna5()
{
     glColor3f(0.2,0.2,0.2);
     glutSolidSphere(rd5,60,60);
}
void luna6()
{
     glColor3f(1.0,0.4,0.0);
     glutSolidSphere(rd6,60,60);
}
//----------------------------------//
void luna7()
{
     glColor3f(0.2,1.0,0.2);
     glutSolidSphere(rd7,60,60);
}

//----------------------------------//
void luna8()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd8,60,60);
}

void display()
{
void resize(int width, int height)
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     //gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
     saturno();
     anillos();

     glPushMatrix();
     glRotatef(rot1,0,1,0);
     glTranslatef(-40,0,0);
     luna1();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot2,0,1,0);
     glTranslatef(60,0,0);
     luna2();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot3,0,1,0);
     glTranslatef(0,0,-80);
     luna3();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot4,0,1,0);
     glTranslatef(100,0,0);
     luna4();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot5,0,1,0);
     glTranslatef(-120,0,0);
     luna5();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot6,0,1,0);
     glTranslatef(0,0,160);
     luna6();
     glPopMatrix();


     glPushMatrix();
     glRotatef(rot7,0,1,0);
     glTranslatef(-170,0,0);
     luna7();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot8,0,1,0);
     glTranslatef(190,0,0);
     luna8();
     glPopMatrix();

     rotA=rotA+0.03;
     rot1=rot1+0.1;
     rot2=rot2+0.015;
     rot3=rot3+0.013;
     rot4=rot4+0.05;
     rot5=rot5+0.04;
     rot6=rot6+0.03;
     rot7=rot7+0.02;
     rot8=rot8+0.01;

     glutSwapBuffers();
}

void key(unsigned char key, int x, int y)
{
    switch(key)
    {
          case 27 :
            exit(0);
            break;
        default:
            break;
    }

glutPostRedisplay();
}


void idle()
{
    glutPostRedisplay();
}
int main (int argc, char *argv[])
{
    glutInit(&argc, argv);//inicializacion del glut
    glutInitWindowSize(800,600);//tamaño de la ventana
    glutInitWindowPosition(400,100);//posicion de la ventana en el monitor
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//modo de visualizacion inicial
    glutCreateWindow("SISTEMA PLANETARIO SOLAR");//nombre de la ventana
    glClearColor(0,0,0,0);//especificar valores claros para el color del buffer
    glutReshapeFunc(resize);//control de ventanas
    glutDisplayFunc(display);//establece la devolución de llamada de visualización de la ventana actual
    glutKeyboardFunc(key);//funcion teclado especial
    glutFullScreen();
    glutIdleFunc(idle);//funcion de animacion

   // char soundfile[20] ="C:\planeta.wav";//sonido
    //PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );//sonido

    glutMainLoop();//bucle de procesamiento de eventos de GLUT
    return 0;
}
