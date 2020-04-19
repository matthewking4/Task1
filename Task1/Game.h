#pragma once
#include <iostream>
#include <ctime>
#include <thread>
#include "GameComponent.h"

using namespace std;

class Game {
public:
	typedef void(*FP)();
	Game(int maxComponents);
	void Add(GameComponent* gameComponent);
	void Run();
	void SetInitialise(FP);
	void SetTerminate(FP);
private:
	int maxComponents; //1) Does not exist within the spec, no other way - see point (2)
	int componentCount = 0;
	GameComponent* components[2]; //2) possible alternative is to gain maxComponents in the constructor and dynamically set this value (Folly library?)
	FP initialise;
	FP terminate;
	const int TICKS_1000MS = 1000;
};

//Constructor
Game::Game(int maxComponents) {
	this->maxComponents = maxComponents;
};

//Public Methods
void Game::Add(GameComponent* gameComponent) {
	if (this->componentCount == this->maxComponents) {
		cout << "Cannot add any more components. Max : " << this->maxComponents << endl;
		return;
	}
	else {
		this->components[componentCount] = gameComponent;
		this->componentCount++;

	}
};

void Game::Run() {
	initialise();
	int counter = 0;
	int maxRuns = 5;
	while (counter < maxRuns) {
		for (int i = 0; i < this->componentCount; i++) {
			time_t epochTime = std::time(nullptr);
			this->components[i]->Update(std::localtime(&epochTime));
		}
		this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
		counter++;
	}
	terminate();
};

void Game::SetInitialise(FP init) {
	this->initialise = *init;
};

void Game::SetTerminate(FP term) {
	this->terminate = *term;
};
