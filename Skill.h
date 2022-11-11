#pragma once
#include "DoublyLinkedList.h"
#include <string>

using namespace std;

class Skill
{
private:
	string name;
	int damage;

public:
	/* Default constructor */
	Skill();

	/* Overloaded constructor */
	Skill(string _name, int _damage);

	/* Destructor */
	~Skill();

	/* Setters and getters */
	void setName(string _name);
	string getName();

	void setDamage(int _damage);
	int getDamage();
};
