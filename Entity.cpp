#include "Entity.h"
#include <iostream>

/* Default constructor */
Entity::Entity()
{
	name = "";
	entityID = 0;
	maxHP = 0;
	currentHP = 0;
	maxEnergy = 0;
	currentEnergy = 0;
}

/* Overloaded constructor */
Entity::Entity(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy)
{
	name = _name;
	entityID = _entityID;
	maxHP = _maxHP;
	currentHP = _currentHP;
	maxEnergy = _maxEnergy;
	currentEnergy = _currentEnergy;
}

/* Destructor */
Entity::~Entity() {}

/* Polymorphism virtual function */
void Entity::DisplayStats()
{
	cout << endl << "Base Stats" << endl;
}

///* Adds actions to the player */
//void Entity::AddAction(string _action)
//{
//	AddListNode(&head, _action);
//}
//
//void Entity::AddListNode(SinglyLinkedList<string>** _head, string _action)
//{
//	SinglyLinkedList<string>* head = new SinglyLinkedList<string>();
//	head->item = _action;
//	head->next = (*_head);
//	(*_head) = head;
//}
//
///* Displays the player's actions */
//void Entity::DisplayActions()
//{
//	SinglyLinkedList<string>* _head = head;
//
//	cout << endl << "\tActions: " << endl;
//
//	for (int i = 1; _head != nullptr; i++)
//	{
//		cout << "\t" << i << ". " << _head->item << endl;
//		_head = _head->next;
//	}
//}

/* Deducts from the entity's HP */
void Entity::TakeDamage(int _damage)
{
	currentHP = currentHP - _damage;
}

/* Grab iterator */
void Entity::Grab(Iterator* _iter)
{
	iter = _iter;
}

/* Uses the iterator to move to the next element in the list */
void Entity::NextLocation()
{
	++(*iter);
}

/* Uses the iterator to move to the previous element in the list */
void Entity::PreviousLocation()
{
	--(*iter);
}

/* Dereference the current iterator element */
string Entity::GetLocation()
{
	return **iter;
}

/* Setters and getters */
void Entity::setName(string _name) { name = _name; }
string Entity::getName() { return name; }

void Entity::setEntityID(int _entityID) { entityID = _entityID; }
int Entity::getEntityID() { return entityID; }

void Entity::setMaxHP(int _maxHP) { maxHP = _maxHP; }
int Entity::getMaxHP() { return maxHP; }

void Entity::setCurrentHP(int _currentHP) { currentHP = _currentHP; }
int Entity::getCurrentHP() { return currentHP; }

void Entity::setMaxEnergy(int _maxEnergy) { maxEnergy = _maxEnergy; }
int Entity::getMaxEnergy() { return maxEnergy; }

void Entity::setCurrentEnergy(int _currentEnergy) { currentEnergy = _currentEnergy; }
int Entity::getCurrentEnergy() { return currentEnergy; }
