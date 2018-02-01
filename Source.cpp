
#include "GameMain.h"

int main()
{
	string firstname, lastname;
	string roll; //variable used to capture the player typing roll
	int diceroll = 0; //variable used to capture what the dice rolled
	GameMain Game; //An object of type GameMain
	string playagain; //variable used to determine if player wants to player again
		
	cout << "Welcome to a game of snakes and ladders that was created by me: Kevin Johnson.\n";
	cout << "The snakes and ladders are randomly placed on the board, for each game.\n";
	cout << "If a player lands on the head of a snake (Sh#), he/she will slide down to the tail (St#).\n";
	cout << "If a player lands on the bottom of a ladder (Lb#), he/she will climb to the top of the ladder (Lt#).\n";
	cout << "Example: If a player lands on Lb1 he/she will be moved to Lt1, if Sh3 he/she will move to St3, etc.\n";
	cout << "To move positions, type the word \"roll\" or \"ROLL\".\n";
	cout << "The initials for your name, will be used to show your position on the board.\n";
	cout << "Enjoy and good luck!, may the force be with you!\n\n";

	//The player enters their name here
		cout << "\nPlease enter your First Name:\n";
		cin >> firstname;
		Game.setFname(firstname);
		cout << "Please enter your Last Name:\n";
	    cin >> lastname;
		Game.setLname(lastname);

		cout << "\nPlease roll the dice to begin playing.\n";
		while (Game.getPlayerPosition() <50)
		{
			
			//The user rolls the dice here and begins moving position
			cout <<"To roll the dice, type the word:\"ROLL\" or \"roll\" \n";
			cin >> roll; //gets user input of the word roll or ROLL
	
			if (roll == "ROLL" || roll == "roll")
			{
				diceroll = rand() % 6 + 1; //randomly generates a value from 1 to 6
				Game.setPlayerPosition(Game.getPlayerPosition() + diceroll); //the diceroll is added to the player's position
				Game.incrementTable(41);
				Game.decrementTable(40);
				Game.incrementTable(21);
				Game.decrementTable(20);
				Game.incrementTable(1);
				cout << "-------------------------------------------------------------------------------------------\n";
				cout << "You rolled " << diceroll << " on the dice.\n";
				cout << "You are now at position:" << Game.getPlayerPosition() <<"\n";
				Game.TrackingPlayer(Game.getPlayerPosition());

			}
			else
			{
				cout << "You typed the word \"ROLL\" or \"roll\" incorrectly, please try again\n";
			}

			if (Game.getPlayerPosition() >= 50)
			{
				cout << "Congratulations " << Game.getFname() << "!, You won Snakes and Ladders!\n\n";//Congratulates player for winning
				cout << "Would you like to play again? Type and enter \"y\" for yes and anything else for no\n";
				cin >> playagain;

				if (playagain == "y")
				{
					Game.setPlayerPosition(1); //resets player position to 1
					Game.EmptyPieces();
					Game.RandomPieces(); //makes a new board of random snakes and ladders
				}

					
			}
		}
		
	
	return 0;
}