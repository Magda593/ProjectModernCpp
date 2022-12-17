#pragma once
#include "AccountManager.h"
#include "QuestionType1.h"
#include "QuestionType2.h"
#include "Board.h"

class Game
{
public:
	void MenuForTheGame();
	void MenuForALoggedInUser();
	void SetGame();

private:
	AccountManager user;
	Board board;
	QuestionType1 question1;
	QuestionType2 question2;
	int m_option;
};

