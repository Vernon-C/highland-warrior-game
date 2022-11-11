#include "Location.h"

/* Default constructor */
Location::Location()
{
	name = "";
}

/* Overloaded constructor */
Location::Location(string _name, Enemy _enemy, Iterator* _iter)
{
	name = _name;
	enemy = _enemy;
	iter = _iter;
}

/* Destructor */
Location::~Location() {}

///* Grab iterator */
//void Location::Grab(Iterator* _iter)
//{
//	iter = _iter;
//}
//
//void Location::NextLocation()
//{
//	++(*iter);
//}
//
//void Location::PreviousLocation()
//{
//	--(*iter);
//}
//
//void Location::GetLocation()
//{
//	cout << **iter << endl;
//}

/* Setters and getters */
void Location::setName(string _name) { name = _name; }
string Location::getName() { return name; }

void Location::setEnemy(Enemy _enemy) { enemy = _enemy; }
Enemy Location::getEnemy() { return enemy; }
