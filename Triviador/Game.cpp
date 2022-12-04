#include "Game.h"
const std::string AnythingElseQ = "Would you like to choose anything else?\n";

void Game::MenuForTheGame()
{
	std::cout << "Welcome to the game! Please choose an option: \n";
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	std::cout << "3. Start Game.\n";
	std::cout << "99. Exit.\n";
	std::cin >> m_option;

	while (m_option != 99)
	{
		switch (m_option)
		{
		case 1:
		{
			std::cout << "Please choose an username: \n";
			std::string username;
			std::cin >> username;
			user.SignUp(username);
			std::cout << AnythingElseQ;
			break;
		}
		case 2:
		{
			std::cout << "Please write your username: \n";
			std::string username;
			std::cin >> username;
			user.Login(username);
			std::cout << AnythingElseQ;
			break;
		}
		case 3:
		{
			std::cout << "What is the number of players you'd like this game to have? \n";
			SetGame();
			break;
		}
		case 99:
		{
			std::cout << "You chose to exit!\n";
			break;
		}
		default:
		{
			std::cout << "Please choose a valid action. :(\n";
			break;
		}
		}
		std::cin >> m_option;
	}

}

void Game::SetGame()
{
	int numberOfPlayers;
	std::cin >> numberOfPlayers;
	board.SetNumberOfPlayers(numberOfPlayers);
	board.SetBoard();
	board.MakeBoard();
	std::cout << "This is what the board looks like: \n";
	std::cout << board;
	std::cout << "Stats about the game: \n";
	board.Test();
}
