#include "PowerUps.h"

PowerUps::PowerUps()
{
}

PowerUps::PowerUps(const std::vector<int> powerUps):
	m_powerUps(powerUps)
{
}

void PowerUps::AllPowers(std::vector<int> powerUps)
{
	for (int i = 0; i < powerUps.size(); i++) 
	{
		powerUps[i] = 1;
	}
}

void PowerUps::UsedPowers(std::vector<int> powerUps)
{
	int nr;
	std::cout << "Use a power:" << std::endl << "1. 50/50" << std::endl << "2." << std::endl << "3.";
	std::cin >> nr;
	powerUps[nr] = 0;
	for (int i = 0; i < powerUps.size(); i++) 
	{
		std::cout<<powerUps[i]<<" ";
	}
}