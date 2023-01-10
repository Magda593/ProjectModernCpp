#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include"Board.h"
#include "Question.h"
#include "PowerUps.h"
#include"Region.h"

#include<Windows.h>

int main()
{
	system("Color 0A"); //light green
	Board board;
	int numberOfPlayers;
	std::cin >> numberOfPlayers;
	board.SetNumberOfPlayers(numberOfPlayers);
	board.SetBoard();
	std::cout << "Empty board:\n" << board << std::endl; 
	board[{0, 1}] = Region::Regions::SimpleRegion;
	std::cout << board;


	return 0;
}