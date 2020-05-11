#include "Button.h"


Button::Button(sf::Vector2f position, Color color, sf::Vector2f dims, std::string text, const char* font)
{
	this->normal = color;
	this->rect = RectangleShape(position);
	this->rect.setSize(dims);
	this->rect.setFillColor(color);
	this->collider = IntRect(rect.getPosition().x, rect.getPosition().y, rect.getGlobalBounds().width, rect.getGlobalBounds().height);
	if (!this->font.loadFromFile(font))
	{
		std::cout << "Couldn't load font!" << "\n";
	}
	this->text.setFont(this->font);
	this->text.setCharacterSize(16);
	this->text.setFillColor(Color::Black);
	this->setLabels(text);
}

Button::Button()
{
}

void Button::setOnClick(eventFunction function)
{
	this->onClick = function;
}

void Button::update(RenderWindow& window) {
	this->mouseTouching = collider.contains(Mouse::getPosition(window));

	if (mouseTouching) {
		rect.setFillColor(hover);
	}
	else {
		rect.setFillColor(normal);
	}
}

void Button::draw(RenderWindow& window)
{
	if (visible) {
		window.draw(rect);

		if (labels.size() > 1) {
			
			for (unsigned int x = 0; x < labels.size(); x++) {
				text.setString(labels[x]);
				text.setPosition((this->rect.getGlobalBounds().left) + rect.getGlobalBounds().width / 2 - text.getGlobalBounds().width / 2,
					(this->rect.getGlobalBounds().top + this->rect.getGlobalBounds().height / 2) - text.getLineSpacing()/2 + x * 20 - (labels.size() * 10));
				window.draw(text);
			}
		}
		else {
			text.setString(labels[0]);
			text.setPosition((this->rect.getGlobalBounds().left + this->rect.getGlobalBounds().width / 2) - text.getGlobalBounds().width / 2,
				(this->rect.getGlobalBounds().top + this->rect.getGlobalBounds().height / 2) - text.getLineSpacing()/2 - 10);
			window.draw(text);
		}
	}
}

void Button::setVisible(bool visible) {
	this->visible = visible;
}

bool Button::getVisible() {
	return this->visible;
}

void Button::setOutline(Color c) {
	this->rect.setOutlineColor(c);
}

void Button::setOutlineSize(int size) {
	this->rect.setOutlineThickness(size);
}

void Button::setTextColor(Color c) {
	this->text.setFillColor(c);
}

void Button::setFill(Color c) {
	this->normal = c;
	this->rect.setFillColor(c);
}

void Button::setHover(Color c) {
	this->hover = c;
}

void Button::setFont(const char* file) {
	if (!font.loadFromFile(file))
	{
		std::cout << "Couldn't load font!" << "\n";
	}
}

void Button::setLabels(std::vector<std::string> labels) {
	this->labels = labels;
}

void Button::setLabels(std::string label) {
	std::vector<std::string> fakeLabels = {};
	splitUsingDelimiter(label, '\n', fakeLabels);
	this->labels = fakeLabels;
}

void Button::setPosition(Vector2f position) {
	this->rect.setPosition(position);
	this->collider = this->collider = IntRect(rect.getPosition().x, rect.getPosition().y, rect.getGlobalBounds().width, rect.getGlobalBounds().height);
}

Vector2f Button::getPosition() {
	return rect.getPosition();
}

RectangleShape Button::getRect()
{
	return rect;
}


