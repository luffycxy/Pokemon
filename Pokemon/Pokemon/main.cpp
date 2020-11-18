#include <iostream>
#include <fstream>
#include <string>
#include "Move.h"
#include "Pokemon.h"
#include "PokemonTrainer.h"
using namespace std;

int main() {
	Pokemon *pm = new Pokemon[5];
	string file;
	cin >> file;
	ifstream in(file);
	for (int i = 0; i < 5; i++) {
		string name;
		string s;
		string move1, move2, move3;
		int damage1, damage2, damage3;
		getline(in, name);
		getline(in, move1);
		in >> damage1;
		getline(in, s);
		getline(in, move2);
		in >> damage2;
		getline(in, s);
		getline(in, move3);
		in >> damage3;
		getline(in, s);
		Pokemon p(name);
		pm[i] = p;
		pm[i].setMoves(move1, damage1, move2, damage2, move3, damage3);
	}
	in.close();

	cout << "List of Pokemons to choose" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Number " << i + 1 << endl;
		cout << "Name: " << pm[i].getName() << endl;
		cout << "Moves: " << pm[i].getFirstMove().name<<", " << pm[i].getSecondMove().name << ", or "<<pm[i].getThirdMove().name  << endl;
	}

	cout << endl;
	int a, b, c;
	cout << "Enter the number of the pokemon you want to add to your team: "<<endl;
	cin >> a;
	cout << "Enter the number of the pokemon you want to add to your team: " <<endl;
	cin >> b;
	cout << "Enter the number of the pokemon you want to add to your team: " <<endl;
	cin >> c;

	a = a - 1;
	b = b - 1;
	c = c - 1;

	cout << endl;
	cout << "Pokemon Team" << endl;
	cout << pm[a].getName()<< " with moves " << pm[a].getFirstMove().name << ", " << pm[a].getSecondMove().name << ", or " << pm[a].getThirdMove().name << endl;
	cout << pm[b].getName() << " with moves " << pm[b].getFirstMove().name << ", " << pm[b].getSecondMove().name << ", or " << pm[b].getThirdMove().name << endl;
	cout << pm[c].getName() << " with moves " << pm[c].getFirstMove().name << ", " << pm[c].getSecondMove().name << ", or " << pm[c].getThirdMove().name << endl;

	cout << endl;
	cout << "Prepare to fight, the battle will start now!"<<endl;
	string s;
	getline(cin, s);
	int n = 650;
		while (1) {
				cout << "Mewtwo used Psycho Cut" << endl;
				pm[a].setHealth(pm[a].getHealth() - 90);	
				if (pm[a].getHealth() <= 0) {
					cout << pm[a].getName() << " can't keep fighting" << endl;
					break;
				}
				cout << "Your current pokemon fighting is " << pm[a].getName() << endl;
				cout <<"It can use "<< pm[a].getFirstMove().name << ", " << pm[a].getSecondMove().name << ", or " << pm[a].getThirdMove().name << endl;
				
				
				string s1;
				getline(cin,s1);
				if (s1 == pm[a].getFirstMove().name) {
					cout << pm[a].getName() << " used " << s1 << endl;
					n = n - pm[a].getFirstMove().damage;
				}
				else if (s1 == pm[a].getSecondMove().name) {
					cout << pm[a].getName() << " used " << s1 << endl;
					n = n - pm[a].getSecondMove().damage;
				}	
				else {
					cout << pm[a].getName() << " used " << s1 << endl;
					n = n - pm[a].getThirdMove().damage;
				}
				
				if (n <= 0) {
					cout << "Mewtwo's health points reached 0. You win!";
					break;
				}
		}
		if (n > 0) {
			cout << pm[b].getName() << " prepares" << endl;
			while (1) {
						
						
						if (pm[b].getHealth() <= 0) {
							cout << pm[b].getName() << " can't keep fighting" << endl;
							break;
						}
						
						cout << "Your current pokemon fighting is " << pm[b].getName() << endl;
						cout << "It can use " << pm[b].getFirstMove().name << ", " << pm[b].getSecondMove().name << ", or " << pm[b].getThirdMove().name << endl;
						string s1;
						getline(cin, s1);
						cout << pm[b].getName() << " used " << s1 << endl;
						if (s1 == pm[b].getFirstMove().name)
							n = n - pm[b].getFirstMove().damage;
						else if (s1 == pm[b].getSecondMove().name)
							n = n - pm[b].getSecondMove().damage;
						else
							n = n - pm[b].getThirdMove().damage;
						cout << "Mewtwo used Psycho Cut" << endl;
						pm[b].setHealth(pm[b].getHealth() - 90);
						if (n <= 0) {
							cout << "Mewtwo's health points reached 0. You win!";
							break;
						}
					}
		}
		if (n > 0) {
			cout << pm[c].getName() << " prepares" << endl;
			while (1) {
				
				if (pm[c].getHealth() <= 0) {
					cout << pm[c].getName() << " can't keep fighting" << endl;
					break;
				}
				if (n <= 0) {
					cout << "Mewtwo's health points reached 0. You win!";
					break;
				}
				cout << "Your current pokemon fighting is " << pm[c].getName() << endl;
				cout << "It can use " << pm[c].getFirstMove().name << ", " << pm[c].getSecondMove().name << ", or " << pm[c].getThirdMove().name << endl;
				string s1;
				getline(cin, s1);
				cout << pm[c].getName() << " used " << s1 << endl;
				if (s1 == pm[c].getFirstMove().name)
					n = n - pm[c].getFirstMove().damage;
				else if (s1 == pm[c].getSecondMove().name)
					n = n - pm[c].getSecondMove().damage;
				else
					n = n - pm[c].getThirdMove().damage;
				if (n <= 0) {
					cout << "Mewtwo's health points reached 0. You win!";
					break;
				}
				cout << "Mewtwo used Psycho Cut" << endl;
				pm[c].setHealth(pm[c].getHealth() - 90);
				
				
			}

		}
	
		if (n > 0) {
			cout << "Your team health points reached 0. You lose";
		}
		


	system("pause");
	return 0;
}