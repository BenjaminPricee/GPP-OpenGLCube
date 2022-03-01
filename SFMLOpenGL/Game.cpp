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

	rotate.x1 = cos(0.00025f);
	rotate.y1 = 0;
	rotate.z1 = sin(0.00025f);
	rotate.x2 = 0;
	rotate.y2 = 1;
	rotate.z2 = 0;
	rotate.x3 = -sin(0.00025f);
	rotate.y3 = 0;
	rotate.z3 = cos(0.00025f);

	////////////////////////////////////////////////////////////////////////////
	/// 
	FL.x1 = -1;
	FL.y1 = 1;
	FL.z1 = -5;
	FL.x2 = -1;
	FL.y2 = -1;
	FL.z2 = -5;
	FL.x3 = 1;
	FL.y3 = -1;
	FL.z3 = -5;

	FR.x1 = -1;
	FR.y1 = 1;
	FR.z1 = -5;
	FR.x2 = 1;
	FR.y2 = 1;
	FR.z2 = -5;
	FR.x3 = 1;
	FR.y3 = -1;
	FR.z3 = -5;

	BL.x1 = -1;
	BL.y1 = 1;
	BL.z1 = -10;
	BL.x2 = -1;
	BL.y2 = -1;
	BL.z2 = -10;
	BL.x3 = 1;
	BL.y3 = -1;
	BL.z3 = -10;

	BR.x1 = -1;
	BR.y1 = 1;
	BR.z1 = -10;
	BR.x2 = 1;
	BR.y2 = 1;
	BR.z2 = -10;
	BR.x3 = 1;
	BR.y3 = -1;
	BR.z3 = -10;

	std::cout << "ok" << std::endl;

	////////////////////////////////////////////////////////////////////////////


	std::cout << "Pause" << std::endl;

}

void Game::update()
{
	FL = FL * rotate;
	FR = FR * rotate;
	BL = BL * rotate;
	BR = BR * rotate;

	std::cout << "Check" << std::endl;
}

void Game::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	{ glVertex3f(FL.x1, FL.y1, FL.z1 - 15); glVertex3f(FL.x2, FL.y2, FL.z2 - 15); glVertex3f(FL.x3, FL.y3, FL.z3 - 15); }
	{ glVertex3f(FR.x1, FR.y1, FR.z1 - 15); glVertex3f(FR.x2, FR.y2, FR.z2 - 15); glVertex3f(FR.x3, FR.y3, FR.z3 - 15); }
	{ glVertex3f(BL.x1, BL.y1, BL.z1 - 15); glVertex3f(BL.x2, BL.y2, BL.z2 - 15); glVertex3f(BL.x3, BL.y3, BL.z3 - 15); }
	{ glVertex3f(BR.x1, BR.y1, BR.z1 - 15); glVertex3f(BR.x2, BR.y2, BR.z2 - 15); glVertex3f(BR.x3, BR.y3, BR.z3 - 15); }
	glEnd();


	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

