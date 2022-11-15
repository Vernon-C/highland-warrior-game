#pragma once
#include "Entity.h"
#include "DoublyLinkedList.h"
#include "Skill.h"
#include "Stack.h"

class Player: public Entity
{
private:
	int level;
	int currentEXP;
	int damage;
	Stack<string> armour;
	int armourCount;

public:
	/* Default constructor */
	Player();

	/* Overloaded constructor */
	Player(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy, int _level, int _currentEXP, int _damage);

	/* Destructor */
	~Player();

	/* Polymorphism: Virtual function*/
	/* Displays the player's statistics */
	void DisplayStats();

	/* Polymorphism: Virtual function*/
	/* Checks if the player has been defeated and provides appropriate messages */
	bool IsDefeated();

	/* Adds actions to the player */
	void AddAction(string _action);
	void AddListNode(SinglyLinkedList<string>** _head, string _action);

	/* Displays the player's actions */
	void DisplayActions();

	/* Updates the player's status */
	void UpdateStats();

	/* Add a skill */
	void AddSkill();  // Work on this

	/* Add armour to stack */
	void AddArmour(string _armour)
	{
		armour.push(_armour);
		armourCount++;
	}

	/* Remove armour from stack */
	void DestroyArmour()
	{
		// Display the armour name before popping it
		cout << endl << "\tArmour destroyed: " << armour.peek() << endl;
		armour.pop();
		armourCount--;
	}

	/* Setters and getters */
	void setLevel(int _level);
	int getLevel();

	void setCurrentEXP(int _currentEXP);
	int getCurrentEXP();

	void setDamage(int _damage);
	int getDamage();

	bool armourIsEmpty();
};
