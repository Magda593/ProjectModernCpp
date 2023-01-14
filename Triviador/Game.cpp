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
			std::cout << "Players: " << user.HowManyPlayersAreLoggedIn() << "\n";
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
	numericQuestion.ReadNumericQuestions();
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
	std::string nQuestion;
	int nAnswerPlayer1;
	int nAnswerPlayer2;
	int line, column;
	int contor = 0;
	std::cout << std::endl << "Who wuld like to play?\n";

	std::cout << "Player one (with id 1): ";
	std::cin >> playerOne;
	if (!user.FoundUserInFile("LoggedInUsers.txt", playerOne))
	{
		std::cout << "Please enter the username of someone who is logged in.\n";
		std::cin >> playerOne;
	}

	std::cout << "Player two (with id 2): ";
	std::cin >> playerTwo;
	if (!user.FoundUserInFile("LoggedInUsers.txt", playerTwo))
	{
		std::cout << "Please enter the username of someone who is logged in.\n";
		std::cin >> playerTwo;
	}

	while (!board.IsFull())
	{
		//system("cls");
		std::cout << "Board: \n" << board << std::endl;

		nQuestion = numericQuestion.GetRandomNumericQuestion();
		std::cout << '\n' << playerOne << " ,answer to this question! \n" << nQuestion;
		auto startPlayerOne = std::chrono::steady_clock::now();
		std::cin >> nAnswerPlayer1;
		auto stopPlayerOne = std::chrono::steady_clock::now();

		std::chrono::duration<double> timePlayerOne = stopPlayerOne - startPlayerOne;
		std::cout << std::endl << "(" << timePlayerOne.count() << ")\n";

		std::cout << '\n' << playerTwo << " ,answer to this question! \n" << nQuestion;
		auto startPlayerTwo = std::chrono::steady_clock::now();
		std::cin >> nAnswerPlayer2;
		auto stopPlayerTwo = std::chrono::steady_clock::now();

		std::chrono::duration<double> timePlayerTwo = stopPlayerTwo - startPlayerTwo;
		std::cout << std::endl <<"(" << timePlayerTwo.count() <<")\n";

		if (nAnswerPlayer1 == numericQuestion.GetAnswer(nQuestion) && nAnswerPlayer2 == numericQuestion.GetAnswer(nQuestion))
		{
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
		else if (nAnswerPlayer1 != numericQuestion.GetAnswer(nQuestion) && nAnswerPlayer2 == numericQuestion.GetAnswer(nQuestion))
		{
			roomUsers.push(playerTwo);
		}
		else if (nAnswerPlayer1 == numericQuestion.GetAnswer(nQuestion) && nAnswerPlayer2 != numericQuestion.GetAnswer(nQuestion))
		{
			roomUsers.push(playerOne);
		}

		while (!roomUsers.empty()) 
		{
			if (contor == 0)
			{
				std::cout << roomUsers.front() << ", please choose the position for your base: ";
				std::cin >> line >> column;
				if (roomUsers.front() == playerOne)
				{
					board[{line, column}] = Region::Regions::BasePlayerOne;
					std::cout << playerTwo<< ", please choose the position for your base: ";
					std::cin >> line >> column;
					board[{line, column}] = Region::Regions::BasePlayerTwo;
					roomUsers.pop();
				}
				else
				{
					board[{line, column}] = Region::Regions::BasePlayerTwo;
					std::cout << playerOne << ", please choose the position for your base: ";
					std::cin >> line >> column;
					board[{line, column}] = Region::Regions::BasePlayerOne;
					roomUsers.pop();
				}
			}
			else
			{
				std::cout << roomUsers.front() << ", please choose the position for your region: ";
				std::cin >> line >> column;
				if (roomUsers.front() == playerOne)
					board[{line, column}] = Region::Regions::SimpleRegionPlayerOne;
				else
					board[{line, column}] = Region::Regions::SimpleRegionPlayerTwo;
				roomUsers.pop();
			}
			//roomUsers.pop();
			contor++;
		}
		roomUsers.empty();
	}

	system("cls");
	std::cout << "\nThe duel begins!\n";

	while (m_numberOfRounds != 0)
	{
		int randomNumber = numericQuestion.GetRandomNumber(2);
		if (randomNumber + 1 == 1)
		{

		}


		m_numberOfRounds--;
	}

	//int line, column;
	////int line2, column2;
	//std::cin >> line >> column;
	////std::cin >> line2 >> column2;
	//std::cout << "Empty board:\n" << board << std::endl;
	//board[{line, column}] = Region::Regions::SimpleRegionPlayerOne;
	//std::cout << board;
	//while (!board.IsFull())
	//{
	//	int line, column;
	//	std::cin >> line >> column;
	//	board[{line, column}] = Region::Regions::SimpleRegionPlayerOne;
	//	std::cout << "\n";
	//	std::cout << board;
	//	/*if (line == 0 && column == 0)
	//	{
	//		std::cout << "\033[94m" << board;
	//	}
	//	else
	//	{
	//		std::cout << "\033[92m" << board;
	//	}
	//	*/
	//	std::cout << "\n";
	//}

	//std>>
	/*std::ofstream ofs;
	ofs.open("RoomUsers.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();*/
}
