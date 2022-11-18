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

/* Item object using a struct method */
struct Item
{
	string name;
	int HP;

	Item()
	{
		name = "";
		HP = 0;
	}

	Item(string _name, int _HP)
	{
		name = _name;
		HP = _HP;
	}

	~Item() {};
};

void DisplayMainMenu();
int GetUserMenuInput();
void DisplayBackstory(string _playerName);
void Buffer();
void Battle(Enemy* _enemy, Player* _player, Queue<string>* _endingMessages, Item _items[], int* _sizeOfItems);

List<string> braveryRating;

int main()
{
	bool programStatus = true;

	while (programStatus)
	{
		/* Array of struct items */
		Item items[] = { Item("Bandages", 20),Item("Sweet Roll", 10),Item("Health Potion", 50) };
		int sizeOfItems = 3;

		Queue<string> endingMessages;  // Holds the ending messages the player earns throughout the game

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

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			string locations[] = { "Lir's Reach","Highshore Village","Farcrag Castle","Stonevale" };

			/* Instantiate iterator object pointer */
			Iterator* iter = new Iterator(locations, 0, sizeof(locations));
			player.Grab(iter);

			/* Showcases Iterator */
			cout << endl << "\tCurrent location: " << player.GetLocation();

			////////////////////////////////////////
			///          Wolf Encounter          ///
			////////////////////////////////////////

			/* Instantiate wolf object */
			Enemy wolf("Redmane Wolf", 2, 20, 20, 0, 0, 150, 5);

			cout << endl << "\tYou encounter an aggressive wolf on the outskirts of Highshore Village." << endl;

			cout << endl << "\tEntering battle..." << endl;

			/* Stops the program until the user presses 'Enter' */
			Buffer();

			/* Starts battle sequence */
			Battle(&wolf, &player, &endingMessages, items, &sizeOfItems);

			/* Ends the game if the player has been defeated */
			if (player.IsDefeated())
				break;

			Buffer();

			/* Dialogue */
			cout << endl << "\tStory:" << endl;
			cout << endl << "\t" << player.getName() << ": That wolf moved and attacked rather unnaturally." << endl;
			Buffer();
			cout << "\t" << player.getName() << ": Almost as if it was being controlled." << endl;
			Buffer();
			cout << "\t" << player.getName() << ": I should look around and report this to a guard." << endl;
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
				/* Move to next location */
				player.NextLocation();
				cout << endl << "\tYour journey continues." << endl;
				cout << "\tYou enter " << player.GetLocation() << "." << endl;

				//////////////////////////////////////////
				///        Blacksmith Encounter        ///
				//////////////////////////////////////////

				/* This area demonstrates the stack LIFO: Last in First out */

				/* Accept helmet */
				cout << endl << "\tVillage Blacksmith: You're the one who slained the wolf weren't you?" << endl;
				cout << "\tVillage Blacksmith: Please, accept this helmet (armour +1)" << endl;
				cout << "\tDo you accept?: ";

				string acceptHelmet = "";

				cin >> acceptHelmet;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				/* Add armour if the player accepts */
				if (acceptHelmet == "yes" || acceptHelmet == "y" || acceptHelmet == "Y")
					player.AddArmour("helmet");

				/* Accept breastplate */
				cout << endl << "\tVillage Blacksmith: Please, accept this breatsplate (armour +1)" << endl;
				cout << "\tDo you accept?: ";

				string acceptBreastplate = "";

				cin >> acceptBreastplate;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				/* Add armour if the player accepts */
				if (acceptBreastplate == "yes" || acceptBreastplate == "y" || acceptBreastplate == "Y")
					player.AddArmour("breastplate");

				/* Accept boots */
				cout << "\tVillage Blacksmith: Please, accept these steel boots (armour +1)" << endl;
				cout << "\tDo you accept?: ";

				string acceptBoots = "";

				cin >> acceptBoots;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				/* Add armour if the player accepts */
				if (acceptBoots == "yes" || acceptBoots == "y" || acceptBoots == "Y")
					player.AddArmour("steel boots");

				///////////////////////////////////////////
				///           Ghoul Encounter           ///
				///////////////////////////////////////////

				cout << endl << "\tYou see a figure in the wheat field of the village" << endl;
				cout << "\tIt appears hostile" << endl;
				cout << endl << "\tEntering battle..." << endl;

				Enemy ghoul("Ghoul", 2, 40, 40, 0, 0, 100, 5);

				/* Stops the program until the user presses 'Enter' */
				Buffer();

				/* Starts battle sequence */
				Battle(&ghoul, &player, &endingMessages, items, &sizeOfItems);

				/* Ends the game if the player has been defeated */
				if (player.IsDefeated())
					break;

				///////////////////////////////////////////////////////////
				//      Move back to Lir's Reach: Showcaes Iterator      //
				///////////////////////////////////////////////////////////

				/* Dialogue */
				cout << endl << "\t*The village guard approaches you*" << endl;
				Buffer();
				cout << "\tGuard: What was that unnatural creature." << endl;
				cout << "\tGuard: I can't leave my post, but you should report this to the lord at Farcrag Castle." << endl;
				Buffer();
				cout << "\t" << player.getName() <<  ": I shall do just that." << endl;
				cout << "\t" << player.getName() << ": I will have to return to Lir's Reach first to get to the castle." << endl;
				Buffer();

				/* Return to the previous location: Showcases Iterator */
				player.PreviousLocation();
				cout << endl << "\tYour journey continues." << endl;
				cout << "\tYou enter " << player.GetLocation() << "." << endl;

				/* Re-initiates wolf battle is the wolf is still alive */
				if (wolf.getCurrentHP() > 0)
				{
					/* Starts battle sequence */
					Battle(&wolf, &player, &endingMessages, items, &sizeOfItems);
				}

				/* Dialogue */
				cout << endl << "\t*You wander around Lir's Reach*" << endl;
				Buffer();
				cout << "\t" << player.getName() << ": Finally, I'm outside the castle." << endl;
				cout << "\t[Press any button to enter]" << endl;
				
				Buffer();

				/* Iterate twice to get to the next next location */
				player.NextLocation();
				player.NextLocation();

				cout << endl << "\t*You arrive at " << player.GetLocation() << "*" << endl;

				//////////////////////////////////////////////////
				///           Drunk Knight Encounter           ///
				//////////////////////////////////////////////////

				cout << endl << "\tYou are stopped by a knight patroling the castle." << endl;
				cout << "\tShe appears to be drunk and aggressive" << endl;
				cout << endl << "\tEntering battle..." << endl;

				Enemy knight("Drunk Knight", 2, 40, 40, 0, 0, 100, 5);

				/* Stops the program until the user presses 'Enter' */
				Buffer();

				/* Starts battle sequence */
				Battle(&knight, &player, &endingMessages, items, &sizeOfItems);

				/* Ends the game if the player has been defeated */
				if (player.IsDefeated())
					break;

				/* Dialogue */
				cout << endl << "\t" << knight.getName() << ": You're not that sneaky rogue." << endl;
				cout << "\t" << knight.getName() << ": Bugger stole my sweet roll." << endl;
				cout << "\t" << knight.getName() << ": *walks away*" << endl;
				Buffer();
				cout << "\t" << player.getName() << ": That was a rather uncomfortable encounter." << endl;
				cout << "\t" << player.getName() << ": I need to find the lord of this castle." << endl;
				Buffer();

				cout << "\t*You find the lord*" << endl;
				cout << "\t" << player.getName() << ": *You report of the unnatural events you experienced." << endl;
				cout << "\tLord Maclir: These events may have been caused by the red meteorite that was seen in the sky recently." << endl;
				cout << "\tLord Maclir: Thank you for telling me this " << player.getName() << "." << endl;
				cout << "\tLord Maclir: Lord Macroin had recently sent a messenger with a similar tale to yours." << endl;
				cout << "\tLord Maclir: I need you to go visit him at Stonevale and report back what you see." << endl;
				Buffer();
				cout << "\t" << player.getName() << ": Understood." << endl;

				cout << "\t[Press any button to proceeed to Stonevale]" << endl;

				player.NextLocation();

				/* Showcases Iterator */
				cout << endl << "\tCurrent location: " << player.GetLocation();

				cout << endl << "\tYour journey is over for now" << endl;
				cout << "\tBut the adventure to be had in " << player.GetLocation() << " is yet to be seen. Until then!" << endl;

				break;
			}
			case 2:
			{
				programStatus = false;
				break;
			}
			default:
				cout << endl << "\tSorry, that is an invalid input." << endl;
				cout << "\tPlease try again." << endl;

				break;
			}

			if (!programStatus)
				break;

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

		/////////////////////
		//    Game Over    //
		/////////////////////

		cout << endl << "\tYou have completed the game" << endl;
		Buffer();
		cout << "\tYour jouney has ended for now. But the adventure may continue in the future." << endl;
		cout << endl << "\tYour progress:" << endl;

		while (!endingMessages.isEmpty())
		{
			cout << "\t" << endingMessages.peek() << endl;
			endingMessages.pop();
		}

		/* Shows DoublyLinkedList usage with an ADT List */
		int couragiousCount = 0;
		int cowardCount = 0;
		string braveryResult;

		for (int i = 0; i < braveryRating.size(); i++)
		{
			if (braveryRating[i] == "coward")
			{
				braveryRating.remove("couragious");
				cowardCount += 1;
			}
		}

		for (int i = 0; i < braveryRating.size(); i++)
		{
			if (braveryRating[i] == "couragious")
				couragiousCount += 1;
		}

		cout << endl << "\tCourage points: " << couragiousCount << "\tCoward points: " << cowardCount << endl;

		if (cowardCount > couragiousCount)
			braveryResult = "Coward";
		else if (couragiousCount == cowardCount)
			braveryResult = "Average";
		else if (couragiousCount > cowardCount)
			braveryResult = "Brave";
		else
			braveryResult = "Error";

		cout << endl << "\tBravery Result: " << braveryResult << endl;
	}

	return 0;
}

/* Displays the menu options */
void DisplayMainMenu()
{
	cout << endl << "\t>----------------------------<" << endl;
	cout << "\t>----- Highland Warrior -----<" << endl;
	cout << "\t>----------------------------<" << endl;

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
void Battle(Enemy* _enemy, Player* _player, Queue<string>* _endingMessages, Item _items[], int* _sizeOfItems)
{
	int battleLoop = true;
	Player p = *_player;
	Enemy enemy = *_enemy;

	p.UpdateStats();

	while (battleLoop)
	{
		/* Polymorphism: Displays the wolf's status */
		enemy.DisplayStats();

		/* Displays the actions the user may take */
		p.DisplayStats();
		p.DisplayActions();

		int userActionInput;

		cout << endl;
		cout << "\t";

		cin >> userActionInput;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (userActionInput)
		{
		case 1:
			cout << endl << "\t" << enemy.getName() << " dealt " << enemy.getDamage() << " to you." << endl;

			/* Destroy armour if the player has armour */
			if (!p.armourIsEmpty())
				p.DestroyArmour();
			else
				p.TakeDamage(enemy.getDamage());

			/* Breaks from the loop if the player is defeated */
			if (p.IsDefeated())
			{
				battleLoop = false;
				break;
			}

			cout << endl << "\tYou dealt " << p.getDamage() << " damage." << endl;
			enemy.TakeDamage(p.getDamage());

			/* Checks if the ghoul has been defeated and provides appropriate messages */
			if (enemy.IsDefeated())
			{
				p.setCurrentEXP(p.getCurrentEXP() + enemy.getRewardEXP());
				p.DisplayStats();

				braveryRating.append("couragious");

				battleLoop = false;

				/* This area demonstrates the queue FIFO: First in First out */

				/* Saves the ending message */
				string saveMessage = "You defeated the " + enemy.getName();
				Queue<string> endingMessage = *_endingMessages;
				endingMessage.push(saveMessage);
				*_endingMessages = endingMessage;
			}

			break;
		case 2:
			cout << endl << "\tYou have escaped." << endl;
			battleLoop = false;

			braveryRating.append("coward");

			break;
		case 3:
		{
			cout << endl << "\tItems:" << endl;

			for (int i = 0; i < *_sizeOfItems; i++)
			{
				cout << "\t" << i + 1 << ": " << _items[i].name << " [" << _items[i].HP << "]" << endl;
			}

			int useItem;

			cin >> useItem;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			p.setCurrentHP(p.getCurrentHP() + _items[useItem - 1].HP);

			*_player = p;

			break;
		}
		default:
			cout << "\tInvalid input. Please try again." << endl;
			break;
		}

		*_enemy = enemy;
		*_player = p;
	}

	p.UpdateStats();
}
