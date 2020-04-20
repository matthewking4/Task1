#pragma once
#include <iostream>
#include <iomanip>

using namespace std;
class GameComponent {
public:
	GameComponent();
	~GameComponent();
	virtual void Update(const tm* eventTime);
private:
	int id = 1;
	static int instances;
};

//Constructor
GameComponent::GameComponent() {
	this->id = ++this->instances;
}

//Destructor
GameComponent::~GameComponent() {
	this->id = --this->id;
}

//Public Methods
void GameComponent::Update(const tm* eventTime) {
	cout << "ID : " << this->id << " Updated @ " << put_time(eventTime, "%T") << endl;
};

//Private Static assignment
int GameComponent::instances = 0;
