#pragma once
#include "AccountManager.h"
#include "QuestionType1.h"
#include "NumericQuestion.h"
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

private:
	AccountManager user;
	Board board;
	QuestionType1 question1;
	NumericQuestion numericQuestion;
	int m_option;
	int m_numberOfPlayers;
	int m_numberOfRounds;
};

