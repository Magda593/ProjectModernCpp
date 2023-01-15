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
	void FiftyFifty(GrillQuestion currentQuestion, const GrillQuestion& question);

private:
	std::vector<int> m_powerUps;
};

