#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../utils/stringutils.h"
using namespace sf;
class Button
{
	typedef void(*eventFunction)();
protected:
	Color hover, normal;
	bool visible = true;
	RectangleShape rect;
	IntRect collider;
	eventFunction onClick = [](){};
	Font font;
	Text text;
	std::vector<std::string> labels;
public:
	Button(Vector2f position, Color color, Vector2f dims, std::string text, const char* file);
	Button();
	bool mouseTouching = false;
	void setOnClick(eventFunction);
	void draw(RenderWindow& window);
	virtual void update(RenderWindow& window);

	// Getters and Setters
	void setVisible(bool vis);
	bool getVisible();

	Vector2f getPosition();
	RectangleShape getRect();

	void setOutline(Color c);
	void setOutlineSize(int size);
	void setTextColor(Color c);
	void setFill(Color c);
	void setHover(Color c);
	void setFont(const char* file);
	void setLabels(std::vector<std::string> labels);
	void setLabels(std::string label);
	void setPosition(Vector2f position);
};

