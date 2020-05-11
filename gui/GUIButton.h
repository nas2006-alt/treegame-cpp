#pragma once
#include "Button.h"
#include <math.h>
#include "../Core/Player.h"
#include "../Core/Constants.h"
#include "../Core/Math.h"
class GUIButton : public Button
{
	typedef void(*buyFunction)(GUIButton&);
	buyFunction function;
	int id;
	Menu menu;
public:
	GUIButton(Vector2f position, Color color, Vector2f dims, std::string text, const char * file, Menu menu, int id);
	void renderConnection(RenderWindow& window, std::vector<GUIButton> list);
	void initBuy();

	void update(RenderWindow & window) override;
	void setBuyFunction(buyFunction function);
	void syncCostLabel();
};

