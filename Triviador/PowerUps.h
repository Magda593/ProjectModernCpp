#pragma once
#include <vector>
#include <iostream>
#include "GrillQuestion.h"

class PowerUps
{
public:
	PowerUps();
	PowerUps(const std::vector<int> powerUps);

	void AllPowers(std::vector<int> powerUps);
	void UsedPowers(std::vector<int> powerUps);

	void CloseAnswer(int answer);
	void FiftyFifty(std::string answer);
	void Suggestion(int answer);

private:
	GrillQuestion m_question;
	std::vector<int> m_powerUps;
};

