#pragma once
#include <vector>
#include <iostream>
class PowerUps
{
public:
	PowerUps();
	PowerUps(const std::vector<int> powerUps);

	void AllPowers(std::vector<int> powerUps);
	void UsedPowers(std::vector<int> powerUps);

	//void FiftyFifty();
	//void CloseAnswer();
private:
	std::vector<int> m_powerUps;
};

