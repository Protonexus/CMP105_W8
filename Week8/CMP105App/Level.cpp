#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ball1 = Ball(sf::Vector2f(100.f, 100.f), sf::Vector2f(100.f, 0.f));
	ball1.setWindow(hwnd);
	ball2 = Ball(sf::Vector2f(600.f, 100.f), sf::Vector2f(-100.f, 0.f));
	ball2.setWindow(hwnd);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt);
	ball2.update(dt);
	
	if (Collision::checkBoundingCircle(&ball1, &ball2))
	{
		ball1.collisionResponse();
		ball2.collisionResponse();
	}
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}