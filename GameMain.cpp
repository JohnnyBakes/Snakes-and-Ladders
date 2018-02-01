#include "GameMain.h"

using namespace std;

GameMain::GameMain() //Constructor
{
	PlayerPosition = 1; //initialize player position to 1
	GamePieces = 2; //initialize GamePieces to 2 (hardcoded, but this value can be used in future developments 
					//to change the total game pices
	RandomPieces();
}

void GameMain::incrementTable(int num) //This function is used to create the rows on the game board
									  //that are increasing from left to right
{
	bool printblank; //boolean variable used to determine if a blank spot should be printed on the game board or a game piece
	cout << "-------------------------------------------------------------------------------------------\n"; // Game Board line
	for (int k = 1; k <= 3; k++)
	{
		int count = 0;
		if (k == 1) //if it is the top part of the row, print out the position of the game board
		{

			for (int i = 0; i <= 9; i++)
			{
				printf("|   %02d   "    ,(num + i) );
			}
			cout << "|\n";
		}
		else if (k == 2)
		{
			for (int i = 0; i <= 9; i++)
			{
				printblank = true;
				for (int b = 0; b <= GamePieces; b++)
				{
					if (head[b] == (num + i)) //if statement is used to display snake head on the game board
					{
						printf("|   Sh%d  ", b);
						printblank = false;
					}
					if (tail[b] == (num + i)) // if statement to display snake tail on the game board
					{
						printf("|   St%d  ", b);
						printblank = false;
					}
					if (laddertop[b] == (num + i)) // if statement to display the top of the ladder on the game board
					{
						printf("|   Lt%d  ", b);
						printblank = false;
					}
					if (ladderbottom[b] == (num + i)) // if statement to display the bottom of the ladder on the game board
					{
						printf("|   Lb%d  ", b);
						printblank = false;
					}

				}
				if (printblank == true)
				{
					cout << "|        ";
				}

			}
			cout << "|\n";
		}
			else
			{
				for (int i = 0; i <= 9; i++)//For loop used to print players initials on the board, so that he/she know there position
				{							//The initials is used to inform the player visually, which position they are at on the board
					if (getPlayerPosition() == (num + i))
					{
						cout << "|   " << getInitials() << "   ";
					}
					else
					{
						cout << "|        ";
					}
				}
				cout << "|\n";
			}

		}
		
	}

void GameMain::decrementTable(int num)//This function is used to create the rows on the game board
									  //that are decreasing from left to right
{
	bool printblank;
	cout << "-------------------------------------------------------------------------------------------\n"; //Game board line
	for (int k = 1; k <= 3; k++)
	{
		if (k == 1) //if the table row nunber begins with an even number, decrement the other row numbers by 1
		{
			//if it is the first row, print out the number on the board

			for (int i = 0; i <= 9; i++)
			{
				printf("|   %02d   ", (num - i));
			}
			cout << "|\n";
		}
		else if (k == 2)
		{
			for (int i = 0; i <= 9; i++)
			{
				printblank = true;
				for (int b = 0; b <= GamePieces; b++)
				{
					if (head[b] == (num - i))  // if statement to display snake head on the game board
					{
						printf("|   Sh%d  ", b); //printing Sh to represent Snake Head on the game board
						printblank = false;
					}
					if (tail[b] == (num - i)) // if statement to display snake tail on the game board
					{
						printf("|   St%d  ", b); //printing St to represent Snake Tail on the game board
						printblank = false;
					}
					if (laddertop[b] == (num - i)) // if statement to display snake tail on the game board
					{
						printf("|   Lt%d  ", b); //printing Lt to represent the top of the ladder on the game board
						printblank = false;
					}
					if (ladderbottom[b] == (num - i)) // if statement to display snake tail on the game board
					{
						printf("|   Lb%d  ", b); //printing Lb to represent bottom of the ladder on the game board
						printblank = false;
					}

				}
				if (printblank == true)
				{
					cout << "|        ";
				}

			}
			cout << "|\n";
		}
		else
		{
			for (int i = 0; i <= 9; i++) //For loop used to print players initials on the board, so that he/she know there position
			{							 //The initials is used to inform the player visually, which position they are at on the board
				if (getPlayerPosition() == (num - i))
				{
					cout << "|   " << getInitials() << "   ";
				}
				else
				{
					cout << "|        ";
				}
			}
			cout << "|\n";
		}
	}
}

void GameMain::RandomPieces()
{

	srand(time(NULL));
	for (int i = 0; i <= GamePieces; i++)
	{
		head.push_back(rand() % (50-26) + 26); //Assigns random values for the snake head pieces ranging from 26-50
		tail.push_back(rand() % 25 + 1); //Assigns random values for the snake tail pieces ranging from  1-25
		laddertop.push_back(rand() % (50 - 26) + 26); //Assigns random values for the top of the ladder pieces ranging from 26-50
		ladderbottom.push_back(rand() % 25 + 1); //Assigns random values for the bottom of the ladder pieces ranging from 1-25
	}

	

			while (UniqueSnakeHead() == true)//Generates different snake head pieces if any are the same
			{
				for (int i = 0; i <= GamePieces; i++)
				{
					head[i] = rand() % (50 - 26) + 26;
				}
			}

			while (UniqueSnakeTail() == true)//Generates different snake tail pieces if any are the same
			{
				for (int i = 0; i <= GamePieces; i++)
				{
					tail[i] = rand() % 25 + 1;
				}
			}

			while ( UniqueLadderTop() == true || MatchSnakeHeadandLadderTop() == true) //Generates another random number if two ladder tops are the same
			{														  // or if a ladder top and snake head are the same
				for (int i = 0; i <= GamePieces; i++)
				{
					laddertop[i] = rand() % (50 - 26) + 26;
				}
			}
			while (UniqueLadderBottom() == true || MatchSnakeTailandLadderBottom() == true) //Generates another random number if two ladder bottom are the same
			{																//or if a ladder bottom and a snake tail are the same
				for (int i = 0; i <= GamePieces; i++)
				{
					ladderbottom[i] =rand() % 25  + 1;
				}
			}	
		
}



bool GameMain::UniqueSnakeHead()//This function is used to ensure all snake head are unique
{
	bool found = false;
	for (int a = 0; a <= GamePieces-1; a++) //This for loop ensures all snake head pieces are unique 
	{
		for (int x = a + 1; x <= GamePieces; x++)
		{
			if (head[a] == head[x])
			{
				found = true;
				return found;
			}
		}
	}
	return found;
}

bool GameMain::UniqueSnakeTail()//This function is used to ensure all snake head are unique
{
	bool found = false;
	for (int a = 0; a <= GamePieces-1; a++) //This for loop ensures all snake head pieces are unique 
	{
		for (int x = a + 1; x <= GamePieces; x++)
		{
			if (tail[a] == tail[x])
			{
				found = true;
				return found;
			}
		}
	}
	return found;
}

bool GameMain::UniqueLadderTop()//This function is used to ensure all ladder top are unique
{
	bool found = false;
	for (int a = 0; a <= GamePieces-1; a++) //This for loop ensures all ladder top pieces are unique 
	{
		for (int x = a + 1; x <= GamePieces; x++)
		{
			if (laddertop[a] == laddertop[x])
			{
				found = true;
				return found;
			}
		}
	}
	return found;
}

bool GameMain::UniqueLadderBottom() //This function is used to ensure all ladder bottom are unique
{
	bool found = false;
	for (int a = 0; a <= GamePieces-1; a++) //This for loop ensures all ladder bottom pieces are unique 
	{
		for (int x = a + 1; x <= GamePieces; x++)
		{
			if (ladderbottom[a] == ladderbottom[x])
			{
				found = true;
				return found;
			}
		}
	}
	return found;
}

bool GameMain::MatchSnakeHeadandLadderTop() //This function is used to determine if a Snake head and a top of the ladder piece
{											//has the same values
	bool found = false;
	for (int a = 0; a <= GamePieces; a++)
	{
		for (int b = 0; b <= GamePieces; b++)
		{
			if (head[a] == laddertop[b])
			{
				found = true;
				return found;
			}

		}
	}
	return found;
}

bool GameMain::MatchSnakeTailandLadderBottom() //This function is used to determine if a Snake tail and a bottom of the ladder piece
{											  //has the same value
	bool found = false;
	for (int a = 0; a <= GamePieces; a++)
	{
		for (int b = 0; b <= GamePieces; b++)
		{
			if (tail[a] == ladderbottom[b])
			{
				found = true;
				return found;
			}

		}
	}
	return found;
}

void GameMain::setPlayerPosition(int x) //Mutator function to change the players position
{
	PlayerPosition = x;
}

int GameMain::getPlayerPosition() //Accessor function used to get the player's position
{
	return PlayerPosition;
}

void GameMain::setFname(string f) //Mutator function used to set the first name
{
	Fname = f;
}

string GameMain::getFname() //Accessor function used to get the player's first name
{
	return Fname;
}

void GameMain::setLname(string l) //Mutator function used to set the last name
{
	Lname = l;
}

string GameMain::getLname() //Accessor function used to get the last name
{
	return Lname;
}
string GameMain::getInitials() //Accessor funcion used to get the initials of the player's name
{
	string initials = "";

	initials=Fname[0];
	initials.push_back(Lname[0]);

	return initials;

}

void GameMain::TrackingPlayer(int position) //This function is used to move the player position, if they landed on a ladder or snake
{
	for (int a = 0; a <= GamePieces; a++)
	{
		if (position == ladderbottom[a])
		{
			setPlayerPosition(laddertop[a]);
			cout << "\n Nice roll!, you landed on the bottom of a ladder, your new position is:" << getPlayerPosition() <<"\n";
		}
		if (position == head[a])
		{
			setPlayerPosition(tail[a]);
			cout << "\n Oops, you landed on a snakes' head, your new position is:" << getPlayerPosition() << "\n";
		}
	}

}

void GameMain::EmptyPieces() //Removes all game pieces
{
	head.clear();
	tail.clear();
	ladderbottom.clear();
	laddertop.clear();
}


GameMain::~GameMain() //destructor function, not used
{

}



