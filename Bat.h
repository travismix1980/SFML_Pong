// Bat.h  This class is to create a player bat ... to hit our ball back to the player opponent.
// By Travis Mix

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat {
private:
	// position of the bat
	Vector2f m_Position;

	// A RectangleShape object
	RectangleShape m_Shape;

	// how fast the bat moves
	float m_Speed = 1000.0f;

	// keep track of if the bat is moving
	// right or left
	bool m_MovingRight = false;

	bool m_MovingLeft = false;

public:
	Bat(float startX, float startY);

	// returns the position of the bat
	FloatRect getPosition();

	// change the size of the bat
	// default is x: 50 y:5
	void setBatSize(float x, float y);

	// returns the shape of the bat
	RectangleShape getShape();

	// moves the bat left or right
	void moveLeft();

	void moveRight();

	void stopLeft();
	
	void stopRight();

	// updates the bats position smoothly based on 
	// time elapsed between frames
	void update(Time dt);
};