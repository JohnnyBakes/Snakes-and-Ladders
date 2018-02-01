#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;
#ifndef GAMEMAIN_H
#define GAMEMAIN_H

class GameMain
{
private:
	vector<int>head; //Vector to hold snake head pieces
	vector<int>tail; //Vector used to hold snake tail pieces
	vector<int>laddertop; //Vector used to hold top of the ladder pieces
	vector<int>ladderbottom; //Vector used to hold bottom of the ladder pieces
	string Fname; //String variable used to hold the player's first name
	string Lname; //String variable used to hold the player's last name
	int GamePieces; //Used to determine how many pieces should be of each ladder and snake
	int PlayerPosition; //Used to calculate the player's positon

public:
	GameMain(); //Constructor function
	void incrementTable(int num); //function used to display rows whose values increase
	void decrementTable(int num); //function used to display rows whose values decrease
	void RandomPieces(); //function used to generate random values for head and tail of snake
	bool MatchSnakeHeadandLadderTop(); //function used to determine if snake head and ladder top has same value
	bool MatchSnakeTailandLadderBottom();//function used to determine if snake tail and ladder bottom has same value
	bool UniqueLadderTop(); //This function is used to ensure all ladder top pieces are unique
	bool UniqueLadderBottom(); //This function is used to ensure all ladder bottom pieces are unique
	bool UniqueSnakeHead();//This function is used to ensure all snake head pieces are unique
	bool UniqueSnakeTail();//This function is used to ensure all snake tail pieces are unique
	void setPlayerPosition(int x); //Mutator function to change the players position
	int getPlayerPosition(); //Accessor function usedto get the players position
	void setFname(string f); //Mutator function used to set the player's first name
	string getFname();		//Accessor function used to get the player's first name
	void setLname(string l); //Mutator function used to set the player's last name
	string getLname(); //Mutator function usedto get the player's last name
	string getInitials(); //Accessor function used to get the player's initial
	void TrackingPlayer(int position); //This function is used to keep track of the player
	void EmptyPieces();//Removes all game pieces
	~GameMain(); //Destrcutor function
};
#endif
