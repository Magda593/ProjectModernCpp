#include "Game.h"
const std::string AnythingElseQ = "Would you like to choose anything else?\n";

void Game::MenuForTheGame()
{
	std::cout << "Welcome to the game! Please choose an option: \n";
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	std::cout << "3. Go to menu for logged in users.\n";
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
			user.SaveUserForCurrentRoom(username);
			std::cout << "\n";
			std::cout << AnythingElseQ;
			//MenuForALoggedInUser();
			break;
		}
		case 3:
		{
			MenuForALoggedInUser();
			break;
		}
		case 99:
		{
			std::cout << "You chose to exit! \n";
			break;
		}
		default:
		{
			std::cout << "Please choose a valid action. :( \n";
			break;
		}
		}
		std::cin >> m_option;
	}

}

void Game::MenuForALoggedInUser()
{
	std::cout << "Now please choose an option: \n";
	std::cout << "1. See your profile.\n";
	std::cout << "2. Start game.\n";
	std::cout << "99. Exit.\n";
	std::cin >> m_option;

	while (m_option != 99)
	{
		switch (m_option)
		{
		case 1:
		{
			std::cout << "This option is yet to come.";
			std::cout << AnythingElseQ;
			break;
		}
		case 2:
		{
			SetGame();
			if (board.GetNumberOfPlayers() == 2)
				Run2();
			else if (board.GetNumberOfPlayers() == 3)
				std::cout << "Soon to be made.";
			break;
		}
		case 99:
		{
			std::cout << "You chose to exit! \n";
			break;
		}
		default:
		{
			std::cout << "Please choose a valid action. :( \n";
			break;
		}
		}
		std::cin >> m_option;
	}
}

void Game::SetGame()
{
	std::cout << "What is the number of players you'd like this game to have? \n";
	int numberOfPlayers;
	std::cin >> numberOfPlayers;
	board.SetNumberOfPlayers(numberOfPlayers);
	board.SetBoard();
	std::cout << "This is what the board looks like: \n";
	std::cout << board;
	std::cout << "Stats about the game: \n";
	board.Test();
}

void Game::Run2()
{
	std::string PlayerOne;
	std::string PlayerTwo;
}
