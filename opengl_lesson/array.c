#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <GL/glut.h>

#define TITLE "array"
#define WIDTH 320
#define HEIGHT 240

#define N 20000

enum{
	DRAW_TYPE_NORMAL,
	DRAW_TYPE_DISPLAY_LIST,
	DRAW_TYPE_DISPLAY_LIST2,
	DRAW_TYPE_ARRAY,
	DRAW_TYPE_ARRAY2,
};

float getRandom(void);
void drawNorma(void);
void drawDisplayListInit(void);
void drawDisplayList(void);
void drawArrayInit(void);
void drawArray(void);
void display(void);
void setOrtho(int w, int h);
void reshape(int w, int h);
void key(unsigned char key, int x, int y);
void init(void);

GLfloat color[N*3][3];
GLfloat vertex[N*3][3];
GLuint triangleIndex[N][3];
int drawn = 0;
int drawType = 0;


float getRandom(void)
{
	float v;

	v = (float)rand()/RAND_MAX;

	if(v < 0.5) v = (float)rand()/RAND_MAX;
	else v = -(float)rand()/RAND_MAX;

	return v;
}


void drawNormal(void)
{
	int i, j;
	float r, g, b;
	float x, y;

	for(i = 0; i < N; i++){
		glBegin(GL_TRIANGLES);
		for(j = 0; j < 3; j++){
			r = fabs(getRandom());
			g = fabs(getRandom());
			b = fabs(getRandom());
			glColor3f(r, g, b);
			x = getRandom();
			y = getRandom();
			glVertex2f(x, y);
		}
		glEnd();
	}
}


void drawDisplayListInit(void)
{
	glNewList(1, GL_COMPILE);
	drawNormal();
	glEndList();
}


void drawDisplayList(void)
{
	glCallList(1);
}


void drawArrayInit(void)
{
	int i;

	for(i = 0; i < N*3; i++){
		color[i][0] = fabs(getRandom());
		color[i][1] = fabs(getRandom());
		color[i][2] = fabs(getRandom());
	}

	for(i = 0; i < N*3; i++){
		vertex[i][0] = getRandom();
		vertex[i][1] = getRandom();
		vertex[i][2] = 0.;
	}

	glColorPointer(3, GL_FLOAT, 0, color);
	glVertexPointer(3, GL_FLOAT, 0, vertex);

	for(i = 0; i < N; i++){
		triangleIndex[i][0] = 3*i;
		triangleIndex[i][1] = 3*i + 1;
		triangleIndex[i][2] = 3*i + 2;
	}
}


void drawArray(void)
{
	glDrawElements(GL_TRIANGLES, N*3, GL_UNSIGNED_INT, triangleIndex);
}


void display(void)
{
	clock_t s, e;

	if(!drawn){
		glClear(GL_COLOR_BUFFER_BIT);

		printf("Drawing...\n");

		switch(drawType){
		case DRAW_TYPE_DISPLAY_LIST2:
			printf("Initialize display list\n");
			drawDisplayListInit();
			break;
		case DRAW_TYPE_ARRAY2:
			printf("Initialize array\n");
			drawArrayInit();
			break;
		default:
			break;
		}


		s = clock();

		switch(drawType){
		case DRAW_TYPE_NORMAL:
			printf("Draw Type: Normal\n");
			drawNormal();
			break;
		case DRAW_TYPE_DISPLAY_LIST:
			printf("Draw Type: Display List\n");
			drawDisplayListInit();
			drawDisplayList();
			break;
		case DRAW_TYPE_DISPLAY_LIST2:
			printf("Draw Type: Display List Without Initialize\n");
			drawDisplayList();
			break;
		case DRAW_TYPE_ARRAY:
			printf("Draw Type: Array\n");
			drawArrayInit();
			drawArray();
			break;
		case DRAW_TYPE_ARRAY2:
			printf("Draw Type: Array Without Initialize\n");
			drawArray();
			break;
		default:
			assert(0);
			break;
		}

		e = clock();

		printf("Done.\n");

		printf("%.2f s\n", (float)(e - s)/CLOCKS_PER_SEC);

		drawn = 1;
	}

	glutSwapBuffers();
}


void setOrtho(int w, int h)
{
	float aspect;

	if(w > h){
		aspect = (float)w/h;
		gluOrtho2D(-aspect, aspect, -1., 1.);
	}else{
		aspect = (float)h/w;
		gluOrtho2D(-1., 1., -aspect, aspect);
	}
}


void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glLoadIdentity();
	setOrtho(w, h);

	display();
}


void key(unsigned char key, int x, int y)
{
	int num;

	num = key - '0' - 1;

	switch(num){
	case DRAW_TYPE_NORMAL:
		drawn = 0;
		drawType = DRAW_TYPE_NORMAL;
		glutPostRedisplay();
		break;
	case DRAW_TYPE_DISPLAY_LIST:
		drawn = 0;
		drawType = DRAW_TYPE_DISPLAY_LIST;
		glutPostRedisplay();
		break;
	case DRAW_TYPE_DISPLAY_LIST2:
		drawn = 0;
		drawType = DRAW_TYPE_DISPLAY_LIST2;
		glutPostRedisplay();
		break;
	case DRAW_TYPE_ARRAY:
		drawn = 0;
		drawType = DRAW_TYPE_ARRAY;
		glutPostRedisplay();
		break;
	case DRAW_TYPE_ARRAY2:
		drawn = 0;
		drawType = DRAW_TYPE_ARRAY2;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}


void init(void)
{
	glClearColor(1., 1., 1., 1.);

	srand(time(NULL));

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	drawn = 1;
}


int main(int argc, char* argv[])
{
	int w, h;

	glutInit(&argc, argv);

	w = glutGet(GLUT_SCREEN_WIDTH);
	h = glutGet(GLUT_SCREEN_HEIGHT);

	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition((w - WIDTH)/2, (h - HEIGHT)/2);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutCreateWindow(TITLE);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);

	init();

	printf("Press Key\n");
	printf("%d: Normal\n", DRAW_TYPE_NORMAL+1);
	printf("%d: Display List\n", DRAW_TYPE_DISPLAY_LIST+1);
	printf("%d: Display List Without Initialize\n", DRAW_TYPE_DISPLAY_LIST2+1);
	printf("%d: Array\n", DRAW_TYPE_ARRAY+1);
	printf("%d: Array Without Initialize\n", DRAW_TYPE_ARRAY2+1);

	glutMainLoop();

	return 0;
}
