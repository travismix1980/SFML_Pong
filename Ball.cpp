#include "Ball.h"

// Constructor
Ball::Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	// probably to small again add the ability to modify this
	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}

FloatRect Ball::getPosition() {
	return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
	return m_Shape;
}

float Ball::getXVelocity() {
	return m_DirectionX;
}

void Ball::reboundSides() {
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatOrTop() {
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom() {
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = -m_DirectionY;
}

void Ball::update(Time dt) {
	// update the balls position
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);
}

void Ball::resizeBall(float x, float y) {
	m_Shape.setSize(sf::Vector2f(x, y));
}

void Ball::increaseSpeed() {
	m_Speed += 20;
}

void Ball::setSpeed(float speed) {
	m_Speed = speed;
}
