#pragma once
#include "AccountManager.h"
#include "QuestionType1.h"
#include "QuestionType2.h"
#include "Board.h"
#include<chrono>
#include<queue>

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
	QuestionType2 question2;
	int m_option;
	int m_numberOfPlayers;
	int m_numberOfRounds;
};

