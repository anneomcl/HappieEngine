#include "Matrix.h"
#include "Vector3D.h"
#include "Math.h"
#include <iostream>
#include <gl/freeglut.h>

#define MAX_SPEED 0.4
#define ACCELERATION 0.1
#define ZOOM_SPEED 0.1

//CAMERA 
Vector3D centerPosition = Vector3D(1.f, 1.f, 1.f);
Vector3D eyePosition = Vector3D(0.f, 0.f, 0.f);
Vector3D upVector = Vector3D(0.f, 0.f, 1.f);

//CUBE
bool isMoving = false;
float speed = 0.f;
Vector3D cubeScale = Vector3D(0.f, 0.f, 0.f);
Vector3D cubePosition = Vector3D(0.f, 0.f, 0.f);
Vector3D cubeForward = Vector3D(1.f, 0.f, 0.f);
Vector3D cubeVerts[24] = { Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
						Vector3D(0.5, -0.5, 0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, -0.5, 0.5),
						Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, -0.5, 0.5),
						Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, 0.5, 0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, -0.5, -0.5),
						Vector3D(0.5, 0.5, 0.5), Vector3D(0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, -0.5), Vector3D(-0.5, 0.5, 0.5),
						Vector3D(0.5, -0.5, -0.5), Vector3D(0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, 0.5), Vector3D(-0.5, -0.5, -0.5)};

Vector3D cubeColors[6] = { Vector3D(1.0, 0.0, 0.0), Vector3D(0.0, 1.0, 0.0), Vector3D(0.0, 0.0, 1.0),
							Vector3D(1.0, 1.0, 0.0), Vector3D(1.0, 0.0, 1.0), Vector3D(0.0, 1.0, 1.0)};

//VIEW
float zoom = 0.1f;
float rotateAngle = 0.f;
int nFPS = 30;

void init(void)
{
	// init your data, setup OpenGL environment here
	glClearColor(1.f, 1.f, 1.f, 1.0f);

	glEnable(GL_DEPTH_TEST);
}

void drawCube(Vector3D pos){

	for (int i = 0; i < 6; i++){
		glBegin(GL_POLYGON);
		glColor3f(cubeColors[i].x, cubeColors[i].y, cubeColors[i].z);
		for (int j = 0; j < 4; j++){
			glVertex3f(cubeVerts[i*4 + j].x, cubeVerts[i*4 + j].y, cubeVerts[i*4 + j].z);
		}
		glEnd();
	}
}

void drawDotProduct(Vector3D a, Vector3D b){
	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(a.x, a.y, 0);
	glEnd();

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(b.x, b.y, 0);
	glEnd();

	float dot = Math::dot(a, b);

	glLineWidth(5);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(dot, b.y, 0);
	glEnd();
}

void drawCrossProduct(Vector3D a, Vector3D b){

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(a.x, a.y, a.z);
	glEnd();

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(b.x, b.y, b.z);
	glEnd();

	Vector3D cross = Math::cross(a, b);

	glLineWidth(2.5);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(cross.x, cross.y, cross.z);
	glEnd();
}

void keyboard_up(unsigned char key, int x, int y){
	if (key == 'w'){
		isMoving = false;
	}
	else if (key == 's'){
		isMoving = false;
	}
}

void keyboard_down(unsigned char key, int x, int y){
	if (key == 'w'){
		speed -= ACCELERATION;
		isMoving = true;
	}
	else if (key == 's'){
		speed += ACCELERATION;
		isMoving = true;
	}
}

void mouseWheel(int wheel, int direction, int x, int y)
{
	wheel = 0;
	if (direction == -1)
	{
		zoom -= ZOOM_SPEED;

	}
	else if (direction == +1)
	{
		zoom += ZOOM_SPEED;
	}

	glutPostRedisplay();

}

void display(){

	//  Clear screen and Z-buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	gluLookAt(eyePosition.x, eyePosition.y, eyePosition.z, centerPosition.x, centerPosition.y, centerPosition.z, upVector.x, upVector.y, upVector.z);

	glScalef(zoom, zoom, zoom);

	//drawDotProduct(Vector3D(.5, .5, 0), Vector3D(1, 0, 0));

	//drawCrossProduct(Vector3D(-1, -4, 2), Vector3D(4, 9, 2));

	drawCube(cubePosition);

	glFlush();
	glutSwapBuffers();

}

void translateVertices(Vector3D delta){

	for (int i = 0; i < 24; i++){
		cubeVerts[i] = Math::add(cubeVerts[i], delta);
	}
}

void limitSpeed(){

	if (speed < -MAX_SPEED){
		speed = -MAX_SPEED;
	}
	else if (speed > MAX_SPEED){
		speed = MAX_SPEED;
	}
	else{
		
	}
}

//Challenge: Have the camera follow the block in 3rd person.
void moveCamera(Vector3D delta){
	
}

//Challenge: Create a rotation matrix and apply the rotations to "newDirection".
void move(){

	limitSpeed();

	Vector3D newDirection = cubeForward;
	Vector3D delta = Math::multiply(newDirection, speed);
	cubePosition =  Math::add(delta, cubePosition);

	glTranslatef(cubePosition.x, cubePosition.y, cubePosition.z);
	translateVertices(delta);

	moveCamera(delta);
}

void stop(){
	if (Math::abs(speed) < .1f){
		speed = 0.f;
	}
	else if (speed > 0.f){
		speed -= .05f;
	}
	else{
		speed += .05f;
	}

	move();
}

void timer(int v)
{
	if(isMoving) move();
	else stop();
	glutPostRedisplay();
	glutTimerFunc(1000 / 30, timer, v);
}

void mathLibraryTests(){


	Vector3D z = Vector3D(0, 0, 1);
	Vector3D y = Vector3D(0, 1, 0);
	Vector3D x = Math::cross(y, z);
	std::cout << "(0, 0, 1) cross (0, 1, 0) = " << x.x << ", " << x.y << ", " << x.z << std::endl;

	float v = Math::dot(x, y);
	std::cout << "(1, 0, 0) dot (0, 1, 0) = " << v << std::endl;

	Vector3D zParallel = Vector3D(0, 0, 3);
	Vector3D w = Math::cross(zParallel, z);
	std::cout << "(0, 0, 1) cross (0, 0, 3) = " << w.x << ", " << w.y << ", " << w.z << std::endl;

	Vector3D a = Vector3D(3, 0, 0);
	Vector3D b = Vector3D(1, 1, 0);
	float u = Math::dot(a, b);
	std::cout << "(3, 0, 0) dot (1, 1, 0) = " << u << std::endl;
	u = acos(u / (Math::magnitude(a) * Math::magnitude(b)));
	std::cout << "Angle is: " << u << " radians" << std::endl;
	std::cout << "Angle is: " << u * 180 / 3.14159 << " degrees." << std::endl;

	float val = Math::sqrt(2);
	std::cout << "Sqrt of 2 is: " << val << std::endl;
}

int main(int argc, char* argv[]){

	mathLibraryTests();

	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("HappieEngine");
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard_down);
	glutKeyboardUpFunc(keyboard_up);
	glutTimerFunc(100, timer, 30);
	glutMouseWheelFunc(mouseWheel);
	glutDisplayFunc(display);
	glutMainLoop();

	//  Return to OS
	return 0;
}