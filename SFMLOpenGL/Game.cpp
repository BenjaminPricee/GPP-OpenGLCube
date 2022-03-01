#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	//Vector3B work(2, 12, 6);
	//Vector3B b(1, 3, 2);

	//work += b;

	std::cout << "ok" << std::endl;

	top.x = 0;
	top.y = 2;
	top.z = -5;

	left.x = -2;
	left.y = -2;
	left.z = -5;

	right.x = 2;
	right.y = -2;
	right.z = -5;

	//moveRight.x = 0.00025f;
	//moveRight.y = 0.00025f;
	//moveRight.z = 0.00025f;

	//scaleUp.x = 1.00025f;
	//scaleUp.y = 1;
	//scaleUp.z = 1;

	////////////////////////////////////////////////////////////////////////////
	
	rotate.x1 = 0;
	rotate.y1 = 2;
	rotate.z1 = -5;
	rotate.x2 = -2;
	rotate.y2 = -2;
	rotate.z2 = -5;
	rotate.x3 = 2;
	rotate.y3 = -2;
	rotate.z3 = -5;

	rotate2.x1 = cos(0.00025f);
	rotate2.y1 = -sin(0.00025f);
	rotate2.z1 = 0;
	rotate2.x2 = sin(0.00025f);
	rotate2.y2 = cos(0.00025f);
	rotate2.z2 = 0;
	rotate2.x3 = 0;
	rotate2.y3 = 0;
	rotate2.z3 = 1;


	std::cout << "Pause" << std::endl;

}

void Game::update()
{
	rotate = rotate * rotate2;

	cout << "Update up" << endl;
	//glRotatef(0.025, 0, 0, 1);
	//glScalef(1.000025, 1, 1);
	//glTranslatef(0.00025f, 0.0, 0.0);

	//top += moveRight;
	//left += moveRight;
	//right += moveRight;
	 
	//top *= scaleUp;
	//left *= scaleUp;
	//right *= scaleUp;

	std::cout << "Check" << std::endl;
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	//{ glVertex3f(top.x, top.y, top.z); glVertex3f(left.x, left.y, left.z); glVertex3f(right.x, right.y, right.z); }
	{ glVertex3f(rotate.x1, rotate.y1, rotate.z1); glVertex3f(rotate.x2, rotate.y2, rotate.z2); glVertex3f(rotate.x3, rotate.y3, rotate.z3); }
	glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

