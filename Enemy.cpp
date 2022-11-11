#include "Enemy.h"
#include <iostream>

/* Default constructor */
Enemy::Enemy()
{
	rewardEXP = 0;
	damage = 0;
}

/* Overloaded constructor */
Enemy::Enemy(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy, int _rewardEXP, int _damage) : Entity(_name, _entityID, _maxHP, _currentHP, _maxEnergy, _currentEnergy)
{
	rewardEXP = _rewardEXP;
	damage = _damage;
}

/* Destructor */
Enemy::~Enemy() {}

/* Displays the wolf's status */
void Enemy::DisplayStats()
{
	cout << endl << "\t>------Wolf's Status------<" << endl;
	cout << "\tName: " << name << endl;
	cout << "\tHP: " << currentHP << "/" << maxHP << endl;
	cout << "\t>-------------------------<" << endl;
}



//void Enemy::DefeatMessage()
//{
//	cout << endl << "\tThe " << name << " has fainted." << endl;
//	cout << "\tYou have gained " << rewardEXP << " EXP." << endl;
//}

/* Checks if the enemy has been defeated and provides appropriate messages */
bool Enemy::IsDefeated()
{
	if (currentHP <= 0)
	{
		cout << endl << "\tThe " << name << " has fainted." << endl;
		cout << "\tYou have gained " << rewardEXP << " EXP." << endl;

		return true;
	}
	else
	{
		return false;
	}
}

//void Enemy::TakeDamage(int _damage)
//{
//	currentHP = currentHP - _damage;
//}

/* Setters and getters */
void Enemy::setRewardEXP(int _rewardEXP) { rewardEXP = _rewardEXP; }
int Enemy::getRewardEXP() { return rewardEXP; }

void Enemy::setDamage(int _damage) { damage = _damage; }
int Enemy::getDamage() { return damage; }
