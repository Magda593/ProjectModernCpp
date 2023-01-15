#pragma once
#include "AccountManager.h"
#include "QuestionType1.h"
#include "GrillQuestion.h"
#include "NumericQuestion.h"
#include "PowerUps.h"
#include "Board.h"
#include<chrono>
#include<queue>
#include <cmath>

class Game
{
public:
	void MenuForTheGame();
	void MenuForALoggedInUser();
	void SetGame();

	void Run();
	void Run2();

	//void UsingPowerUps(std::string player, std::string question);

	std::string NumericQuestionPart(std::string playerOne, std::string playerTwo);

private:
	AccountManager user;
	Board board;
	GrillQuestion grillQuestion;
	NumericQuestion numericQuestion;
	PowerUps powerUpsPlayer1;
	PowerUps powerUpsPlayer2;
	int m_option;
	int m_numberOfPlayers;
	int m_numberOfRounds;
};

