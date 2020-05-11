#include "MouseHandler.h"

int MouseHandler::x = 0;
int MouseHandler::y = 0;
int MouseHandler::oldX = 0;
int MouseHandler::oldY = 0;
int MouseHandler::dragX = 0;
int MouseHandler::dragY = 0;
bool MouseHandler::down = false;

void MouseHandler::update(std::vector<GUIButton> buttons)
{
	bool overButtons = false;
	for (GUIButton button : buttons) {
		if (button.mouseTouching) {
			overButtons = true;
		}
	}
	if (down && !overButtons) {
		MouseHandler::dragX = MouseHandler::oldX - MouseHandler::x;
		MouseHandler::dragY = MouseHandler::oldY - MouseHandler::y;
	}
	else {
		MouseHandler::dragX = 0;
		MouseHandler::dragY = 0;
	}
	MouseHandler::oldX = MouseHandler::x;
	MouseHandler::oldY = MouseHandler::y;
	MouseHandler::x = sf::Mouse::getPosition().x;
	MouseHandler::y = sf::Mouse::getPosition().y;
	MouseHandler::down = sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}
