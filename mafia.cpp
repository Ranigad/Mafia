/*   Name: Ranigad
     Date: 12/8/14
	 Description: A list to keep track of remaining roles in the classic Town of Salem game
*/

#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	bool deadRoles[15] = { 0 };
	
	while (!victoryConditions(deadRoles))
	{
		_getch();
		printRoles(deadRoles[15]);
	}
	
	switch(met){
		case 1: cout << "Town wins!" << endl;
		case 2: cout << "Mafia wins!" << endl;
		case 3: cout << "SK wins!" << endl;
		}
		
	_getch();	
		
	return 0;
}

victoryConditions(bool deadRoles[15])
{
	int met;

	bool deadTown = true;
	bool deadMafia = true;
	bool deadSK = false;
	
	for (int i = 0; i < 9; i++)
		if (!deadRoles[i])
			deadTown = false;
			
	for (int i = 9; i <= 11; i++)
		if (!deadRoles[i])
			deadMafia = false;
		
	if (deadRoles[12]) deadSK = true;
	
	if (deadTown && deadMafia) met = 3;
	else if (deadMafia && deadSK) met = 1;
	else if (deadTown && deadSK) met = 2;
	else met = 0;
	
	return met;
}

void printRoles(bool deadRoles[15])
{
	cout << "** Town **" << endl;
	if (deadRoles[0]) cout << "1. Investigator" << endl;
	if (deadRoles[1]) cout << "2. Sheriff" << endl;
	if (deadRoles[2]) cout << "3. Escort" << endl;
	if (deadRoles[3]) cout << "4. Doctor" << endl;
	if (deadRoles[4]) cout << "5. Jailor" << endl;
	if (deadRoles[5]) cout << "6. Medium" << endl;
	if (deadRoles[6]) cout << "7. Lookout" << endl;
	if (deadRoles[7]) cout << "8. Town Killing" << endl;
	if (deadRoles[8]) cout << "9. Random Town" << endl;

	cout << "** Mafia **" << endl;
	if (deadRoles[9]) cout << "a. Godfather" << endl;
	if (deadRoles[10]) cout << "b. Mafioso" << endl;
	if (deadRoles[11]) cout << "c. Framer" << endl;
	
	cout << "** Neutral **" << endl;
	if (deadRoles[12]) cout << "d. Serial Killer" << endl;
	if (deadRoles[13]) cout << "e. Jester" << endl;
	if (deadRoles[14]) cout << "f. Executioner" << endl;
	
	cout << endl << "*********************************************" 	<< endl;
}