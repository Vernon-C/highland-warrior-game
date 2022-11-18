#pragma once
#include "Entity.h"

class Enemy: public Entity
{
private:
	int rewardEXP;
	int damage;

public:
	/* Default constructor */
	Enemy();

	/* Overloaded constructor */
	Enemy(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy, int _rewardEXP, int _damage);

	/* Destructor */
	~Enemy();

	/* Polymorphism: Virtual function*/
	/* Displays the enemy's status */
	void DisplayStats();

	/* Polymorphism: Virtual function*/
	/* Checks if the enemy has been defeated and provides appropriate messages */
	bool IsDefeated();

	//void TakeDamage(int _damage);

	/* Setters and getters */
	void setRewardEXP(int _rewardEXP);
	int getRewardEXP();

	void setDamage(int _damage);
	int getDamage();
};
