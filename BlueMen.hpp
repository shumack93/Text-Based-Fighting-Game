/*******************************************************************
** Program Name: Project 3 - Fantasy Combat Game
** Author:       Cris Shumack
** Date:         02/17/2019
** Description:  Header file to declare the BlueMen class that
**               will be defined in the BlueMen.cpp file.
*******************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include<string>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Character.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class BlueMen: public Character
{
	public:
		BlueMen();
		int attack();
		void defense(int damageTaken);
		bool getDeathStatus();
		int rollAttack();
		int rollDefense();
		string getName();
		int getArmor();
		int getStrength();
		string getCharacteristic();
};

#endif
