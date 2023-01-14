#include "Game.h"
const std::string AnythingElseQ = "Would you like to choose anything else?\n";

void Game::MenuForTheGame()
{
	std::cout << "Welcome to the game! Please choose an option: \n";
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
	//std::cout << "3. Go to menu for logged in users.\n";
	std::cout << "99. Exit.\n";
	std::cin >> m_option;

	while (m_option != 99)
	{
		switch (m_option)
		{
		case 1:
		{
			try
			{
				std::cout << "Please choose an username: \n";
				std::string username;
				std::cin >> username;
				user.SignUp(username);
				std::cout << "You can now choose to go to the menu for logged in users by entering the number 3. \n";
				std::cout << AnythingElseQ;
				std::cin >> m_option;
				std::cout << "\n";
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage;
				m_option = 1;
			}
			break;
		}
		case 2:
		{
			try
			{
				std::cout << "Please write your username: ";
				std::string username;
				std::cin >> username;
				user.Login(username);
				if (user.FoundUserInFile("AllRegisteredUsers.txt", username))
				{
					std::cout << "You can now choose to go to the menu for logged in users by entering the number 3.";
				}
				if (!user.FoundUserInFile("LoggedInUsers.txt", username))
				{
					user.SaveLoggedInUsers(username);
				}
				std::cout << "\n";
				std::cout << AnythingElseQ;
				std::cin >> m_option;
				std::cout << "\n";
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage;
				m_option = 2;
			}
			break;
		}
		case 3:
		{
			MenuForALoggedInUser();
			std::cout << "\n";
			break;
		}
		case 99:
		{
			std::ofstream ofs;
			ofs.open("LoggedInUsers.txt", std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			std::cout << "You chose to exit! \n";
			break;
		}
		default:
		{
			std::cout << "Please choose a valid action. :( \n";
			break;
		}
		}
		
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
			std::cout << "Please enter your username again.\n";
			std::string username;
			std::cin >> username;
			while (!user.FoundUserInFile("LoggedInUsers.txt", username))
			{
				std::cout << "Please enter the username of someone who is logged in.\n";
				std::cin >> username;
			}
			user.ShowUserStats(username);
			std::cout << AnythingElseQ;
			std::cout << "\n";
			break;
		}
		case 2:
		{
			std::cout<< "Players: "<<user.HowManyPlayersAreLoggedIn()<<"\n";
			if (user.HowManyPlayersAreLoggedIn() < 2)
			{
				std::cout << "Wait for more players to log in.\n";
				MenuForTheGame();
				break;
			}
			SetGame();
			if (board.GetNumberOfPlayers() == 2)
				Run2();
			else if (board.GetNumberOfPlayers() == 3)
				std::cout << "Soon to be made.";
			std::cout << "\n";
			break;
		}
		case 99:
		{
			std::ofstream ofs;
			ofs.open("LoggedInUsers.txt", std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			std::cout << "You chose to exit! \n";
			std::cout << "\n";
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
	system("cls");
	std::cout << "What is the number of players you'd like this game to have? \n";
	std::cin >> m_numberOfPlayers;
	board.SetNumberOfPlayers(m_numberOfPlayers);
	if (m_numberOfPlayers == 2) m_numberOfRounds = 5;
	else m_numberOfRounds = 4;
	board.SetBoard();
	std::cout << "This is what the board looks like: \n";
	std::cout << board;
	std::cout << "Stats about the game: \n";
	board.Test();
	std::cout << "Number of rounds: " << m_numberOfRounds;
	std::cout << "\n";
}

void Game::Run()
{
	/*SetGame();*/
	MenuForTheGame();
	/*if (m_numberOfPlayers == 2)
		Run2();*/
}

void Game::Run2()
{
	std::queue<std::string> roomUsers;
	std::string playerOne;
	std::string playerTwo;
	std::cout <<std::endl << "Who wuld like to play?\n";

	std::cout << "Player one: ";
	std::cin >> playerOne;
	if (!user.FoundUserInFile("LoggedInUsers.txt", playerOne))
	{
		std::cout << "Please enter the username of someone who is logged in.\n";
		std::cin >> playerOne;
	}

	std::cout << "Player two: ";
	std::cin >> playerTwo;
	if (!user.FoundUserInFile("LoggedInUsers.txt", playerTwo))
	{
		std::cout << "Please enter the username of someone who is logged in.\n";
		std::cin >> playerTwo;
	}
	
	while (!board.IsFull())
	{
		system("cls");
		std::cout << "Board: \n" << board << std::endl;


		//Intrebare
		auto startPlayerOne = std::chrono::steady_clock::now();
		//raspuns playerOne
		auto stopPlayerOne = std::chrono::steady_clock::now();
		auto timePlayerOne = stopPlayerOne - startPlayerOne;

		//intrebare
		auto startPlayerTwo = std::chrono::steady_clock::now();
		//raspuns playerTwo
		auto stopPlayerTwo = std::chrono::steady_clock::now();
		auto timePlayerTwo = stopPlayerOne - startPlayerOne;

		//daca raspunsul este cel corect
		if (timePlayerOne < timePlayerTwo)
		{
			roomUsers.push(playerOne);
			roomUsers.push(playerTwo);
		}
		else
		{
			roomUsers.push(playerTwo);
			roomUsers.push(playerOne);
		}

	}


	//std>>
	/*std::ofstream ofs;
	ofs.open("RoomUsers.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();*/
}
