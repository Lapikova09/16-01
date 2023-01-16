#include <SFML/Graphics.hpp>
#include "Header.h"
#include "functions.h"
#include "bat.h"
#include "text.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close);
	window.setFramerateLimit(FPS);

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	Textobj scoreText;
	TextobjInit(scoreText, ball.score);

	
	/*Text finish;
	finish.setString(end);
	finish.setFont(font);
	finish.setCharacterSize(FONT_SIZE);
	finish.setPosition(END_TEXT_POS);*/

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		ballUpdate(ball);
		batUpdate(bat);
		TextobjUpdate(scoreText,ball.score);

		/*if (Score == 5) {
			ball.speedX = 0.f;
			ball.speedY = 0.f;
			ball.shape.setPosition(BALL_END_POS);
			window.clear();
			window.draw(finish);
			window.display();
		}*/

		Vector2f left{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y };
		Vector2f mid{ ball.shape.getPosition().x + BALL_RADIUS,ball.shape.getPosition().y };
		Vector2f right{ ball.shape.getPosition().x,ball.shape.getPosition().y + 2 * BALL_RADIUS };
		Vector2f midleft{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f midright{ ball.shape.getPosition().x,ball.shape.getPosition().y + BALL_RADIUS };
		Vector2f bottomleft{ ball.shape.getPosition().x + 2 * BALL_RADIUS,ball.shape.getPosition().y + 2 * BALL_RADIUS };
		Vector2f bottomright{ ball.shape.getPosition().x,ball.shape.getPosition().y + 2 * BALL_RADIUS };

		if (pointInRect(bat.shape, mid) && pointInRect(bat.shape, left) ||
			pointInRect(bat.shape, mid) && pointInRect(bat.shape, right)) {
			ball.speedY = -ball.speedY;
			ball.speedX = -ball.speedX;
		}
		if (pointInRect(bat.shape, right) && pointInRect(bat.shape, midright) ||
			pointInRect(bat.shape, bottomright) && pointInRect(bat.shape, midright)) {
			ball.speedX = -ball.speedX;
		}
		if (pointInRect(bat.shape, midleft) && pointInRect(bat.shape, left) ||
			pointInRect(bat.shape, midleft) && pointInRect(bat.shape, bottomleft)) {
			ball.speedX = -ball.speedX;
		}
		if (pointInRect(bat.shape, left) || pointInRect(bat.shape, right)) {
			ball.speedY = -ball.speedY;
		}

		window.clear();
		batDraw(window, bat);
		ballDraw(window, ball);
		textDraw(window, scoreText);
		window.display();
	}
	return 0;
}