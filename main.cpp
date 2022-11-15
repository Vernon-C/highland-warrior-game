#include "Player.h"
#include "Enemy.h"
#include "SinglyLinkedList.h"
#include "Location.h"
#include "Iterator.h"
#include "Skill.h"
#include "DoublyLinkedList.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;

void DisplayMainMenu();
int GetUserMenuInput();
void DisplayBackstory(string _playerName);
void Buffer();
void Battle(Enemy _enemy, Player* _player);

/* Pet object using a struct method */
//struct Pet
//{
//	string name;
//	int heal;
//
//	Pet()
//	{
//		name = "";
//		heal = 0;
//	}
//
//	Pet(string _name, int _heal)
//	{
//		name = _name;
//		heal = _heal;
//	}
//
//	~Pet() {};
//};

/* Item object using a struct method */
struct Item
{
	string name;
	int HP;
	int value;

	Item()
	{
		name = "";
		HP = 0;
		value = 0;
	}

	Item(string _name, int _HP, int _energy)
	{
		name = _name;
		HP = _HP;
		value = _energy;
	}

	~Item() {};
};

int main()
{
	//string actions[] = { "Attack","Run" };
	Item items[] = { Item("Bandages", 20, 0),Item("Sweet Roll", 10, 0),Item("Health Potion", 50, 0),Item("Gold Pouch", 0, 100) };
	string locations[] = { "Lir's Reach","Highshore Village","Farcrag Castle","Stonevale" };

	bool programStatus = true;

	while (programStatus)
	{
		/* Displays the menu options */
		DisplayMainMenu();

		/* Get the user's menu option and validates it */
		int userMenuInput = GetUserMenuInput();

		/* Game start */
		switch (userMenuInput)
		{
		case 1:
		{
			/* SFML: Plays background music */
			sf::Music music;

			if (!music.openFromFile("BGM.wav"))
				cout << endl << "Error: Music couldn't be played" << endl;

			music.play();

			cout << endl << "\t>------New Game------<" << endl;
			cout << "\tEnter player name: ";

			string playerName;
			cin >> playerName;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			/* Instantiate the player object */
			Player player(playerName, 1, 100, 100, 100, 100, 0, 0, 10);

			/* Add actions to the player object */
			player.AddAction("Use Item");
			player.AddAction("Escape");
			player.AddAction("Attack");

			/* Displays text on the backstory of the game */
			DisplayBackstory(playerName);

			/* Polymorphism: Displays the player's status */
			player.DisplayStats();

			/* Foot soldier encounter*/

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			/* Instantiate iterator object pointer */
			Iterator* iter = new Iterator(locations, 0, sizeof(locations));
			player.Grab(iter);

			cout << endl << "\tCurrent location: " << player.GetLocation();

			////////////////////////////////////////
			///          Wolf Encounter          ///
			////////////////////////////////////////

			/* Instantiate wolf object */
			Enemy wolf("Redmane Wolf", 2, 20, 20, 0, 0, 100, 5);

			cout << endl << "\tYou encounter an aggressive wolf on the outskirts of Highshore Village." << endl;

			cout << endl << "\tEntering battle..." << endl;

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			/* Starts battle sequence */
			Battle(wolf, &player);

			/* Ends the game if the player has been defeated */
			if (player.getCurrentHP() <= 0)
			{
				if (player.IsDefeated())
					programStatus = false;
				
				break;
			}

			Buffer();

			int userLocationAction;
			cout << endl << "\tWhat do you wish to do?" << endl;
			cout << "\tActions:" << endl;
			cout << "\t1. Enter Highshore Village" << endl;
			cout << "\t2. Quit the game" << endl;

			cout << "\t";
			cin >> userLocationAction;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			switch (userLocationAction)
			{
			case 1:
			{
				/////////////////////////////////////////
				///       Blacksmith Encounter       ///
				/////////////////////////////////////////

				/* Accept helmet */
				cout << endl << "\tVillage Blacksmith: You're the one who slained the wolf weren't you?" << endl;
				cout << "\tVillage Blacksmith: Please, accept this helmet (armour +1)" << endl;
				cout << "\tDo you accept?: ";

				string acceptHelmet = "";

				cin >> acceptHelmet;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				/* Add armour if the player accepts */
				if (acceptHelmet == "yes")
					player.AddArmour("helmet");

				/* Accept breastplate */
				cout << endl << "\tVillage Blacksmith: Please, accept this breatsplate (armour +2)" << endl;
				cout << "\tDo you accept?: ";

				string acceptBreastplate = "";

				cin >> acceptBreastplate;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				/* Add armour if the player accepts */
				if (acceptBreastplate == "yes")
					player.AddArmour("breastplate");

				/////////////////////////////////////////
				///             Ghoul Encounter       ///
				/////////////////////////////////////////


				/* Move to next location */
				player.NextLocation();
				cout << endl << "\tYour journey continues." << endl;
				cout << "\tYou enter " << player.GetLocation() << "." << endl;

				cout << endl << "\tYou see a figure in the wheat field of the village" << endl;
				cout << "\tIt appears hostile" << endl;
				cout << endl << "\tEntering battle..." << endl;

				Enemy ghoul("Ghoul", 2, 40, 40, 0, 0, 100, 5);

				/* Stops the program until the user presses 'Enter' */
				Buffer();

				/* Starts battle sequence */
				Battle(ghoul, &player);

				cout << endl << "\tYou have completed the game" << endl;

				/* Return to the previous location */
				player.PreviousLocation();
				cout << endl << "\tYour journey continues." << endl;
				cout << "\tYou enter " << player.GetLocation() << "." << endl;

				break;
			}
			case 2:
			{
				//programStatus = false;
				break;
			}
			default:
				cout << endl << "\tSorry, that is an invalid input." << endl;
				cout << "\tPlease try again." << endl;

				break;
			}
			
			/////////////////////////////////////////
			///       Rude Knight Encounter       ///
			/////////////////////////////////////////

			/* Free up the memory */
			delete iter;

			system("pause");
			
			break;
		}
		case 2:
			programStatus = false;

			cout << endl << "\tThank you for playing!" << endl;
			cout << "\tGoodbye!" << endl;

			break;
		default:
			cout << endl << "\tSorry, that is an invalid input." << endl;
			cout << "\tPlease try again." << endl;

			break;
		}
	}

	return 0;
}

/* Displays the menu options */
void DisplayMainMenu()
{
	cout << endl << "\t>------Main Menu------<" << endl;
	cout << "\t1. Play" << endl;
	cout << "\t2. Exit" << endl;
	cout << "\t>---------------------<" << endl;
}

/* Get the user's menu option and validates it */
int GetUserMenuInput()
{
	int userMenuInput;

	cout << "\tEnter a command: ";
	cin >> userMenuInput;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	/* Validates the user's input for the menu options */
	while (true)
	{
		if (cin.fail())
		{
			cout << endl << "\tSorry, that is an invalid input." << endl;
			cout << "\tPlease try again." << endl << endl;
			cout << "\tEnter a command: ";

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> userMenuInput;
		}

		if (!cin.fail())
			break;
	}

	return userMenuInput;
}

/* Displays text on the backstory of the game */
void DisplayBackstory(string _playerName)
{
	cout << endl << "\t>-----------------------------Backstory-----------------------------<" << endl;
	cout << "\tWelcome to the Lir's Reach." << endl;
	cout << "\tA once peaceful land teeming with life and people." << endl;
	cout << "\tHowever, ever since the Morrigan, an evil goddess, became discontent," << endl;
	cout << "\tthe once peaceful creatures of the land started to become aggressive." << endl;
	cout << "\tThreatening the lives of everyone." << endl << endl;

	cout << "\tYou're name is " << _playerName << "." << endl;
	cout << "\tAn aspiring adventurer looking to make a name for themselves," << endl;
	cout << "\tyou aim to erradicate the Morrigan's influence on these lands." << endl;
	cout << "\t>-------------------------------------------------------------------<" << endl;

	/* Stops the program until the user presses 'Enter' */
	Buffer();
}

/* Stops the program until the user presses 'Enter' */
void Buffer()
{
	cout << "\t...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/* Starts battle sequence */
void Battle(Enemy _enemy, Player* _player)
{
	int battleLoop = true;
	Player p = *_player;

	while (battleLoop)
	{
		/* Polymorphism: Displays the wolf's status */
		_enemy.DisplayStats();

		/* Displays the actions the user may take */
		p.DisplayStats();
		p.DisplayActions();

		int userActionInput;

		cout << endl;
		cout << "\t";

		cin >> userActionInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << userActionInput;

		switch (userActionInput)
		{
		case 1:
			cout << endl << "\t" << _enemy.getName() << " dealt " << _enemy.getDamage() << " to you." << endl;

			/* Destroy armour if the player has armour */
			if (!p.armourIsEmpty())
				p.DestroyArmour();
			else
				p.TakeDamage(_enemy.getDamage());

			/* Breaks from the loop if the player is defeated */
			if (p.IsDefeated())
			{
				battleLoop = false;
				break;
			}

			cout << endl << "\tYou dealt " << p.getDamage() << " damage." << endl;
			_enemy.TakeDamage(p.getDamage());

			/* Checks if the ghoul has been defeated and provides appropriate messages */
			if (_enemy.IsDefeated())
			{
				p.DisplayStats();
				battleLoop = false;
			}

			break;
		case 2:
			cout << endl << "\tYou have escaped." << endl;
			battleLoop = false;

			break;
		case 3:
			cout << "\tYou may not use items when in a battle." << endl;

			break;
		default:
			cout << "\tInvalid input. Please try again." << endl;
			break;
		}

		*_player = p;
	}
}
