// SFML_Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
// by Travis Mix

#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

int main() {
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a full screen (1920 x 1080) window for the game to run inside
	RenderWindow window(vm, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	// Create a bat at the bottom center of th e screen
	Bat bat(1920 / 2.0f, 1080 - 20);
	// default bat seemed way to small so 
	// added the ability to make it bigger
	// remove later maybe?
	bat.setBatSize(180, 10);

	// We will add the Ball here
	Ball ball(1920 / 2, 0);

	// Create a Text object called hud 
	Text hud;

	// add our font
	Font font;
	font.loadFromFile("fonts/DS-DIGI.ttf");

	// set the font
	hud.setFont(font);

	// make the font nice and big - is this to big?
	hud.setCharacterSize(30);

	// set our font color to white
	hud.setFillColor(Color::White);

	// place our hud on the screen
	hud.setPosition(20, 20);

	// create a clock to keep track of time
	Clock clock;

	// start the game loop
	while (window.isOpen()) {
		// handle player input
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				// quit the game when the window is closed
				window.close();
			}
		}
		
		// handle the player quiting via the ESC key
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		// handle player input for left and right movement
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			bat.moveLeft();
		}
		else {
			bat.stopLeft();
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			bat.moveRight();
		}
		else {
			bat.stopRight();
		}

		// update the bat, ball, and hud

		// Update the delta time
		Time dt = clock.restart();
		
		// update the bat
		bat.update(dt);

		// update the ball
		ball.update(dt);

		// update the hud
		std::stringstream ss;
		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());

		// check for collisions
		// handle the ball hitting the bottom
		if (ball.getPosition().top > window.getSize().y) {
			// reverse the ball direction
			ball.reboundBottom();

			// remove a life;
			lives--;

			// check for 0 lives remaining
			if (lives < 1) {
				// reset the score 
				score = 0;

				// reset lives
				lives = 3;

				// reset ball speed
				ball.setSpeed(1400);
			}
		}

		// handle the ball hitting the top of the screen
		if (ball.getPosition().top < 0) {
			ball.reboundBatOrTop();
		}

		// if the ball hits the side of the screen
		if (ball.getPosition().left < 0 || ball.getPosition().left + ball.getPosition().width > window.getSize().x) {
			ball.reboundSides();
		}

		// handle the ball hitting the bat
		if (ball.getPosition().intersects(bat.getPosition())) {
			// hit detected so reverse ball and add 1 to score
			ball.reboundBatOrTop();
			score += 10;

			// increase the ball speed slightly for added challenge
			ball.increaseSpeed();
		}

		// draw the bat, the ball, and the hud
		
		// clear out the old stuff
		window.clear();
		
		// draw the new stuff
		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());

		// display on the screen what we drew
		window.display();

	}

	return 0;
}