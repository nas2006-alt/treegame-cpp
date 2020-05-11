#include "Player.h"

std::vector<bool> Player::upgrades{ {} }, Player::rbUpgrades{ {} };
std::vector<ttmath::Big<16, 16>> Player::Rates{ {} };
ttmath::Big<16, 16> Player::x{}, Player::y{}, Player::z{};
ttmath::Big<8, 8> Player::RP{};

void Player::initConstants() {
	for (int x = 0; x < 25; x++) {
		upgrades.push_back(false);
	}
	for (int x = 0; x < 16; x++) {
		rbUpgrades.push_back(false);
	}
}

void Player::reset(bool keepRp) {
	if (!keepRp) Player::RP = "0";
	Player::x = "0"; Player::y = "0"; Player::z = "0";
	Player::Rates = { "0", "0", "0" };
}

void Player::calcRates() {
	calcX();
	calcY();
	calcZ();
}

void Player::calcX() {
	ttmath::Big<16, 16> res = 0;
	if (Player::upgrades[RAISE_CORE_X_25]) {
		res += 25;
	} if (Player::upgrades[RAISE_CORE_X_10]) {
		res += 10;
	} if (Player::upgrades[RAISE_X_1POINT5]) {
		res.Pow(1.5);
	} if (Player::upgrades[BEGIN_X]) {
		res += 1;
	} if (Player::upgrades[MULT_X_10]) {
		res *= 10;
	} if (Player::upgrades[SQUARE_X]) {
		res.Pow(2);
	} if (Player::upgrades[RAISE_X_5]) {
		res += 5;
	} if (Player::upgrades[MULT_X_5]) {
		res *= 5;
	} if (Player::upgrades[SQUARE_X_NUM2]) {
		res *= res;
	} if (Player::rbUpgrades[MULT_ALL_4]) {
		res *= 4;
	} if (Player::rbUpgrades[SQUARE_PROD]) {
		res *= res;
	} if (Player::rbUpgrades[CUBE_PROD]) {
		res *= res * res;
	} if (Player::rbUpgrades[PROD_POW_5]) {
		res *= res * res * res * res;
	} if (Player::upgrades[X_AND_Y_MULT_Z_POWER_POINT1]) {
		ttmath::Big<16, 16> zClone(Player::z);
		res *= (zClone.Pow(0.1)) > 1 ? (zClone.Pow(0.1)) : 1;
	} if (Player::upgrades[X_POWER_Y_POWER_ONE_SIXTH]) {
		ttmath::Big<16, 16> yClone(Player::y);
		res.Pow((yClone.Pow(0.16666666667)) > 1 ? (yClone.Pow(0.16666666667)) : 1);
	} if (Player::rbUpgrades[PROD_MULT_UNSPENT_RP]) {
		res *= Player::RP > 1 ? Player::RP : 1;
	}

	Player::Rates[0] = res;
}

void Player::calcY() {

	ttmath::Big<16, 16> res = 0;

	if (Player::upgrades[BEGIN_Y]) {
		res+= 1;
	} if (Player::upgrades[MULT_Y_5]) {
		res *= 5;
	} if (Player::upgrades[SQUARE_Y]) {
		res.Pow(2);
	} if (Player::upgrades[MULT_Y_2]) {
		res *= 2;
	} if (Player::upgrades[MULT_Y_7]) {
		res *= 7;
	} if (Player::rbUpgrades[MULT_ALL_4]) {
		res *= 5;
	} if (Player::rbUpgrades[SQUARE_PROD]) {
		res.Pow(2);
	} if (Player::rbUpgrades[CUBE_PROD]) {
		res.Pow(3);
	} if (Player::rbUpgrades[PROD_POW_5]) {
		res = res.Pow(5);
	} if (Player::upgrades[X_AND_Y_MULT_Z_POWER_POINT1]) {
		ttmath::Big<16, 16> zClone(Player::z);
		res *= (zClone.Pow(0.1)) > 1 ? (zClone.Pow(0.1)) : 1;
	} if (Player::rbUpgrades[PROD_MULT_UNSPENT_RP]) {
		res *= Player::RP > 1 ? Player::RP : 1;
	}

	Player::Rates[1] = res;
}

void Player::calcZ() {

	ttmath::Big<16, 16> res = 0;

	if (Player::upgrades[RAISE_CORE_Z_3]) {
		res += 3;
	} if (Player::upgrades[MULT_Z_5]) {
		res *= 5;
	} if (Player::upgrades[MULT_Z_5_NUM2]) {
		res *= 5;
	} if (Player::upgrades[SQUARE_Z]) {
		res.Pow(2);
	} if (Player::upgrades[MULT_Z_10]) {
		res *= 10;
	} if (Player::upgrades[CUBE_Z]) {
		res.Pow(3);
	} if (Player::upgrades[BEGIN_Z]) {
		res += 1;
	} if (Player::upgrades[MULT_Z_2]) {
		res *= 2;
	} if (Player::rbUpgrades[MULT_ALL_4]) {
		res *= 5;
	} if (Player::rbUpgrades[SQUARE_PROD]) {
		res.Pow(2);
	} if (Player::rbUpgrades[CUBE_PROD]) {
		res.Pow(3);
	} if (Player::rbUpgrades[PROD_POW_5]) {
		res.Pow(5);
	} if (Player::rbUpgrades[PROD_MULT_UNSPENT_RP]) {
		res *= Player::RP > 1 ? Player::RP : 1;
	}

	Player::Rates[2] = res;

}