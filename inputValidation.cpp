/*********************************************************************************
** Program Name: Project 3 - Fantasy Combat Game
** Author:       Cris Shumack
** Date:         02/17/2019
** Description:  Implementation file that defines our inputValidation 
**               function that was declared in inputValidation.hpp.
*********************************************************************************/

#include "inputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;

void inputValidation(int& input, int min, int max)
{
        while (input < min || input > max || cin.fail() || cin.get() != '\n')
        {
                cin.clear();
                cin.ignore(5000, '\n');

                cout << "Invalid input. Please try again." << endl;

                cin >> input;
        }
}
