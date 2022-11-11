#include "Player.h"
#include <iostream>

/* Default constructor */
Player::Player()
{
	level = 0;
	currentEXP = 0;
	damage = 0;
}

/* Overloaded constructor */
Player::Player(string _name, int _entityID, int _maxHP, int _currentHP, int _maxEnergy, int _currentEnergy, int _level, int _currentEXP, int _damage): Entity(_name, _entityID, _maxHP, _currentHP, _maxEnergy, _currentEnergy)
{
	level = _level;
	currentEXP = _currentEXP;
	damage = _damage;
}

/* Destructor */
Player::~Player()
{
}

/* Displays the player's status */
void Player::DisplayStats()
{
	cout << endl << "\t>------Current Status------<" << endl;
	cout << "\tName: " << name << endl;
	cout << "\tHP: " << currentHP << "/" << maxHP << endl;
	cout << "\tEnergy: " << currentEnergy << "/" << maxEnergy << endl;
	cout << "\t>--------------------------<" << endl;
}

/* Checks if the enemy has been defeated and provides appropriate messages */
bool Player::IsDefeated()
{
	if (currentHP <= 0)
	{
		cout << endl << "\tYou have been defeated" << endl;
		cout << "\tGame Over" << endl;

		return true;
	}
	else
	{
		return false;
	}
}

/* Adds actions to the player */
void Player::AddAction(string _action)
{
	AddListNode(&head, _action);
}

void Player::AddListNode(SinglyLinkedList<string>** _head, string _action)
{
	SinglyLinkedList<string>* head = new SinglyLinkedList<string>();
	head->item = _action;
	head->next = (*_head);
	(*_head) = head;
}

/* Displays the player's actions */
void Player::DisplayActions()
{
	SinglyLinkedList<string>* _head = head;

	cout << endl << "\tActions: " << endl;

	for (int i = 1; _head != nullptr; i++)
	{
		cout << "\t" << i << ". " << _head->item << endl;
		_head = _head->next;
	}
}

/* Updates the player's status */
void Player::UpdateStats()
{
	switch (currentEXP)
	{
	case 100:
		level = 1;
		maxHP = 100;
		damage = 10;

		break;
	case 200:
		maxHP = 110;
		damage = 20;
		level = 2;

		break;
	case 300:
		maxHP = 120;
		damage = 30;
		level = 3;

		break;
	case 400:
		maxHP = 130;
		damage = 40;
		level = 4;

		break;
	case 500:
		maxHP = 140;
		damage = 50;
		level = 5;

		break;
	default:
		maxHP = 150;
		damage = 10;
		level = 1;

		break;
	}
}

/* Add a skill */
void Player::AddSkill()
{

}

/* Setters and getters */
void Player::setLevel(int _level) { level = _level; }
int Player::getLevel() { return level; }

void Player::setCurrentEXP(int _currentEXP) { currentEXP = _currentEXP; }
int Player::getCurrentEXP() { return currentEXP; }

void Player::setDamage(int _damage) { damage = _damage; }
int Player::getDamage() { return damage; }
