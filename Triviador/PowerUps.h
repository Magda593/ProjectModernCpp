#pragma once
#include <vector>
#include <iostream>
#include "Question.h"

class PowerUps
{
public:
	PowerUps();
	PowerUps(const std::vector<int> powerUps);

	void AllPowers(std::vector<int> powerUps);
	void UsedPowers(std::vector<int> powerUps);

	void CloseAnswer(int answer);
	//void FiftyFifty(std::vector<Question> question);

private:
	std::vector<int> m_powerUps;
};

