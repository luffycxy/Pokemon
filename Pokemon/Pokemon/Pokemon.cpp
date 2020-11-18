#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon() {
	health = 0;
	name = "";
}
Pokemon::~Pokemon()
{
	health = 0;
	name = "";
}
Pokemon::Pokemon(string userName) {
	name = userName;
	if (userName == "Mewtwo") {
		health = 650;
		setMoves("Psycho Cut", 90, "", 0, "", 0);
	}
	else {
		health = 270;
	}
}

string Pokemon::getName() {
	return name;
}
int Pokemon::getHealth() {
	return health;
}

Move Pokemon::getFirstMove() {
	return moves[0];
}
Move Pokemon::getSecondMove() {
	return moves[1];
}
Move Pokemon::getThirdMove() {
	return moves[2];
}

void Pokemon::setHealth(int newHealth) {
	health = newHealth;
}
void Pokemon::setMoves(string move1, int damage1, string move2, int damage2, string move3, int damage3) {
	moves[0].name = move1;
	moves[0].damage = damage1;
	moves[1].name = move2;
	moves[1].damage = damage2;
	moves[2].name = move3;
	moves[2].damage = damage3;
}

void Pokemon::move(int index, Pokemon& target) {
	target.health = target.health - moves[index].damage;
}