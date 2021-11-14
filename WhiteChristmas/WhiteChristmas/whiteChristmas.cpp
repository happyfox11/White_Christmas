#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>


// 색상
GLfloat WHITE[] = { 1, 1, 1 };
GLfloat RED[] = { 1, 0, 0 };
GLfloat LIGHTRED[] = { 1, 0.6, 0.6 };
GLfloat GREEN[] = { 0, 0.5, 0 };
GLfloat LIGHTGREEN[] = { 0.6, 0.8, 0 };
GLfloat MAGENTA[] = { 1, 0, 1 };
GLfloat YELLOW[] = { 1, 1, 0 };
GLfloat SKYBLUE[] = { 0.5, 0.8, 0.9 };
GLfloat ORANGE[] = { 1.0 , 0.7, 0 };
GLfloat GRAY[] = { 0.4 , 0.4, 0.4 };
GLfloat BLACK[] = { 0 , 0, 0 };
GLfloat BLUE[] = { 0 , 0, 1 };
GLfloat PINK[] = { 1 , 0.7, 0.8 };
GLfloat BEIGE[] = { 1 , 0.8, 0.8 };
GLfloat BROWN[] = { 0.65 , 0.16, 0.16 };
GLfloat DARKBROWN[] = { 0.4 , 0, 0 };

// 메뉴
GLboolean IsOut_night = true;
GLboolean IsOut_morning = false;
GLboolean IsIn = false;
GLboolean IsSmall = true;

//카메라
class Camera {
	double theta;      // determines the x and z positions
	double y;          // the current y position
	double dTheta;     // increment in theta for swinging the camera around
	double dy;         // increment in y for moving the camera up/down
public:
	Camera() : theta(0), y(3), dTheta(0.04), dy(0.2) {}
	double getX() { return 10 * cos(theta); }
	double getY() { return y; }
	double getZ() { return 10 * sin(theta); }
	void moveRight() { theta += dTheta; }
	void moveLeft() { theta -= dTheta; }
	void moveUp() { y += dy; }
	void moveDown() { if (y > dy) y -= dy; }
};

//물체 클래스
class Object {
	double radius;
	double maximumHeight;
	double x;
	double y;
	double z;
	int direction;

public:
	Object(double r, double h, double x, double z) :
		radius(r), maximumHeight(h), direction(-1),
		y(h), x(x), z(z) {
	}

	//3D 집을 그리는 메소드
	void home() {
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LIGHTGREEN);
		glTranslatef(2.5, 1.5, 8);
		glutSolidCube(3);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLACK);
		glutWireCube(2.01);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GRAY);
		glTranslatef(0, 1.3, 0);
		glRotatef(-90.0f, 1, 0, 0);
		glutSolidCone(2.5, 1.5, 30, 30);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
		glTranslatef(0, 0, 0.65);
		glutSolidCone(1.45, 1.3, 30, 30);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, SKYBLUE);
		glTranslatef(+1.1, 0, -1.5);
		glutSolidCube(1);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, DARKBROWN);
		glTranslatef(-0.2, 0, 0);
		glutSolidCube(1.3);
		glPopMatrix();
	}

	//2D 별을 그리는 메소드
	void star() {
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ORANGE);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

		if (!IsSmall) {
			glTranslated(-5, 3.8, 6.03);
			glScalef(2, 2, 2);
		}
		else
			glTranslated(-5, 1.8, 6.03);

		glBegin(GL_POLYGON);
		glVertex3f(0.02, -0.07, 0.0);
		glVertex3f(0.07, -0.1, 0.0);
		glVertex3f(0.05, -0.05, 0.0);
		glVertex3f(0.1, 0.03, 0.0);
		glVertex3f(0.04, 0.03, 0.0);
		glVertex3f(0.02, 0.1, 0.0);
		glVertex3f(-0.04, 0.03, 0.0);
		glVertex3f(-0.1, 0.03, 0.0);
		glVertex3f(-0.05, -0.05, 0.0);
		glVertex3f(-0.07, -0.1, 0.0);
		glEnd();
		glFlush();
		glPopMatrix();

	}

	//3D 크리스마스 트리를 그리는 메소드
	void tree() {

		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, GREEN);

		if (IsSmall)
			glTranslated(6, 1.2, 5);
		else
			glTranslated(6, 2.5, 5);

		glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);

		if (!IsSmall)
			glScalef(2, 2, 2);

		glutSolidCone(0.3, 0.6, 30, 50);
		glTranslatef(0, 0, -0.4);
		glutSolidCone(0.4, 0.6, 30, 50);
		glTranslatef(0, 0, -0.4);
		glutSolidCone(0.5, 0.6, 30, 50);
		glTranslatef(0, 0, -0.4);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BROWN);
		glutSolidCone(0.2, 1.0, 30, 50);

		glTranslatef(0, 0, 1.8);


		glTranslatef(0, 0.35, -0.6);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RED);
		glutSolidSphere(0.07, 30, 30);

		glTranslatef(0, -0.7, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RED);
		glutSolidSphere(0.07, 30, 30);

		glTranslatef(0, 0.82, -0.4);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
		glutSolidSphere(0.07, 30, 30);

		glTranslatef(0, -0.94, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
		glutSolidSphere(0.07, 30, 30);

		glTranslatef(0, 1.0, -0.4);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, MAGENTA);
		glutSolidSphere(0.07, 30, 30);

		glTranslatef(0, -1.1, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, MAGENTA);
		glutSolidSphere(0.07, 30, 30);

		glPopMatrix();

	}

	//3D 선물 상자를 그리는 메소드
	void present() {
		glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, SKYBLUE);
		//glTranslated(7.2, 0.15, 1.2);
		glTranslated(5.7, 0.15, 4); glScalef(2, 2, 2);
		glutSolidCube(0.3);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, ORANGE);
		glTranslated(0.3, 0.0, 0.1);
		glutSolidCube(0.3);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RED);
		glTranslated(-0.3, 0, 1);
		glutSolidCube(0.3);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, LIGHTRED);
		glTranslated(0.5, 0, 0.2);
		glutSolidCube(0.3);

		glPopMatrix();
	}

	//실내 놀이방에 갈색 꽃가루를 뿌리는 메소드
	void spread() {
		y += direction * 0.04;
		radius = 0.015;
		if (y > maximumHeight) {
			y = maximumHeight; direction = -1;
		}
		else if (y < radius) {
			y = radius; direction = 1000;
		}

		glPushMatrix();
		glTranslated(x, y, z);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, DARKBROWN);
		glRotatef(30.0f, 1, 0, 1);
		glutSolidCube(0.025);
		glPopMatrix();

	}
	//실내 놀이방에 파란 꽃가루를 뿌리는 메소드
	void spread2() {

		y += direction * 0.04;
		radius = 0.02;
		if (y > maximumHeight) {
			y = maximumHeight; direction = -1;
		}
		else if (y < radius) {
			y = radius; direction = 1000;
		}

		glPushMatrix();
		glTranslated(x, y, z);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLUE);
		glRotatef(60.0f, 1, 0, 0);
		glutSolidCube(0.03);
		glPopMatrix();
	}

	//실내 놀이방에 초록 꽃가루를 뿌리는 메소드
	void spread3() {
		y += direction * 0.04;
		radius = 0.02;
		if (y > maximumHeight) {
			y = maximumHeight; direction = -1;
		}
		else if (y < radius) {
			y = radius; direction = 1000;
		}

		glPushMatrix();
		glTranslated(x, y, z);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, GREEN);
		glRotatef(45.0f, 1, 0, 0);
		glutSolidCube(0.05);
		glPopMatrix();
	}

	//하늘에서부터 바닥을 향해 천천히 내리는 눈을 표현하는 메소드
	void snowing() {
		y += direction * 0.04;
		radius = 0.02;
		if (y > maximumHeight) {
			y = maximumHeight; direction = -1;
		}
		else if (y < radius) {
			y = radius; direction = 1000;
		}

		glPushMatrix();
		glTranslated(x, y, z);
		glColor3f(1, 1, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, WHITE);
		glutSolidSphere(radius, 30, 30);
		glPopMatrix();
	}

	//눈사람을 그리는 메소드
	void snowman() {
		
		glPushMatrix();
		// 몸 
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, WHITE);
		glTranslatef(6, 0.3, 7.5);
		glutSolidSphere(0.5, 30, 30);
		
		// 머리
		glTranslatef(0, 0.7, 0);
		glutSolidSphere(0.3, 30, 30);

		//빨간 산타 모자
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, RED);
		glTranslatef(0, 0.12, 0);
		glRotatef(-90.0f, 1, 0, 0);
		glutSolidCone(0.3, 0.5, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, GRAY);
		glTranslatef(0, 0, 0.5);
		glutSolidSphere(0.1, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, WHITE);
		glTranslatef(0, 0, -0.42);
		glutSolidTorus(0.05, 0.2, 30, 30);

		// 눈알
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLACK);
		glTranslatef(0.25, -0.12, -0.12);
		glutSolidSphere(0.05, 30, 30);
		glTranslatef(0, 0.3, 0);
		glutSolidSphere(0.05, 30, 30);

		//웃고있는 입
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, RED);
		glTranslatef(0, -0.16, -0.14);
		glRotatef(180.0f, 1, 0, 0);
		glutSolidCone(0.08, 0.15, 30, 30);

		glPopMatrix();
	}

	//앞뒤로 움직이는 장난감 자동차와 그 위에 타고 있는 아이를 그리는 메소드 
	void toyCar() {
		x += direction * 0.04;
		if (x > maximumHeight - 3) {
			x = maximumHeight - 3; direction = -1;
		}
		else if (x < radius) {
			x = radius; direction = 1;
		}

		glPushMatrix();
		//자동차 몸체
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ORANGE);
		glTranslated(x + 2, 1, 2.7);
		glutSolidCube(1.2);

		//자동차 바퀴 4개
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLACK);
		glTranslated(0.3, -0.8, -0.5);
		glutSolidTorus(0.1, 0.16, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, RED);
		glTranslated(-0.6, 0, 0);
		glutSolidTorus(0.1, 0.16, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, YELLOW);
		glTranslated(0, 0, 1);
		glutSolidTorus(0.1, 0.16, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLUE);
		glTranslated(0.6, 0, 0);
		glutSolidTorus(0.1, 0.16, 30, 30);

		//사람 몸
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLUE);
		glTranslatef(-0.2, 1.3, -0.45);
		glutSolidSphere(0.5, 30, 30);
		
		//사람 머리
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BEIGE);
		glTranslatef(0, 0.7, 0);
		glutSolidSphere(0.3, 30, 30);

		//초록 모자
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, GREEN);
		glTranslatef(0, 0.12, 0);
		glRotatef(-90.0f, 1, 0, 0);
		glutSolidCone(0.3, 0.5, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, GRAY);
		glTranslatef(0, 0, 0.5);
		glutSolidSphere(0.1, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, WHITE);
		glTranslatef(0, 0, -0.42);
		glutSolidTorus(0.05, 0.2, 30, 30);

		// 사람 눈알 
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, BLACK);
		glTranslatef(0.25, -0.12, -0.12);
		glutSolidSphere(0.05, 30, 30);
		glTranslatef(0, 0.3, 0);
		glutSolidSphere(0.05, 30, 30);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, RED);
		glTranslatef(0, -0.16, -0.14);
		glRotatef(180.0f, 1, 0, 0);
		glutSolidCone(0.08, 0.15, 30, 30);

		//웃고 있는 입
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, RED);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glTranslated(-1, 0, 0.28); glScalef(5, 5, 5);
		
		//장난감 자동차 앞면에 그려진 별 그림
		glBegin(GL_POLYGON);
		glVertex3f(0.0, -0.05, 0.0);
		glVertex3f(0.05, -0.08, 0.0);
		glVertex3f(0.03, -0.03, 0.0);
		glVertex3f(0.08, 0.01, 0.0);
		glVertex3f(0.02, 0.01, 0.0);
		glVertex3f(0.0, 0.08, 0.0);
		glVertex3f(-0.02, 0.01, 0.0);
		glVertex3f(-0.08, 0.01, 0.0);
		glVertex3f(-0.03, -0.03, 0.0);
		glVertex3f(-0.05, -0.08, 0.0);
		glEnd();

		//만세하고 있는 사람의 두 팔
		GLUquadricObj* obj1;

		obj1 = gluNewQuadric();

		glTranslatef(0.12, -0.05, -0.1);
		glRotatef(90.0f, 1, 1, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
		gluCylinder(obj1, 0.02f, 0.02f, 0.14f, 16, 4);

		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BEIGE);
		glTranslatef(0, 0, 0.14);
		glutSolidSphere(0.02, 30, 30);

		gluDeleteQuadric(obj1);

		GLUquadricObj* obj2;

		obj2 = gluNewQuadric();

		glTranslatef(0.06, 0.06, -0.2);
		glRotatef(-90.0f, 1, 0, 0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BLUE);
		gluCylinder(obj2, 0.02f, 0.02f, 0.14f, 16, 4);

		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, BEIGE);
		glTranslatef(0, 0, 0.14);
		glutSolidSphere(0.02, 30, 30);

		gluDeleteQuadric(obj2);

		glPopMatrix();
	}

};

//벽면과 바닥면
class Wall {
	int displayListId;
	int width;
	int depth;
public:
	Wall(int width, int depth) : width(width), depth(depth) { width = 0; depth = 0; }
	double centerx() { return width / 2; }
	double centerz() { return depth / 2; }
	void playroom() {


		glBegin(GL_QUADS);
		glNormal3d(0, 1, 0);

		for (int x = 0; x < width + 2; x++) {
			for (int y = 0; y < depth + 2; y++) {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (x + y) % 2 == 0 ? BLUE : SKYBLUE);
				glVertex3d(x, y, 0);
				glVertex3d(x + 1, y, 0);
				glVertex3d(x + 1, y + 1, 0);
				glVertex3d(x, y + 1, 0);
			}
		}

		for (int x = 0; x < width + 2; x++) {
			for (int y = 0; y < depth + 2; y++) {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (x + y) % 2 == 0 ? BLUE : SKYBLUE);
				glVertex3d(x, y, depth + 2);
				glVertex3d(x + 1, y, depth + 2);
				glVertex3d(x + 1, y + 1, depth + 2);
				glVertex3d(x, y + 1, depth + 2);
			}
		}

		for (int z = 0; z < width + 2; z++) {
			for (int y = 0; y < depth + 2; y++) {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, (z + y) % 2 == 0 ? RED : PINK);
				glVertex3d(0, y, z);
				glVertex3d(0, y, z + 1);
				glVertex3d(0, y + 1, z + 1);
				glVertex3d(0, y + 1, z);
			}
		}

		glEnd();
		glEndList();
	}

	void create() {
		displayListId = glGenLists(1);
		glNewList(displayListId, GL_COMPILE);

		GLfloat lightPosition[] = { 15,30,8,1 };

		glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

		glBegin(GL_QUADS);
		glNormal3d(0, 1, 0);

		//흰 눈이 쌓인 바닥
		for (int x = 0; x < width + 2; x++) {
			for (int z = 0; z < depth + 2; z++) {
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,  WHITE);
				glVertex3d(x, 0, z);
				glVertex3d(x + 1, 0, z);
				glVertex3d(x + 1, 0, z + 1);
				glVertex3d(x, 0, z + 1);
			}
		}

		glEnd();
		glEndList();
	}
	void draw() {
		glCallList(displayListId);
	}
};


Wall wall(9, 9);
Camera camera;
Object objects[] = {
  Object(0.4, 8, 6, 1),
  Object(0.6, 9, 1, 2),
  Object(0.6, 10, 3, 4),
  Object(0.3,  11, 7, 5),
  Object(0.7, 12, 1, 7),
  Object(0.3, 8, 6, 3),
  Object(0.5,  9, 6, 2),
  Object(0.6, 10, 7, 1),
  Object(0.9, 11, 7, 5),
  Object(0.9, 12, 7, 5),
  Object(0.9, 8, 7, 2),
  Object(0.9, 8, 7, 8),
  Object(0.9, 10, 7, 2),
  Object(0.9, 9, 1, 1),
  Object(0.9, 12, 10, 10),

  Object(0.9, 12, 10, 2),
  Object(0.9,  8, 10, 8),
  Object(0.9, 10, 10, 4),
  Object(0.9, 9, 2, 7),
  Object(0.9, 10, 6, 2),
  Object(0.9,  12, 7, 5),
  Object(0.9,  10, 6, 10),
  Object(0.9, 9, 10, 7),
  Object(0.9,8, 10, 5),

   Object(0.4, 7, 1, 1),
   Object(0.4,  8, 2, 2),
   Object(0.4, 9, 3, 3),
   Object(0.4, 10, 4, 4),
   Object(0.4, 11, 5, 5),
   Object(0.4, 12, 6, 6),
   Object(0.4, 7, 7, 7),
   Object(0.4, 8, 8, 8),
   Object(0.4, 9, 11, 11),
   Object(0.4, 10, 12, 12),
   Object(0.4,  11, 7, 7),
   Object(0.4, 12, 8, 8),
   Object(0.4,  7, 1, 3),
   Object(0.4,  8, 2, 8),
   Object(0.4, 9, 3, 1),
   Object(0.4,  10, 4, 5),
   Object(0.4,  11, 5,10),
   Object(0.4,  12, 6,2),
   Object(0.4,  7, 7,4),
   Object(0.4,  8,8 ,12),
   Object(0.4,  9, 9,3),
   Object(0.4,  10, 10,5),
   Object(0.4, 11, 11,1),
   Object(0.4, 12, 12,7),
   Object(0.4,  10, 1,12),
   Object(0.4,  11, 5,1),
   Object(0.4, 12,7 ,4)

};


void init() {
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
	glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
	glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
	glMaterialf(GL_FRONT, GL_SHININESS, 30);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	wall.create();
}

//모든 것을 결합하여 보여주는 메소드
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(camera.getX() + 4, camera.getY(), camera.getZ() + 5,
		5, 2, 5,
		0.0, 1.0, 0.0);

	wall.draw();

	objects[0].star();
	objects[0].present();
	objects[0].snowman();
	objects[0].toyCar();
	objects[0].home();


	if (IsOut_night) {
		glClearColor(0.0, 0.0, 0.0, 1);
		objects[0].tree();
		for (int i = 0; i < sizeof objects / sizeof(Object); i++) {
			objects[i].snowing();
		}
	}
	else if (IsOut_morning) {
		glClearColor(0.5, 0.8, 0.9, 1);
		objects[0].tree();
		for (int i = 0; i < sizeof objects / sizeof(Object); i++) {
			objects[i].snowing();
		}
	}
	else if (IsIn) {
		wall.playroom(); wall.draw();
		objects[0].tree();
		for (int i = 0; i < sizeof objects / sizeof(Object); i++) {

			if (i % 3 == 0)
				objects[i].spread();
			else if (i % 3 == 1)
				objects[i].spread2();
			else
				objects[i].spread3();
		}
	}

	glFlush();
	glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
}

void timer(int v) {
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, v);
}

void keyboard(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT: camera.moveLeft(); break;
	case GLUT_KEY_RIGHT: camera.moveRight(); break;
	case GLUT_KEY_UP: camera.moveUp(); break;
	case GLUT_KEY_DOWN: camera.moveDown(); break;
	}
	glutPostRedisplay();
}

void MyMainMenu(int entryID) {
	if (entryID == 1) {
		IsOut_night = true;
		IsOut_morning = false;
		IsIn = false;
	}
	else if (entryID == 2) {
		IsOut_night = false;
		IsOut_morning = true;
		IsIn = false;
	}
	else if (entryID == 3) {
		IsOut_night = false;
		IsOut_morning = false;
		IsIn = true;
	}
	else if (entryID == 4)
		exit(0);

	glutPostRedisplay();
}


void MySubMenu(int entryID) {
	if (entryID == 1)
		IsSmall = true;
	else if (entryID == 2)
		IsSmall = false;

	glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(1500, 800);
	glutCreateWindow("WhiteChristmas_201811119_박한별");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);


	GLint MySubMenuID = glutCreateMenu(MySubMenu);
	glutAddMenuEntry("Small Tree", 1);
	glutAddMenuEntry("Big Tree", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Night - outdoor", 1);
	glutAddMenuEntry("Morning - outdoor", 2);
	glutAddMenuEntry("PlayRoom - inside", 3);
	glutAddSubMenu("Christmas Tree Size", MySubMenuID);
	glutAddMenuEntry("Exit", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);

	glutTimerFunc(100, timer, 0);
	init();
	glutMainLoop();
}
