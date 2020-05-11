#pragma once
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "../utils/Vector3Big.h"
	enum Upgrade {
		RAISE_X_1POINT5 = 0,
		RAISE_CORE_X_25 = 1,
		BEGIN_X = 2,
		RAISE_CORE_X_10 = 3,
		X_AND_Y_MULT_Z_POWER_POINT1 = 4,
		MULT_X_10 = 5,
		SQUARE_X = 6,
		RAISE_X_5 = 7,
		BEGIN_Y = 8,
		MULT_Y_5 = 9,
		MULT_Z_5 = 10,
		RAISE_CORE_Z_3 = 11,
		X_POWER_Y_POWER_ONE_SIXTH = 12,
		MULT_X_5 = 13,
		MULT_Z_5_NUM2 = 14,
		SQUARE_Z = 15,
		SQUARE_Y = 16,
		MULT_Y_2 = 17,
		SQUARE_X_NUM2 = 18,
		MULT_Z_10 = 19,
		CUBE_Z = 20,
		REBIRTH = 21,
		BEGIN_Z = 22,
		MULT_Y_7 = 23,
		MULT_Z_2 = 24,
	};

	enum rbUpgrade {
		BEGIN_RB_TREE = 0,
		MULT_ALL_4 = 1,
		AUTO_BUY_X = 2,
		PROD_MULT_UNSPENT_RP = 3,
		START_WITH_1e5 = 4,
		SQUARE_PROD = 5,
		AUTO_BUY_Y = 6,
		RP_MULT_50 = 7,
		X_BOOSTS_RP = 8,
		CUBE_PROD = 9,
		AUTO_BUY_Z = 10,
		RP_MULT_100 = 11,
		Y_BOOSTS_RP = 12,
		PROD_POW_5 = 13,
		GAIN_1PERCENT_RP_PER_SEC = 14,
		RP_MULT_1e5 = 15,
	};

	enum Menu {
		NORMAL_TREE,
		OPTIONS,
		RB_TREE,
	};

	static Vector3Big costs[] = {
		Vector3Big("2e4", 0, 0),
		Vector3Big("2.5e3", 0, 0),
		Vector3Big(0, 0, 0),
			Vector3Big(100, 0, 0),
			Vector3Big(0, 0, "1e3"),
			// Row 2
			Vector3Big("1e6", 0, 0),
			Vector3Big(250, 0, 0),
			Vector3Big(5, 0, 0),
			Vector3Big("1e8", 0, 0),
			Vector3Big("1e8", 0,0),
			// Row 3
			Vector3Big(0, 0, 400),
			Vector3Big(0, 0, 15),
			Vector3Big(0, 10, 0),
			Vector3Big(0, 250, 0),
			Vector3Big(0, "5e4", 0),
			// Row 4
			Vector3Big(0, 0, "1e3"),
			Vector3Big("1e9", 0, 0),
			Vector3Big(0, 100, 0),
			Vector3Big(0, "3.3e3",0),
			Vector3Big("7.1e17",0,0),
			// Row 5
			Vector3Big(0,0, "1e7"),
			Vector3Big(0,0, "1e100"),
			Vector3Big("5e16", 0, 0),
			Vector3Big(0, "1e4", 0),
			Vector3Big(0, "1e5", 0)
	};

	static std::string labels[] = {
		"Raise x production to\nthe power of 1.5.",
			"Increase core production\nof x by 25.",
			"Begin production of x.",
			"Increase core production\nof x by 10.",
			"Multiply x and y\nproduction by z^0.1.",
			// Row 2
			"Multiply x production\nby 10.",
			"Square x production.",
			"Increase x production\nby 5.",
			"Enter the era of y.",
			"Multiply y production\nby 5.",
			// Row 3
			"Multiply z production\nby 5.",
			"Increase core z\nproduction by 3",
			"x production is boosted\nby y^(1/6).",
			"Multiply x production\nby 5.",
			"Multiply z production\nby 5.",
			// Row 4
			"Square z production.",
			"Square y production.",
			"Multiply y production\nby 2.",
			"Square x production.",
			"Multiply z production\nby 10.",
			// Row 5
			"Cube z production",
			"Rebirth\n?",
			"Unlock z.",
			"Multiply y production\nby 7.",
			"Multiply z production\nby 2."
	};

	static sf::Vector2f buttonDims(175, 87.5f);
	static sf::Vector2f menuButtonDims(100, 50);

	static float xPoses[] = {
		25, 25 + buttonDims.x + 40,
			25 + (buttonDims.x + 40) * 2,
			25 + (buttonDims.x + 40) * 3,
			25 + (buttonDims.x + 40) * 4,
	};

	static float yPoses[] = {
		50, 50 + buttonDims.y + 40,
			50 + (buttonDims.y + 40) * 2,
			50 + (buttonDims.y + 40) * 3,
			50 + (buttonDims.y + 40) * 4,
			50 + (buttonDims.y + 40) * 5,
			50 + (buttonDims.y + 40) * 6,
			50 + (buttonDims.y)
	};

	static std::vector<sf::Vector2f> points = {
		sf::Vector2f(xPoses[0], yPoses[0]),
			sf::Vector2f(xPoses[1], yPoses[0]),
			sf::Vector2f(xPoses[2], yPoses[0]),
			sf::Vector2f(xPoses[3], yPoses[0]),
			sf::Vector2f(xPoses[4], yPoses[0]),
			// Row 2
			sf::Vector2f(xPoses[0], yPoses[1]),
			sf::Vector2f(xPoses[1], yPoses[1]),
			sf::Vector2f(xPoses[2], yPoses[1]),
			sf::Vector2f(xPoses[3], yPoses[1]),
			sf::Vector2f(xPoses[4], yPoses[1]),
			// Row 3
			sf::Vector2f(xPoses[0], yPoses[2]),
			sf::Vector2f(xPoses[1], yPoses[2]),
			sf::Vector2f(xPoses[2], yPoses[2]),
			sf::Vector2f(xPoses[3], yPoses[2]),
			sf::Vector2f(xPoses[4], yPoses[2]),
			// Row 4
			sf::Vector2f(xPoses[0], yPoses[3]),
			sf::Vector2f(xPoses[1], yPoses[3]),
			sf::Vector2f(xPoses[2], yPoses[3]),
			sf::Vector2f(xPoses[3], yPoses[3]),
			sf::Vector2f(xPoses[4], yPoses[3]),
			// Row 5
			sf::Vector2f(xPoses[0], yPoses[4]),
			sf::Vector2f(xPoses[1], yPoses[4]),
			sf::Vector2f(xPoses[2], yPoses[4]),
			sf::Vector2f(xPoses[3], yPoses[4]),
			sf::Vector2f(xPoses[4], yPoses[4]),
	};

	static std::vector<std::vector<int>> parents = {
		// Row 1
		{1}, {6}, {-1}, {2}, {9},
		// Row 2
		{6}, {7}, {2}, {2}, {8},
		// Row 3
		{11}, {16}, {8}, {12}, {13},
		// Row 4
		{10}, {17}, {12}, {13}, {14},
		// Row 5
		{15}, {20}, {18}, {22}, {23}
	};


