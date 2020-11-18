#include "PokemonTrainer.h"
using namespace std;

PokemonTrainer::PokemonTrainer() {
	maxNumberPokemons = 3;
	currentNumberPokemons = 0;
	indexPokemonFigthing = 0;
	teamHealth = 0;
	pokemons = new Pokemon[3];
}

PokemonTrainer::PokemonTrainer(int max, int current, int index, int teamH, Pokemon * p)
{
	maxNumberPokemons = max;
	currentNumberPokemons = current;
	indexPokemonFigthing = index;
	teamHealth = teamH;
	pokemons = p;
}

void PokemonTrainer::addPokemon(Pokemon p)
{
	if (currentNumberPokemons == maxNumberPokemons)
		return;
	else {
		pokemons[currentNumberPokemons] = p;
		currentNumberPokemons++;
	}
}

void PokemonTrainer::displayTeam()
{
	for (int i = 0; i < maxNumberPokemons; i++) {
		cout << pokemons[i].getName() << endl;
	}
}

int PokemonTrainer::getSelectedMoveIndex(string moveName)
{
	if (moveName == pokemons[indexPokemonFigthing].getFirstMove().name)
		return 0;
	else if (moveName == pokemons[indexPokemonFigthing].getSecondMove().name)
		return 1;
	else
		return 2;
}

int PokemonTrainer::getMaxNumberPokemons()
{
	return maxNumberPokemons;
}

int PokemonTrainer::getTeamHealth()
{
	return teamHealth;
}

int PokemonTrainer::getIndexOfCurrentPokemonFighting()
{
	return indexPokemonFigthing;
}

int PokemonTrainer::getCurrentNumberPokemons()
{
	return currentNumberPokemons;
}

string PokemonTrainer::getPokemonFigthingName()
{
	return pokemons[indexPokemonFigthing].getName();
}

int PokemonTrainer::getPokemonFightingHealth()
{
	return pokemons[indexPokemonFigthing].getHealth();
}

void PokemonTrainer::pokemonFightingAttacks(int index, Pokemon & p)
{
	pokemons[indexPokemonFigthing].move(index, p);
}

void PokemonTrainer::nextPokemonToFight()
{
	indexPokemonFigthing++;
}