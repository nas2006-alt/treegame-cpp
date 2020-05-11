#include "Loader.h"

bool Loader::load() {
	std::ifstream file(".\\saves\\save.txt");
	if (!file.good()) {
		return false;
	}
	std::string vNum;
	std::getline(file, vNum);
	int versionNum = std::stoi(vNum);
	
	switch (versionNum) {

	case 1:
		std::string currency;
		std::getline(file, currency);
		std::vector<std::string> currencyVector;
		splitUsingDelimiter(currency, ',', currencyVector);
		Player::x = currencyVector[0];
		Player::y = currencyVector[1];
		Player::z = currencyVector[2];

		std::string upgrades;
		std::getline(file, upgrades);
		std::vector<std::string> result;
		splitUsingDelimiter(upgrades, ',', result);
		for (int i = 0; i < Player::upgrades.size(); i++) {
			Player::upgrades[i] = result[i] == "1";
		}
	}

	return true;
}
