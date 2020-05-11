#include "GUIButton.h"

GUIButton::GUIButton(Vector2f position, Color color, Vector2f dims, std::string text, const char * file, Menu menu, int id)
{
	this->normal = color;
	this->rect.setPosition(position);
	this->rect.setSize(dims);
	this->rect.setFillColor(color);
	this->collider = IntRect(rect.getPosition().x, rect.getPosition().y, rect.getGlobalBounds().width, rect.getGlobalBounds().height);
	if (!this->font.loadFromFile(file))
	{
		std::cout << "Couldn't load font!" << "\n";
	}
	this->text.setFont(this->font);
	this->text.setCharacterSize(16);
	this->text.setFillColor(Color::Black);
	this->setLabels(text);
	this->menu = menu;
	this->id = id;
}

void GUIButton::renderConnection(RenderWindow & window, std::vector<GUIButton> buttonList) {
	
	for (int i : parents[id]) {
		if (parents[id][0] == -1) {
			continue;
		}
		sf::VertexArray quad(sf::Quads, 4);

		// 0 - Center of Rect - 15
		// 1 - Center of Rect + 15
		// 2 - Center of Other Rect - 15
		// 3 - Center of Other Rect + 15

		quad[0].position = this->rect.getPosition() + Vector2f(this->rect.getLocalBounds().width / 2 - 15, this->rect.getLocalBounds().height / 2 - 15);
		quad[1].position = this->rect.getPosition() + Vector2f(15 + this->rect.getLocalBounds().width / 2, 15 + this->rect.getLocalBounds().height / 2);
		quad[3].position = buttonList[i].getPosition() + Vector2f(buttonList[i].getRect().getLocalBounds().width / 2 - 15, buttonList[i].getRect().getLocalBounds().height / 2 - 15);
		quad[2].position = buttonList[i].getPosition() + Vector2f(15, 15) + Vector2f(buttonList[i].getRect().getLocalBounds().width / 2, buttonList[i].getRect().getLocalBounds().height / 2);

		if (this->rect.getPosition().x < buttonList[i].getPosition().x && this->rect.getPosition().y > buttonList[i].getPosition().y) {
			quad[0].position += Vector2f(15, 0);
			quad[2].position -= Vector2f(15, 0);
			quad[1].position -= Vector2f(15, 0);
			quad[3].position += Vector2f(15, 0);
		}

		if (this->rect.getPosition().x > buttonList[i].getPosition().x && this->rect.getPosition().y > buttonList[i].getPosition().y) {
			quad[0].position += Vector2f(15, 0);
			quad[2].position -= Vector2f(15, 0);
			quad[1].position -= Vector2f(15, 0);
			quad[3].position += Vector2f(15, 0);
		}

		window.draw(quad);
	}
}

void GUIButton::initBuy() {

	if (Player::upgrades[id]) {
		setFill(Color(102, 102, 102, 255));
	}

	this->function = [](GUIButton& t) {
		bool condition;
		if (parents[t.id][0] == -1) condition = true;
		else {
			for (int parent : parents[t.id]) {
				if (Player::upgrades[parent]) {
					condition = true;
				}
				else {
					condition = false;
					break;
				}
			}
		}
		if (costs[t.id].x > Player::x || costs[t.id].y > Player::y || costs[t.id].z > Player::z) condition = false;
		if (!Player::upgrades[t.id] && condition) {
			Player::upgrades[t.id] = true;
			t.setFill(Color(102, 102, 102, 255));
			Player::x -= costs[t.id].x;
			Player::y -= costs[t.id].y;
			Player::z -= costs[t.id].z;
			Player::calcRates();
		}
	};
}

void GUIButton::update(RenderWindow& window) {
	mouseTouching = collider.contains(Mouse::getPosition(window));

	if (mouseTouching) {
		if (Mouse::isButtonPressed(Mouse::Left)) {
			function(*this);
		}
		rect.setFillColor(hover);
	}
	else {
		rect.setFillColor(normal);
	}
}

void GUIButton::setBuyFunction(buyFunction function)
{
	this->function = function;
}

void GUIButton::syncCostLabel() {
	Vector3Big cost = costs[id];
	std::string label = "Cost: ";
	bool comma = false;
	if (cost.x > 0) {
		label += (Math::BigToString(cost.x) + "x");
		comma = true;
	}
	if (cost.y > 0) {
		if (comma) { label += ", ";}
		label += (Math::BigToString(cost.y) + "y");
		comma = true;
	}
	if (cost.z > 0) {
		if (comma) { label += ", "; }
		label += (Math::BigToString(cost.z) + "z");
		comma = true;
	}
	if (label != "Cost: ") {
		labels.push_back(label);
	}
	else {
		labels.push_back("Cost: Free");
	}
}
