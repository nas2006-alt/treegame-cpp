#include "Saver.h"

void Saver::save() {
	std::ofstream file;
	file.open(".\\saves\\save.txt");
	ttmath::Big<16, 16> tempX(Player::x), tempY(Player::y), tempZ(Player::z);
	tempX.Round();
	tempY.Round();
	tempZ.Round();
	file << VERSION;
	file << "\n";
	file << tempX << "," << tempY << "," << tempZ;
	file << "\n";
	for (bool up : Player::upgrades) {
		file << up << ",";
	}
	file.close();
}
