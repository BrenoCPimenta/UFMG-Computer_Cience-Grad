#include "houses.hpp"

void greatHouse::Words() { cout << "Each of the noble Houses of the Seven Kingdoms have their own official family motto." << endl;}
void greatHouse::Allegiance() { cout << "House status: Sovereign." << endl;}
void greatHouse::setName(string n) 
{	name = n;
	cout << endl << "Character name: " << name << endl;
}

void houseLannister::Words(bool common) 
{	if (common)
		cout << "Common words: A Lannister always pays his debts." << endl;
	else
		cout << "Words: Hear Me Roar!" << endl;
}
void houseLannister::Common() {cout << "Common motto: A Lannister always pays his debts." << endl;}

void houseBaratheon::Words() { cout << "Words: Ours is the fury!" << endl;}	

