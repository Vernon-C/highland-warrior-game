#pragma once
#include "Enemy.h"
#include "Iterator.h"
#include <string>

using namespace std;

class Location
{
private:
	string name;
	Enemy enemy;
	Iterator* iter;

public:
	/* Default constructor */
	Location();

	/* Overloaded constructor */
	Location(string _name, Enemy _enemy, Iterator* _iter);

	/* Destructor */
	~Location();

	///* Grab iterator */
	//void Grab(Iterator* _iter);

	//void NextLocation();

	//void PreviousLocation();

	//void GetLocation();

	/* Setters and getters */
	void setName(string _name);
	string getName();

	void setEnemy(Enemy _enemy);
	Enemy getEnemy();
};
