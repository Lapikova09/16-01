#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
bool pointInRect(sf::RectangleShape bat, sf::Vector2f point) {
	return bat.getPosition().x <= point.x &&
		point.x <= bat.getPosition().x + BAT_SIZE.x &&
		bat.getPosition().y <= point.y &&
		point.y <= bat.getPosition().y + BAT_SIZE.y;
}
struct Ball {
	sf::CircleShape shape;
	float speedX;
	float speedY;
	int score;
};
void ballInit(Ball& ball) {
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	ball.speedX = 2.f;
	ball.speedY = 3.f;
	ball.score = 0.f;
}
void ballUpdate(Ball& ball) {
	ball.shape.move(ball.speedX, ball.speedY);
	if (ball.shape.getPosition().x <= 0)
	{
		ball.speedX = -ball.speedX;
	}
	if (ball.shape.getPosition().x + 2 * BALL_RADIUS >= WINDOW_WIDTH) {
		ball.speedX = -ball.speedX;
	}
	if (
		ball.shape.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGHT)
	{
		ball.speedY = -ball.speedY;
	}
	if (ball.shape.getPosition().y <= 0) {
		ball.speedY = -ball.speedY;
	}
}
void ballDraw(sf::RenderWindow& window, const Ball& ball) {
	window.draw(ball.shape);
}