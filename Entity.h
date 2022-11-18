#pragma once
#include "SinglyLinkedList.h"
#include "Iterator.h"
#include <string>
#include <iostream>

using namespace std;

class Entity
{
public:  // Public type is required so that the derived classes can retrieve these variables
	string name;
	int entityID;
	int maxHP;
	int currentHP;
	int maxEnergy;
	int currentEnergy;
	SinglyLinkedList<string>* head;
	Iterator* iter;

public:
	/* Default constructor */
	Entity();

	/* Overloaded constructor */
	Entity(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy);

	/* Destructor */
	~Entity();

	/* Polymorphism: Virtual function */
	virtual void DisplayStats() = 0;
	virtual bool IsDefeated() = 0;

	/* Deducts from the entity's HP */
	void TakeDamage(int _damage);

	/* Grab iterator */
	void Grab(Iterator* _iter);

	/* Uses the iterator to move to the next element in the list */
	void NextLocation();

	/* Uses the iterator to move to the previous element in the list */
	void PreviousLocation();

	/* Dereference the current iterator element */
	string GetLocation();

	/* Setters and getters */
	void setName(string _name);
	string getName();

	void setEntityID(int _entityID);
	int getEntityID();

	void setMaxHP(int _maxHP);
	int getMaxHP();

	void setCurrentHP(int _currentHP);
	int getCurrentHP();

	void setMaxEnergy(int _maxEnergy);
	int getMaxEnergy();

	void setCurrentEnergy(int _currentEnergy);
	int getCurrentEnergy();
};
