#pragma once
#include <vector>
#include "../gui/GUIButton.h"
class MouseHandler
{
public:
	static int oldX, oldY;
	static int x, y;
	static int dragX, dragY;
	static bool down;
	static void update(std::vector<GUIButton> buttons);
};

