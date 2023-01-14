#include <iostream>
#include <fstream>
#include <string>
#include "Game.h"
#include"Board.h"
#include "Question.h"
#include "PowerUps.h"
#include"Region.h"

#include<Windows.h>
#include<algorithm>
#include <random>

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

	//std::vector<const char*> colors;
	//colors.push_back("\033[94m");
	//colors.push_back("\033[91m");
	//colors.push_back("\033[95m");

	//const char* reset = "\033[0m";
	//const char* color= "\033[92m";
	//const char* color2= "\033[94m";
	//const char* color3= "\033[91m";
	//const char* color4 = "\033[95m";
	//std::cout << color << "Player one. \n";
	//std::cout << color2 << "Player two.\n";
	//std::cout << color3 << "Player three.\n";
	//std::cout << color4 << "Player four.\n";
	//std::cout << reset;


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
	////Board board2;
	//int numberOfPlayers;
	//std::cin >> numberOfPlayers;
	//board.SetNumberOfPlayers(numberOfPlayers);
	//board.SetBoard();
	//int line, column;
	////int line2, column2;
	//std::cin >> line >> column;
	////std::cin >> line2 >> column2;
	//std::cout << "Empty board:\n" << board << std::endl; 
	//std::cout << "Empty board2:\n" << board2 << std::endl; 
	//board[{line, column}] = Region::Regions::SimpleRegion;
	//board2[{line, column2}] = Region::Regions::SimpleRegion;
	//std::cout << board;
	//std::cout << board2;
	//while (!board.IsFull())
	//{
	//	int line, column;
	//	std::cin >> line >> column;
	//	if (!board[{line, column}])
	//	{
	//		/*std::default_random_engine rng{ std::random_device{}() };
	//		std::shuffle(colors.begin(),colors.end(), rng);*/
	//		//numar random marime vector 
	//		board[{line, column}] = Region::Regions::SimpleRegion;
	//	}
	//	else
	//		std::cout << "Already there";
	//	
	//	std::cout << "\n";
	//	if (line == 0 && column == 0)
	//	{
	//		std::cout << "\033[94m" << board;
	//	}
	//	else
	//	{
	//		board[{line, column}] = "\033[92m";
	//		std::cout << "\033[92m" << board;
	//	}
	//	
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