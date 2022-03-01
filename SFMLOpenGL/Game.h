#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include"Vector3.h"
#include"Matrix3.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();

private:
	Matrix3B rotate;
	Matrix3B scale;
	Matrix3B moveZ;
	Matrix3B moveX;

	Matrix3B FL;
	Matrix3B FR;

	Matrix3B BL;
	Matrix3B BR;

	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	// // Uncomment for Part 2
	// // ********************
	// const int primatives;

	//GLuint index;
	//Clock clock;
	//Time elapsed;

	//float rotationAngle = 0.0f;
	// // ********************
};