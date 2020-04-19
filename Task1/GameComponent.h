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
	int id;
	static int instances;
};

//Constructor
GameComponent::GameComponent() {
	int incId = ++this->instances;
	this->id = incId;
}

//Destructor
GameComponent::~GameComponent() {
	int decId = --this->id;
	this->id = decId;
}

//Public Methods
void GameComponent::Update(const tm* eventTime) {
	cout << "ID : " << this->id << " Updated @ " << put_time(eventTime, "%T") << endl;
};

//Private Static assignment
int GameComponent::instances = 0;
