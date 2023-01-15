#include "Game.h"
const std::string AnythingElseQ = "Would you like to choose anything else?\n";

void Game::MenuForTheGame()
{
	std::cout << "Welcome to the game! Please choose an option: \n";
	std::cout << "1. Register\n";
	std::cout << "2. Login\n";
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
	std::cout << "3. Go back to the first menu.\n";
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
			else if(board.GetNumberOfPlayers() == 4)
				std::cout << "Soon to be made.";
			std::cout << "\n";
			break;
		}
		case 3:
		{
			MenuForTheGame();
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
	grillQuestion.ReadQuestion();
	powerUpsPlayer1.AllPowers();
	powerUpsPlayer2.AllPowers();
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
	MenuForTheGame();
}

void Game::Run2()
{
	std::queue<std::string> roomUsers;
	std::string playerOne;
	std::string playerTwo;
	std::string nQuestion;
	int nAnswerPlayer1;
	int nAnswerPlayer2;
	std::string gCorrectAnswer;
	std::string gAnswerPlayer1;
	std::string gAnswerPlayer2;
	int score1=300;
	int score2=300;
	int line, column;
	int contor = 0;
	int contorPlayer1=0;
	int contorPlayer2 = 0;
	int numberOfRounds = m_numberOfRounds;
	int option1, option2, answerPowerUps;
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
		std::cout << '\n' << "Do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
		std::cin >> answerPowerUps;
		if (answerPowerUps == 1)
		{
			try
			{
				powerUpsPlayer1.UsedPowers(option1);
				if (option1 == 2)
				{
					try
					{
						powerUpsPlayer1.CloseAnswer(numericQuestion.GetAnswer(nQuestion));
					}
					catch (const char* err)
					{
						std::cout << err;
					}
				}
				else if (option1 == 3)
				{
					try
					{
						powerUpsPlayer1.Suggestion(numericQuestion.GetAnswer(nQuestion));
					}
					catch (const char* err)
					{
						std::cout << err;
					}
				}	
			}
			catch (const char* error)
			{
				std::cout << error;
			}
		}
		else
		{
			std::cout << "Choose your answer: " << '\n';
		}
		auto startPlayerOne = std::chrono::steady_clock::now();
		std::cin >> nAnswerPlayer1;
		auto stopPlayerOne = std::chrono::steady_clock::now();

		std::chrono::duration<double> timePlayerOne = stopPlayerOne - startPlayerOne;
		std::cout << std::endl << "(" << timePlayerOne.count() << ")\n";

		std::cout << '\n' << playerTwo << " ,answer to this question: \n" << nQuestion;
		std::cout << '\n' << "Do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
		std::cin >> answerPowerUps;
		if (answerPowerUps == 1)
		{
			try
			{
				powerUpsPlayer2.UsedPowers(option2);
				if (option2 == 2)
				{
					try
					{
						powerUpsPlayer2.CloseAnswer(numericQuestion.GetAnswer(nQuestion));
					}
					catch (const char* err)
					{
						std::cout << err;
					}
				}
				else if (option2 == 3)
				{
					try
					{
						powerUpsPlayer2.Suggestion(numericQuestion.GetAnswer(nQuestion));
					}
					catch (const char* err)
					{
						std::cout << err;
					}
				}
			}
			catch (const char* error)
			{
				std::cout << error;
			}
		}
		else
		{
			std::cout << "Choose your answer: " << '\n';
		}
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
		else if (nAnswerPlayer1 != numericQuestion.GetAnswer(nQuestion) && nAnswerPlayer2 != numericQuestion.GetAnswer(nQuestion))
		{
			if (abs(numericQuestion.GetAnswer(nQuestion) - nAnswerPlayer1) > abs(numericQuestion.GetAnswer(nQuestion) - nAnswerPlayer2))
				roomUsers.push(playerTwo);
			else
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
					contorPlayer1++;
					std::cout << playerTwo<< ", please choose the position for your base: ";
					std::cin >> line >> column;
					board[{line, column}] = Region::Regions::BasePlayerTwo;
					contorPlayer2++;
					roomUsers.pop();
				}
				else
				{
					board[{line, column}] = Region::Regions::BasePlayerTwo;
					contorPlayer2++;
					std::cout << playerOne << ", please choose the position for your base: ";
					std::cin >> line >> column;
					board[{line, column}] = Region::Regions::BasePlayerOne;
					contorPlayer1++;
					roomUsers.pop();
				}
			}
			else
			{
				std::cout << roomUsers.front() << ", please choose the position for your region: ";
				std::cin >> line >> column;
				if (roomUsers.front() == playerOne)
				{
					board[{line, column}] = Region::Regions::SimpleRegionPlayerOne;
					contorPlayer1++;
					score1 += 100;
				}
				else
				{
					board[{line, column}] = Region::Regions::SimpleRegionPlayerTwo;
					contorPlayer2++;
					score2 += 100;
				}
				roomUsers.pop();
			}
			contor++;
		}
		roomUsers.empty();
	}

	system("cls");
	std::cout << playerOne << ", your score is: " << score1<<'\n';
	std::cout << playerTwo << ", your score is: " << score2<<'\n';
	std::cout << "\n\nThe duel begins!\n";

	while (numberOfRounds != 0)
	{
		std::cout << "Board: \n" << board << std::endl;
		gCorrectAnswer = grillQuestion.GetRandomQuestion();
		
		int randomNumber = numericQuestion.GetRandomNumber(2);

		if (randomNumber + 1 == 1)
		{
			std::cout << playerOne << ", Choose which region you want to attack; PLEASE do not attack your own region :)" << '\n';
			std::cin >> line >> column;
			std::cout << '\n' << playerOne << ", do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
			std::cin >> answerPowerUps;
			if (answerPowerUps == 1)
			{
				try
				{
					powerUpsPlayer1.UsedPowers(option1);
					if (option1 == 1)
					{
						try
						{
							powerUpsPlayer1.FiftyFifty(gCorrectAnswer);
						}
						catch (const char* err)
						{
							std::cout << err;
						}
					}
				}
				catch (const char* error)
				{
					std::cout << error;
				}
			}
			std::cout << std::endl << playerOne << ", write your answer, just the correct letter: ";
			std::cin >> gAnswerPlayer1;

			std::cout << '\n' << playerTwo << ", do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
			std::cin >> answerPowerUps;
			if (answerPowerUps == 1)
			{
				try
				{
					powerUpsPlayer2.UsedPowers(option2);
					if (option2 == 1)
					{
						try
						{
							powerUpsPlayer2.FiftyFifty(gCorrectAnswer);
						}
						catch (const char* err)
						{
							std::cout << err;
						}
					}
				}
				catch (const char* error)
				{
					std::cout << error;
				}
			}
			std::cout << std::endl << playerTwo << ", write your answer, just the correct letter: ";
			std::cin >> gAnswerPlayer2;

			if (gAnswerPlayer1 == gCorrectAnswer && gAnswerPlayer2 == gCorrectAnswer)
			{
				if(playerOne==NumericQuestionPart(playerOne, playerTwo))
				{
						board[{line, column}] = Region::Regions::UpgradedRegionPlayerOne;
						contorPlayer1++;
						contorPlayer2--; score2 -= 100;
						score1 += 100;
				}
				else if (playerTwo == NumericQuestionPart(playerOne, playerTwo))
				{
					numberOfRounds--;
					continue;
				}
			}
			if (gAnswerPlayer1 != gCorrectAnswer && gAnswerPlayer2 == gCorrectAnswer)
			{
				numberOfRounds--;
				continue;
			}
			else if (gAnswerPlayer1 == gCorrectAnswer && gAnswerPlayer2 != gCorrectAnswer)
			{
				board[{line, column}] = Region::Regions::UpgradedRegionPlayerOne;
				contorPlayer1++;
				contorPlayer2--; score2 -= 100;
				score1 += 100;
			}
		}
		else if(randomNumber+1==2)
		{
			std::cout << playerTwo << ", Choose which region you want to attack; PLEASE do not attack your own region :)" << '\n';
			std::cin >> line >> column;

			std::cout << '\n' <<playerTwo <<  ", do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
			std::cin >> answerPowerUps;
			if (answerPowerUps == 1)
			{
				try
				{
					powerUpsPlayer2.UsedPowers(option2);
					if (option2 == 1)
					{
						try
						{
							powerUpsPlayer2.FiftyFifty(gCorrectAnswer);
						}
						catch (const char* err)
						{
							std::cout << err;
						}
					}
				}
				catch (const char* error)
				{
					std::cout << error;
				}
			}
			std::cout << std::endl << playerTwo << ", write your answer, just the correct letter: ";
			std::cin >> gAnswerPlayer2;

			std::cout << '\n' << playerOne <<", do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
			std::cin >> answerPowerUps;
			if (answerPowerUps == 1)
			{
				try
				{
					powerUpsPlayer1.UsedPowers(option1);
					if (option1 == 1)
					{
						try
						{
							powerUpsPlayer1.FiftyFifty(gCorrectAnswer);
						}
						catch (const char* err)
						{
							std::cout << err;
						}
					}
				}
				catch (const char* error)
				{
					std::cout << error;
				}
			}
			std::cout << std::endl << playerOne << ", write your answer, just the correct letter: ";
			std::cin >> gAnswerPlayer1;

			if (gAnswerPlayer2 == gCorrectAnswer && gAnswerPlayer1 == gCorrectAnswer)
			{
				if (playerTwo == NumericQuestionPart(playerOne, playerTwo))
				{
					board[{line, column}] = Region::Regions::UpgradedRegionPlayerTwo;
					contorPlayer2++;
					contorPlayer1--; score1 -= 100;
					score2 += 100;
				}
				else if (playerOne == NumericQuestionPart(playerOne, playerTwo))
				{
					numberOfRounds--;
					continue;
				}
			}
			if (gAnswerPlayer2 != gCorrectAnswer && gAnswerPlayer1 == gCorrectAnswer)
			{
				numberOfRounds--;
				continue;
			}
			else if (gAnswerPlayer2 == gCorrectAnswer && gAnswerPlayer1 != gCorrectAnswer)
			{
				board[{line, column}] = Region::Regions::UpgradedRegionPlayerTwo;
				contorPlayer2++;
				contorPlayer1--; score1-=100;
				score2 += 100;
			}
		}
		if (contorPlayer1 == 9)
		{
			numberOfRounds = 0;
			break;
		}
		else if (contorPlayer2 == 9)
		{
			numberOfRounds = 0;
			break;
		}
		numberOfRounds--;
	}
	if(contorPlayer1==9)
		std::cout << "\033[92m" << "Congratulations! The winner is: " << playerOne;
	else if(contorPlayer2==9)
		std::cout << "\033[92m" << "Congratulations! The winner is: " << playerTwo;
	else
	{
		if (score1 > score2)
			std::cout << "\033[92m" << "Congratulations! The winner is: " << playerOne << ". Your score is: " << score1;
		else
			std::cout << "\033[92m" << "Congratulations! The winner is: " << playerTwo << ". Your score is: " << score2;
	}
	std::cout << "\033[0m";
}

std::string Game::NumericQuestionPart(std::string playerOne, std::string playerTwo)
{
	std::queue<std::string> roomUsers;
	std::string nQuestion;
	int nAnswerPlayer1;
	int nAnswerPlayer2;
	std::string gCorrectAnswer;
	std::string gAnswerPlayer1;
	std::string gAnswerPlayer2;
	int answerPowerUps;
	int option1, option2;
	int score1;
	int score2;
	int line, column;
	int contor = 0;
	nQuestion = numericQuestion.GetRandomNumericQuestion();
	std::cout << '\n' << playerOne << " ,answer to this question! \n" << nQuestion;
	std::cout << '\n' << "Do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
	std::cin >> answerPowerUps;
	if (answerPowerUps == 1)
	{
		try
		{
			powerUpsPlayer1.UsedPowers(option1);
			if (option1 == 2)
			{
				try
				{
					powerUpsPlayer1.CloseAnswer(numericQuestion.GetAnswer(nQuestion));
				}
				catch (const char* err)
				{
					std::cout << err;
				}
			}
			else if (option1 == 3)
			{
				try
				{
					powerUpsPlayer1.Suggestion(numericQuestion.GetAnswer(nQuestion));
				}
				catch (const char* err)
				{
					std::cout << err;
				}
			}
		}
		catch (const char* error)
		{
			std::cout << error;
		}
	}
	else
	{
		std::cout << "Choose your answer: " << '\n';
	}
	auto startPlayerOne = std::chrono::steady_clock::now();
	std::cin >> nAnswerPlayer1;
	auto stopPlayerOne = std::chrono::steady_clock::now();

	std::chrono::duration<double> timePlayerOne = stopPlayerOne - startPlayerOne;

	std::cout << '\n' << playerTwo << " ,answer to this question: \n" << nQuestion;
	std::cout << '\n' << "Do you want to use powerups? Choose 1 for YES and 0 for NO.\n";
	std::cin >> answerPowerUps;
	if (answerPowerUps == 1)
	{
		try
		{
			powerUpsPlayer2.UsedPowers(option2);
			if (option2 == 2)
			{
				try
				{
					powerUpsPlayer2.CloseAnswer(numericQuestion.GetAnswer(nQuestion));
				}
				catch (const char* err)
				{
					std::cout << err;
				}
			}
			else if (option2 == 3)
			{
				try
				{
					powerUpsPlayer2.Suggestion(numericQuestion.GetAnswer(nQuestion));
				}
				catch (const char* err)
				{
					std::cout << err;
				}
			}
		}
		catch (const char* error)
		{
			std::cout << error;
		}
	}
	else
	{
		std::cout << "Choose your answer: " << '\n';
	}
	auto startPlayerTwo = std::chrono::steady_clock::now();
	std::cin >> nAnswerPlayer2;
	auto stopPlayerTwo = std::chrono::steady_clock::now();

	std::chrono::duration<double> timePlayerTwo = stopPlayerTwo - startPlayerTwo;

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
	else if (nAnswerPlayer1 != numericQuestion.GetAnswer(nQuestion) && nAnswerPlayer2 != numericQuestion.GetAnswer(nQuestion))
	{
		if (abs(numericQuestion.GetAnswer(nQuestion) - nAnswerPlayer1) > abs(numericQuestion.GetAnswer(nQuestion) - nAnswerPlayer2))
			roomUsers.push(playerTwo);
		else
			roomUsers.push(playerOne);
	}
	return roomUsers.front();
	roomUsers.empty();
}
