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
	// Testing area

	Queue<string> messages;
	messages.push("Hello");
	messages.push("World");

	messages.push("!");

	messages.push("My");

	messages.push("name");

	messages.push("is");
	messages.push("Vernon");

	while (!messages.isEmpty())
	{
		cout << messages.peek() << endl;
		messages.pop();
	}


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

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			/* Instantiate iterator object pointer */
			Iterator* iter = new Iterator(locations, 0, sizeof(locations));
			player.Grab(iter);

			cout << endl << "\tCurrent location: " << player.GetLocation();

			///* Free up the memory */
			//delete iter;

			////////////////////////////////////////
			///          Wolf Encounter          ///
			////////////////////////////////////////

			/* Instantiate wolf object */
			Enemy wolf("Redmane Wolf", 2, 20, 20, 0, 0, 100, 5);

			cout << endl << "\tYou encounter an aggressive wolf on the outskirts of Highshore Village." << endl;

			cout << endl << "\tEntering battle..." << endl;

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			bool battleLoop = true;

			while (battleLoop)
			{
				/* Polymorphism: Displays the wolf's status */
				wolf.DisplayStats();

				/* Displays the actions the user may take */
				player.DisplayStats();
				player.DisplayActions();

				int userActionInput;

				cout << endl;
				cout << "\t";

				cin >> userActionInput;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				switch (userActionInput)
				{
				case 1:
					cout << endl << "\t" << wolf.getName() << " dealt " << wolf.getDamage() << " to you." << endl;
					player.TakeDamage(wolf.getDamage());

					///* Break from the loop if the player is defeated */
					//if (player.getCurrentHP() <= 0)
					//{
					//	cout << endl << "\t" << player.getName() << " has fainted." << endl;

					//	battleLoop = false;

					//	break;
					//}

					/* Breaks from the loop if the player is defeated */
					if (player.IsDefeated())
					{
						battleLoop = false;
						break;
					}

					/* Break from the loop if the wolf is defeated */
					cout << endl << "\tYou dealt " << player.getDamage() << " damage." << endl;
					wolf.TakeDamage(player.getDamage());

					/* Checks if the wolf has been defeated and provides appropriate messages */
					if (wolf.IsDefeated())
					{
						battleLoop = false;

						cout << "\tYou have learned a new skill." << endl;

						
					}

					/*if (wolf.getCurrentHP() <= 0)
					{
						cout << endl << "\tThe " << wolf.getName() << " has fainted." << endl;
						cout << "\tYou have gained " << wolf.getRewardEXP() << " EXP." << endl;

						battleLoop = false;

						break;
					}*/

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
			}

			/* Ends the game if the player has been defeated */
			if (player.getCurrentHP() <= 0)
			{
				/*cout << endl << "\tYou have been defeated" << endl;
				cout << "\tGame Over" << endl;*/

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
				///       Young Child Encounter       ///
				/////////////////////////////////////////

				/* Move to next location */
				player.NextLocation();
				cout << endl << "\tYour journey continues." << endl;
				cout << "\tYou enter " << player.GetLocation() << "." << endl;

				cout << endl << "\tYou see a child with a bite mark on his leg" << endl;

				Enemy child("Young child", 3, 50, 25, 0, 0, 50, 0);

				/* Stops the program until the user presses 'Enter' */
				Buffer();

				bool childEncounterLoop = true;

				while (childEncounterLoop)
				{
					/* Polymorphism: Displays the child's status */
					child.DisplayStats();

					/* Displays the actions the user may take */
					player.DisplayStats();
					player.DisplayActions();

					int userActionInput;

					cout << endl;
					cout << "\t";

					cin >> userActionInput;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}








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
