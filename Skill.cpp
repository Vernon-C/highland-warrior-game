#include "Skill.h"

/* Default constructor */
Skill::Skill()
{
	name = "";
	damage = 0;
}

/* Overloaded constructor */
Skill::Skill(string _name, int _damage)
{
	name = _name;
	damage = _damage;
}

/* Destructor */
Skill::~Skill() {}

/* Setters and getters */
void Skill::setName(string _name)
{
	name = _name;
}
string Skill::getName()
{
	return name;
}

void Skill::setDamage(int _damage)
{
	damage = _damage;
}

int Skill::getDamage()
{
	return damage;
}