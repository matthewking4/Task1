#pragma once
#include <iostream>
#include <string>
#include "GameComponent.h"
#include <random>

using namespace std;

const char *enumTypes[] = { "Left", "Right", "Up", "Down" };
enum Direction {
	Left,
	Right,
	Up,
	Down
};


class DrawableGameComponent : public GameComponent {
public:
	Direction direction;
	DrawableGameComponent(int x, int y);
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_WIDTH = 80;
	void Update(const tm* eventTime) override;
private:
	void ChangeDirection();
	void Draw();
	int x = 0;
	int y = 0;
};

//Constructor
DrawableGameComponent::DrawableGameComponent(int x, int y) {
	direction = Right;
	if (x > 0)this->x = x;
	if (y > 0)this->y = y;
};


//Public Methods
void DrawableGameComponent::Update(const tm* eventTime) {
	GameComponent::Update(eventTime);

	switch (this->direction) {
	case Left:
		--this->x;
		if (x < 0) this->x = 0;
		break;
	case Right:
		++this->x;
		if (x > SCREEN_WIDTH) this->x = SCREEN_WIDTH;
		break;
	case Up:
		++this->y;
		if (y > SCREEN_HEIGHT) y = SCREEN_HEIGHT;
		break;
	case Down:
		--this->y;
		if (y < 0) this->y = 0;
		break;
	default:
		this->x = 0;
		this->y = 0;
		break;
	}

	Draw();
	ChangeDirection();
};

//Private Methods
void DrawableGameComponent::ChangeDirection() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 3);
	int randomNumber = distribution(generator);

	while (randomNumber == this->direction) {
		randomNumber = distribution(generator);
	}

	this->direction = static_cast<Direction>(randomNumber);
};

void DrawableGameComponent::Draw() {
	cout << enumTypes[this->direction] << " : " << "X:" << x << " Y:" << y << endl;
};
