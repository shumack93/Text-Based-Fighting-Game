/*******************************************************************
** Program Name: Project 3 - Fantasy Combat Game
** Author:       Cris Shumack
** Date:         02/17/2019
** Description:  Header file to declare the abstract Character
**               class that our characters will inherit from.
*******************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<string>

using std::string;

class Character
{
	protected:
		string name;
		string characteristic;
		int armor;
		int strength;
		bool deathStatus;

	public:
		virtual int attack() = 0;
		virtual void defense(int damageTaken) = 0;
		virtual bool getDeathStatus() = 0;
		virtual int rollAttack() = 0;
		virtual int rollDefense() = 0;
		virtual string getName() = 0;
		virtual int getArmor() = 0;
		virtual int getStrength() = 0;
		virtual string getCharacteristic() = 0;
};

#endif
