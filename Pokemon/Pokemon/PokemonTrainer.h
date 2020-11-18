#pragma once
#include <iostream>
#include <string>
#include "Move.h"
#include "Pokemon.h"

using namespace std;

#ifndef pokemonTrainer_h
#define pokemonTrainer_h

class PokemonTrainer {
private:
	int maxNumberPokemons;
	int currentNumberPokemons;
	int indexPokemonFigthing;
	int teamHealth;
	Pokemon* pokemons;

public:
	PokemonTrainer();
	PokemonTrainer(int maxNumberPokemons, int currentNumberPokemons, int indexPokemonFigthing, int teamHealth, Pokemon* pokemons);
	void addPokemon(Pokemon p);
	void displayTeam();
	int getSelectedMoveIndex(string moveName);
	int getMaxNumberPokemons();
	int getTeamHealth();
	int getIndexOfCurrentPokemonFighting();
	int getCurrentNumberPokemons();
	string getPokemonFigthingName();
	int getPokemonFightingHealth();
	void pokemonFightingAttacks(int index, Pokemon &p);
	void nextPokemonToFight();
};












#endif
