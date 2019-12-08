#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<time.h>

using namespace std;


GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;

float scale = 1.0f;


GLfloat rotA,rot1,rot2,rot3,rot4,rot5,rot6,rot7,rot8,rot9,rot10,rot11,rot12,rot13,rot14,rot15,rot16,rot17,rot18,rot19,rot20=0;
GLfloat rdS=30,rd1=4,rd2=6,rd3=5,rd4=3,rd5=10,rd6=12,rd7=6,rd8,rd9,rd10,rd11,rd12,rd13,rd14=6,rd15,rd16,rd17,rd18,rd19,rd20=3;
GLfloat posx=0,posz=0;

void resize(int width, int height)
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

      GLfloat mat_diffuse [] = {0.0, 0.0, 0.0, 1.0};
      GLfloat mat_specular [] = {0.5, 0.5, 0.5, 1.0};
      GLfloat mat_shininess [] = {50};
      GLfloat mat_emission [] = {0.5, 0.2, 0.2, 1.0};
void iluminacion ()
{
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
glLightfv(GL_LIGHT0,GL_POSITION, light_position);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
glEnable (GL_LIGHTING);
glEnable (GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);

}
void saturno()
{
      glColor3f(0.0, 0.5, 0.5);
     glutSolidSphere(rdS,60,60);
}
void anilloA()
{
     glColor3f(0.0, 0.5, 0.5);
     glRotatef(1,0.4,1,0);
     glutSolidTorus(7, 45, 80,80);
}
void anilloB()
{
     glColor3f(0.0, 0.5, 0.5);
     glRotatef(1,0.4,1,0);
     glutSolidTorus(5, 60, 80,80);
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

void luna8()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd8,60,60);
}
void luna9()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd9,60,60);
}
void luna10()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd10,60,60);
}
void luna11()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd11,60,60);
}
void luna12()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd12,60,60);
}
void luna13()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd13,60,60);
}
void luna14()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd14,60,60);
}
void luna15()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd15,60,60);
}
void luna16()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd16,60,60);
}
void luna17()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd17,60,60);
}
void luna18()
{
     glColor3f(0.0,0.0,1.0);
     glutSolidSphere(rd18,60,60);
}
void luna19()
{
     glColor3f(0.0, 1.0, 0.0);
     glutSolidSphere(rd19,60,60);
}
void luna20()
{
     glColor3f(0.0, 1.0, 0.0);
     glutSolidSphere(rd10,60,60);
}
void estrellas()
{
    int i,j,k; srand(time(NULL));
    int h=0;
         glBegin(GL_POINTS);
         while(h<100){
         i=(rand()%300);
         j=(rand()%300);
         k=(rand()%300);
           glColor3f(1,1,1);
           glVertex3f(i,j,k);
           glVertex3f(i,-j,k);
           glColor3f(0,1,0);
           glVertex3f(-i,-j,k);
           glColor3f(0,0,1);
           glVertex3f(-i,j,-k);
           h++;}
    glEnd();

}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     	gluLookAt(0.0 + X, 0.01 - Y, 0.2 + Z, 0.0 + X, 0.0 - Y, 0.0 + Z, 0.0, 2.0, 0.2);
    // gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
     estrellas();
      iluminacion ();
     saturno();
     anilloA();
     anilloB();
     glPushMatrix();
     glRotatef(rot1,0,1,0);
     glTranslatef(-240,0,0);
     luna1();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot2,0,1,0);
     glTranslatef(260,0,0);
     luna2();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot3,0,1,0);
     glTranslatef(0,0,-280);
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
     glTranslatef(-110,0,160);
     luna6();
     glPopMatrix();


     glPushMatrix();
     glRotatef(rot7,0,1,0);
     glTranslatef(-105,0,0);
     luna7();
     glPopMatrix();

     glPushMatrix();
     glRotatef(rot8,0,1,0);
     glTranslatef(-150,0,0);
     luna8();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot9,0,1,0);
     glTranslatef(-160,0,0);
     luna9();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot10,0,1,0);
     glTranslatef(-170,0,0);
     luna10();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot11,0,1,0);
     glTranslatef(-180,0,0);
     luna11();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot12,0,1,0);
     glTranslatef(-200,0,0);
     luna12();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot13,0,1,0);
     glTranslatef(-210,0,0);
     luna13();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot14,0,1,0);
     glTranslatef(-220,0,0);
     luna14();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot15,0,1,0);
     glTranslatef(-230,0,0);
     luna15();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot16,0,1,0);
     glTranslatef(-240,0,0);
     luna16();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot17,0,1,0);
     glTranslatef(250,0,0);
     luna17();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot18,0,1,0);
     glTranslatef(260,0,0);
     luna18();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot19,0,1,0);
     glTranslatef(-270,0,0);
     luna19();
     glPopMatrix();

      glPushMatrix();
     glRotatef(rot20,0,1,0);
     glTranslatef(-280,0,0);
     luna20();
     glPopMatrix();

     rotA=rotA+0.03;
     rot1=rot1+0.1;
     rot2=rot2+0.015;
     rot3=rot3+0.013;
     rot4=rot4+0.05;
     rot5=rot5+0.04;
     rot6=rot6+0.03;
     rot7=rot7+0.02;
     rot8=rot8+0.05;
     rot9=rot9+0.06;
     rot10=rot10+0.1;
     rot11=rot11+0.1;
     rot12=rot12+0.1;
     rot13=rot13+0.05;
     rot14=rot14+0.06;
     rot15=rot15+0.07;
     rot16=rot16+0.08;
     rot17=rot17+0.09;
     rot18=rot18+0.10;
     rot19=rot19+0.11;
     rot20=rot20+0.12;

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

void ArrowKey(int key, int x, int y) {
	//Código
	switch (key) {
	case GLUT_KEY_RIGHT:
		X += 6.0;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(15.0f, (GLfloat)(600 / 600), 0.1f, 1000.0f);
		glRotatef(10, 0, 0, 0);
		glMatrixMode(GL_MODELVIEW);
		break;
		//  Flecha izquierda: disminuir rotación 5 grados
	case GLUT_KEY_LEFT:
			X -= 6.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(15.0f, (GLfloat)(600 / 600), 0.1f, 1000.0f);
			glRotatef(-10, 0, 1, 0);
			glMatrixMode(GL_MODELVIEW);
		break;
	case GLUT_KEY_UP:
		Z -= 6.0;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(105.0f, (GLfloat)(600 / 600), 0.1f, 10000.0f);
		glOrtho(5.0, 5.0, 5.0, 5.0, 0.1, 20.0);
		glMatrixMode(GL_MODELVIEW);
		break;
	case GLUT_KEY_DOWN:
			Z += 6.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(105.0f,(GLfloat)(600/600),0.1f,10000.0f);
			glOrtho(-5.0, 5.0, -5.0, 5.0, 0.1, 20.0);
			glMatrixMode(GL_MODELVIEW);
		break;
	case GLUT_KEY_HOME:
		scale += 0.5;
		break;
	case GLUT_KEY_END:
		scale += -0.5;
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
    glutSpecialFunc(ArrowKey);
    glutFullScreen();
    glutIdleFunc(idle);//funcion de animacion

   // char soundfile[20] ="C:\planeta.wav";//sonido
    //PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );//sonido

    glutMainLoop();//bucle de procesamiento de eventos de GLUT
    return 0;
}
