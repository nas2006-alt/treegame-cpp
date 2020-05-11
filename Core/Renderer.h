#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class Renderer
{
public:
	static void renderText(sf::Vector2f position, std::string fontFile, std::string toRender, sf::RenderWindow& window);
};

