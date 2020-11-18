#pragma once
#include <iostream>
#include <string>
#include "Move.h"

using namespace std;

#ifndef pokemon_h
#define pokemon_h

class Pokemon {
private:
	string name;
	int health;
	Move moves[3];

public:
	Pokemon(string name);
	Pokemon();
	~Pokemon();
	int getHealth();
	string getName();

	Move getFirstMove();
	Move getSecondMove();
	Move getThirdMove();

	void setHealth(int new_health);
	void setMoves(string move1, int damage1,
		string move2, int damage2,
		string move3, int damage3);
	void move(int index, Pokemon& target);
};

#endif