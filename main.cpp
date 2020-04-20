/*
Stefan Florin si Pirvu Catalin - grupa 354
Simularea unei depasiri in trafic
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

const static  double PI = 3.141592654;

static int frame = 0;

double posX1, posY1, viteza1 = 5, depasire1, dim1;
double posX2, posY2, viteza2 = 3.75;
int culoare1 = rand() % 5 , culoare2 = rand() % 5;
bool gamePaused = false;

void desenazaCerc(double raza) {

	glBegin(GL_POLYGON);
	for (int d = 0; d < 32; d++) {
		double unghi = 2*PI/32 * d;
		glVertex2d( raza*cos(unghi), raza*sin(unghi));
	}
	glEnd();
}

void Roata() {

	glColor3f(0,0,0);
	desenazaCerc(1);
	glColor3f(0.75f, 0.75f, 0.75f);
	desenazaCerc(0.8);
	glColor3f(0,0,0);
	desenazaCerc(0.2);

	glRotatef(frame*20,0,0,1);
	glBegin(GL_LINES);
	for (int i = 0; i < 15; i++) {
		glVertex2f(0,0);
		glVertex2d(cos(i*2*PI/15), sin(i*2*PI/15));
	}

	glEnd();
}

void Masina(int df)
{
	glPushMatrix();
	glTranslatef(-1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	Roata();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.1f, 0);
	glScalef(0.8f,0.8f,1);
	Roata();
	glPopMatrix();

    if (df == 0) //culoare random
        glColor3f(0.0,0.9,0.1);
	if(df == 1) //culoarea albastru
        glColor3f(0.1,0.0,0.3);
	if (df == 2) //culoare galben
        glColor3f(1,1,0);
    if (df == 3) //culoare rosu
        glColor3f(0.8,0.0,0.1);
    if (df == 4) //culoare random
        glColor3f(1.0,1.0,1.0);

	glBegin(GL_POLYGON);
	glVertex2f(-4.5f,0);
	glVertex2f(4.5f,0);
	glVertex2f(4.5f,1.5);
	glVertex2f(2.5f,2);
	glVertex2f(1.4f,3.5);
	glVertex2f(-2.2f,3.5);
	glVertex2f(-1.8f,2);
	glVertex2f(-4.5f,1.3);
	glEnd();

	glColor3f(0.3f, 0.5f, 1);
	glBegin(GL_POLYGON);
	glVertex2f(1.2f,3.25);
	glVertex2f(-0.2f,3.25);
	glVertex2f(-0.2,2.25);
	glVertex2f(1.2f,2.25);
	glEnd();

	glColor3f(0.3f, 0.5f, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-2.2f,3.25);
	glVertex2f(-0.8f,3.25);
	glVertex2f(-0.8,2.25);
	glVertex2f(-2.2f,2.25);
	glEnd();

}


void  display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//copaci
	glColor3f(0, 0.6f, 0.2f);
	glBegin(GL_POLYGON);
	glVertex2f(-6,-1);
	glVertex2f(1.5f,2.1f);
	glVertex2f(5,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(3,2.1f);
	glVertex2f(10,-1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0,-1);
	glVertex2f(6,2.1f);
	glVertex2f(10,-1);
	glEnd();
	//copaci

	//pamant
	glColor3f(1,0.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(-20,-1);
	glVertex2f(6,0);
	glVertex2f(20,-1);
	glEnd();
	//pamant


	//sosea
	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.4f);
	glVertex2f(7,-0.4f);
	glVertex2f(7,0.4f);
	glVertex2f(0,0.4f);
	glEnd();

	glLineWidth(6);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(1.5,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(2.5,0);
	glVertex2f(4.0,0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(5.0,0);
	glVertex2f(6.5,0);
	glEnd();
	glLineWidth(1);
	//sosea

	//Masina care depaseste
	glPushMatrix();

	if ((frame%300) >= 100 & (frame%300) <= 125)
        { depasire1 += 0.02; viteza1 += 0.03; dim1 += 0.001;}

    if ((frame%300) >= 150 & (frame%300) <= 180)
        { depasire1 -= 0.01666; viteza1 += 0.035; dim1 -= 0.001; }

    if ((frame%300) == 1)
        {viteza1 = 5; posY1 = -0.07; dim1 = 0;}

	posX1 = -4 + viteza1*(frame % 300) / 130.0;
	posY1 = -0.07;

	glTranslated(posX1, posY1 + depasire1, 0);
	glScaled(0.2 - dim1, 0.2 - dim1, 1);
	Masina(culoare1);
	glPopMatrix();

    //masina depasita
	glPushMatrix();


	if ((frame%300) >= 100 & (frame%300) <= 125)
         viteza2 -= 0.0175;

    if ((frame%300) >= 200 & (frame%300) <= 280)
        viteza2 += 0.015;

    if ((frame%300) == 1)
    viteza2 = 3.75;

	posX2 = -1 + viteza2*(frame % 300) / 130.0;
	posY2 = -0.20;

	glTranslated(posX2, posY2, 0);
	glScaled(0.2,0.2,1);
	Masina(culoare2);
	glPopMatrix();

	//Masina


	glutSwapBuffers();
}

void doFrame(int v) {

    if (gamePaused == false)
        frame++;

    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

void processSpecialKeys(unsigned char key, int x, int y)
{
    if(key == 'x' || key == 'X')
        exit(0);

    if (key == 32 && !((frame%300) >= 100  && (frame%300) <= 180)) //spacebar
        if (gamePaused == false)
            gamePaused = true;
        else gamePaused =  false;

}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            culoare1 = rand() % 6;

         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            culoare2 = rand() % 6;
         break;
      default:
         break;
   }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Proiect 1 - Stefan Florin si Pirvu Catain 354");
    glClearColor(0.2, 0.2, 0.8, 0.5); //culoarea cerului
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 7, -1, 4, -1, 1);


    glutDisplayFunc(display);
    glutTimerFunc(200,doFrame,0);
	glutKeyboardFunc(processSpecialKeys);
	glutMouseFunc(mouse);
    glutMainLoop();

    return 0;
}

