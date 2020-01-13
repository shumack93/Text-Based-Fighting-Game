/*********************************************************************
** Program Name: Project 3 - Fantasy Combat Game
** Author:       Cris Shumack
** Date:         02/17/2019
** Description:  Main function to run our fantasy combat game.
**
*********************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Character.hpp"
#include "inputValidation.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	//So our rand() functions generate different numbers each time.
	srand(time(NULL));

	int choice, player1, player2, firstAttack, attackDmg;
	Character* fighter1;
	Character* fighter2;
	bool continueGame = true;

	fighter1 = NULL;
	fighter2 = NULL;

	cout << endl << "Welcome to the fantasy combat game!" << endl;
	
	//Gave the user the option to replay the game by using a do-while loop.
	do
	{
		cout << endl << "Select an option from the menu below." << endl;
		cout << "1. FIGHT!" << endl;
		cout << "2. Show character details" << endl;
		cout << "3. Exit game" << endl;
		cin >> choice;
		inputValidation(choice, 1, 3);

		if (choice == 1)
		{
			cout << endl << "Select the fighter for Player 1 from the list below." << endl;
			cout << "1. Vampire" << endl;
			cout << "2. Barbarian" << endl;
			cout << "3. Blue Men" << endl;
			cout << "4. Medusa" << endl;
			cout << "5. Harry Potter" << endl;
			cin >> player1;
			inputValidation(player1, 1, 5);
	
			//To create the correct character type based on user input.
			if (player1 == 1)
				fighter1 = new Vampire();	
			else if (player1 == 2)
				fighter1 = new Barbarian();
			else if (player1 == 3)
				fighter1 = new BlueMen();
			else if (player1 == 4)
				fighter1 = new Medusa();
			else if (player1 == 5)
				fighter1 = new HarryPotter();
	
			cout << endl << "Select the fighter for Player 2 from the list below." << endl;
			cout << "1. Vampire" << endl;
			cout << "2. Barbarian" << endl;
			cout << "3. Blue Men" << endl;
			cout << "4. Medusa" << endl;
			cout << "5. Harry Potter" << endl;
			cin >> player2;
			inputValidation(player2, 1, 5);
	
			if (player2 == 1)
				fighter2 = new Vampire();	
			else if (player2 == 2)
				fighter2 = new Barbarian();
			else if (player2 == 3)
				fighter2 = new BlueMen();
			else if (player2 == 4)
				fighter2 = new Medusa();
			else if (player2 == 5)
				fighter2 = new HarryPotter();
	
			cout << endl << "Player 1 Fighter: " << fighter1->getName() << " - " << fighter1->getCharacteristic() << endl;
			cout << "Starting armor: " << fighter1->getArmor() << endl;
			cout << "Starting strength: " << fighter1->getStrength() << endl << endl;
	
			cout << "Player 2 Fighter: " << fighter2->getName() << " - " << fighter2->getCharacteristic() << endl;
			cout << "Starting armor: " << fighter2->getArmor() << endl;
			cout << "Starting strength: " << fighter2->getStrength() << endl << endl;
		
			//Randomly selects who attacks first.
			firstAttack = rand() % 2 + 1;

			if (firstAttack == 1)
				cout << "Player 1 was randomly selected to attack first!" << endl << endl;
			else
				cout << "Player 2 was randomly selected to attack first!" << endl << endl;

			if (firstAttack == 1)
			{
				int round = 1;

				while (fighter1->getDeathStatus() == false && fighter2->getDeathStatus() == false)
				{
					cout << "------------------------------------------------------" << endl << "ROUND " << round << endl << "------------------------------------------------------" << endl;
	
					cout << "Player 1 attacks:" << endl;
					attackDmg = fighter1->attack();

					cout << "Player 2 defends:" << endl;
					fighter2->defense(attackDmg);

					if (fighter2->getDeathStatus() == false)
					{
						cout << "Player 2 attacks:" << endl;
						attackDmg = fighter2->attack();

						cout << "Player 1 defends:" << endl;
						fighter1->defense(attackDmg);
					}

					round++;
				}
			}
			else if (firstAttack == 2)
			{
				int round = 1;
		
				while (fighter1->getDeathStatus() == false && fighter2->getDeathStatus() == false)
				{
					cout << "------------------------------------------------------" << endl << "ROUND " << round << endl << "------------------------------------------------------" << endl;
				
					cout << "Player 2 attacks:" << endl;
					attackDmg = fighter2->attack();

					cout << "Player 1 defends:" << endl;
					fighter1->defense(attackDmg);
	
					if (fighter1->getDeathStatus() == false)
					{
						cout << "Player 1 attacks:" << endl;
						attackDmg = fighter1->attack();
	
						cout << "Player 2 defends:" << endl;
						fighter2->defense(attackDmg);
					}
	
					round++;
				}
			}

			if (fighter1->getDeathStatus() == true)
				cout << "Player 2 is the winner!" << endl;
			else if (fighter2->getDeathStatus() == true)
				cout << "Player 1 is the winner!" << endl;
	
			delete fighter1;
			delete fighter2;
		}
		else if (choice == 2)
		{
			cout << endl << "1. Vampire - One 12 sided attack die and one 6 sided defense die" << endl;
			cout << "Special ability: Charm - Vampire can charm an opponent into not attacking. For a given attack, there is a 50 percent chance that their opponent does not attack them." << endl;
			cout << "Armor: 1" << endl;
			cout << "Strength: 18" << endl << endl;
		
			cout << "2. Barbarian - Two 6 sided attack dice and two 6 sided defense dice" << endl;
			cout << "Armor: 0" << endl;
			cout << "Strength: 12" << endl << endl;

			cout << "3. Blue Men - Two 10 sided attack dice and three 6 sided defense dice (lose 1 defense die for every 4 strength lost)" << endl;
			cout << "Special ability: Mob - Blue Men are actually a swarm of small individuals. For every 4 points of damage, they lose one defense die." << endl;
			cout << "Armor: 3" << endl;
			cout << "Strength: 12" << endl << endl;

			cout << "4. Medusa - Two 6 sided attack dice and one 6 sided defense die" << endl;
			cout << "Special ability: Glare - If Medusa rolls a 12 when attacking, the target is turned to stone and Medusa wins! If Medusa uses Glare on Harry Potter on his first life, he comes back to life." << endl;
			cout << "Armor: 3" << endl;
			cout << "Strength: 8" << endl << endl;

			cout << "5. Harry Potter - Two 6 sided attack dice and two 6 sided defense dice" << endl;
			cout << "Special ability: Hogwarts - If Harry Potter's strength reaches 0 or below, he immediately recovers and his total strength becomes 20. If he were to die again, then he's dead." << endl;
			cout << "Armor: 0" << endl;
			cout << "Strength: 10 (20 after Hogwarts is activated)" << endl;
		}
		else if (choice == 3)
			continueGame = false;

	}
	while (continueGame == true);
	
	return 0;
}
