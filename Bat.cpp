// See Bat.h file 

#include "Bat.h"

// this is the constructor and it is called when we create an object
Bat::Bat(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(50, 5));
	m_Shape.setPosition(m_Position);
}

// return our bats position
FloatRect Bat::getPosition() {
	return m_Shape.getGlobalBounds();
}

// return the shape of the bat
RectangleShape Bat::getShape() {
	return m_Shape;
}

// move the bat left
void Bat::moveLeft() {
	m_MovingLeft = true;
}

// move the bat right
void Bat::moveRight() {
	m_MovingRight = true;
}

// stop movement to the left
void Bat::stopLeft() {
	m_MovingLeft = false;
}

// stop movement to the right
void Bat::stopRight() {
	m_MovingRight = false;
}

// move our bat left and right in our game loop every frame
void Bat::update(Time dt) {
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}