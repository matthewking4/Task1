//Used to hide the localtime() deprecation warming
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using namespace std;

void Initialise() {
	cout << "Initialising game" << endl;
};

void Terminate() {
	cout << "Terminating game" << endl;
};

int main() {
	Game game(2);

	GameComponent *gameComponent = new GameComponent();
	//-10 to show the fallback functionality
	DrawableGameComponent *drawableGameComponent = new DrawableGameComponent(-10, -10);
	game.SetInitialise(*Initialise);
	game.SetTerminate(*Terminate);
	game.Add(gameComponent);
	game.Add(drawableGameComponent);

	game.Run();
}