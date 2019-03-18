#include <iostream>
#include<windows.h>
#include <gl/freeglut.h>

using namespace std;
double ok = 1;
double j = 0.0;
double i = 0.0;
double contor = 0;
double rotire = 0.0;
double loc_vert = 800;
int multime[3] = { 0, 160, 320 };
double inaltime = multime[rand() % 3];
int score = 0;
double time = 0.5;
int pct = 1000;
double rsj, rdj, rss, rds = 0;
void init(void)
{
	glClearColor(0.8, 0.8, 0.8, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);

}

void startgame(void)
{
	
	if ( inaltime != j || (loc_vert>90 || loc_vert <-90))
	{

		if (i < -380)
		{
			i = 0;
		}
		i = i - 2 * time;

		loc_vert -= time;

		if (loc_vert < -150)
		{
			score += 100;
			inaltime = multime[rand() % 3];
			cout << score <<endl;
			loc_vert = 800;
		}

		if (score >= pct && pct <= 15000)
		{
			time += 0.1;
			pct += 1000;
		}

		glutPostRedisplay();
	}
	else {
		ok = 0;
		}
}

void deseneazaScena(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//background-color
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_POLYGON);
	glVertex2i(-100, -140);
	glVertex2i(700, -140);
	glVertex2i(700, -80);
	glVertex2i(-100, -80);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(-100, 400);
	glVertex2i(700, 400);
	glVertex2i(700, 460);
	glVertex2i(-100, 460);
	glEnd();

	// delimitare sosea
	glLineWidth(3);
	glColor3f(1, 1, 1);

	// linii drepte
	glBegin(GL_LINES);
	glVertex2i(-100, -80);
	glVertex2i(1500, -80);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(-100, 400);
	glVertex2i(1500, 400);
	glEnd();

	//linii intrerupte
	glPushMatrix();
	glTranslated(i, 0.0, 0.0);
	glLineStipple(8, 0x00FF);
	glEnable(GL_LINE_STIPPLE);

	glBegin(GL_LINES);
	glVertex2i(-100, 80);
	glVertex2i(1500, 80);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(-100, 240);
	glVertex2i(1500, 240);
	glEnd();
	glPopMatrix();
	
	glDisable(GL_LINE_STIPPLE);

	// masina principala
	glPushMatrix();
	glTranslated(0.0, j, 0.0);
	
	glPushMatrix();
	glRotated(rotire, 0.0, 0.0, 1.0);

	glColor3f(1.0, 0.0, 0.0);
	glRecti(-45, -15, 45, 15);

	if (ok == 0)
	{
		rsj = 8;
		rss = -8;
		rdj = -8;
		rds = 8;
	}

	glColor3f(1.0, 1.0, 0.0);
	glRecti(40, -10, 45, -15);
	
	glColor3f(1.0, 1.0, 0.0);
	glRecti(40, 10, 45, 15);

	glPushMatrix();
	glRotated(rsj, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(-30, -30, -15, -15);
	glPopMatrix();

	glPushMatrix();
	glRotated(rss, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(-30, 15, -15, 30);
	glPopMatrix();

	glPushMatrix();
	glRotated(rds, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(15, 15, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotated(rdj, 0.0, 0.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRecti(15, -30, 30, -15);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

	if (contor == 1 && (j != 160 && j != 320))
		j = j + 1;
	else if (contor == -1 && (j != 160 && j != 0))
		j = j - 1;
	else {
		contor = 0;
		rotire = 0.0;
	}

	//masina inamica

	glPushMatrix();
	glTranslated(loc_vert, inaltime, 0.0);

	glColor3f(0.3, 0.3, 1.0);
	glRecti(-45, -15, 45, 15);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(40, -10, 45, -15);

	glColor3f(1.0, 1.0, 0.0);
	glRecti(40, 10, 45, 15);

	glColor3f(0.0, 0.0, 0.0);
	glRecti(-30, -30, -15, -15);

	glColor3f(0.0, 0.0, 0.0);
	glRecti(-30, 15, -15, 30);

	glColor3f(0.0, 0.0, 0.0);
	glRecti(15, 15, 30, 30);

	glColor3f(0.0, 0.0, 0.0);
	glRecti(15, -30, 30, -15);

	glPopMatrix();

	startgame();
	glutPostRedisplay();
	glutSwapBuffers();
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 700.0, -140.0, 460.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void miscasus(void)
{
	if (ok != 0)
	{
		if (j < 320)
		{
			contor = 1;
			j += 1;
			rotire = 10;
		}

		glutPostRedisplay();
	}
}

void miscajos(void)
{
	if (ok != 0)
	{
		if (j > 0)
		{
			contor = -1;
			j -= 1;
			rotire = -10;

		}

		glutPostRedisplay();
	}
}

void keyboard(int key, int x, int y)
{
	

	switch (key) {
	case GLUT_KEY_UP:
		miscasus();
		break;
	case GLUT_KEY_DOWN:
		miscajos();
		break;

	}
	
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Fereste-te de masini si depaseste-le.");
	init();
	glutDisplayFunc(deseneazaScena);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}