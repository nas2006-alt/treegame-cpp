#include "Renderer.h"

void Renderer::renderText(sf::Vector2f position, std::string fontFile, std::string toRender, sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile(fontFile);
	sf::Text text;
	text.setFont(font);
	text.setString(toRender);
	text.setPosition(position);
	text.setCharacterSize(16);
	window.draw(text);
}
