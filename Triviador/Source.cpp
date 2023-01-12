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
	//std::unordered_map<std::string, int> m_questionType2;
	//m_questionType2.insert({ "a",5 });
	//m_questionType2.insert({ "b",5 });
	//m_questionType2.insert({ "c",5 });
	//
	//std::pair<std::string, int> p;
	//auto x = m_questionType2.begin();
	//auto y = m_questionType2.end();

	//int poz = 2;
	//int nr = 0;
	//for (auto el : m_questionType2)
	//{
	//	if (nr == poz)
	//	{
	//		p = el;
	//		break;
	//	}
	//	nr++;
	//}


	system("Color 0C"); //light green

	Game game;
	game.Run();

	//AccountManager am;
	//am.SetPlayedGamesForXUsr(std::make_pair("Ash",0));
	//am.SignUp("Cath");
	//am.SignUp("Ar");
	//am.SignUp("MEk");
	//am.SignUp("Eri");
	/*am.SetPlayedGamesForXUsr("Ar");
	am.PrintUsernames();*/

	
	//Board board;
	//int numberOfPlayers;
	//std::cin >> numberOfPlayers;
	//board.SetNumberOfPlayers(numberOfPlayers);
	//board.SetBoard();
	//std::cout << "Empty board:\n" << board << std::endl; 
	//while (!board.IsFull())
	//{
	//	int line, column;
	//	std::cin >> line >> column;
	//	if (!board[{line, column}])
	//		board[{line, column}] = Region::Regions::SimpleRegion;
	//	else
	//		std::cout << "Already there";
	//	
	//	std::cout << "\n";
	//	std::cout << board;
	//	std::cout << "\n";
	//}
	///*board[{0, 1}] = Region::Regions::SimpleRegion;
	//std::cout << board;*/

	//return 0;
}

/*
1. fie scriu colorat in consola 
2. ori initiala user si scor

Raspund la aceiasi intrebare, 
daca raspund la fel se mai pune o intrebare pana raspund diferit 

map+20
sau?
for auto iterator de la map.begin; diferit de iterator +20 

sa ne interesam de chrono pentru timp 

regex login
regex register

*/