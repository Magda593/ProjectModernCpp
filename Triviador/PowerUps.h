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

	void CloseAnswer(int answer)
	{
		std::cin >> answer;
		if (answer % 2 == 0)
			std::cout << answer + 10;
		else
			std::cout << answer - 10;
	}

	//void FiftyFifty();
	//void CloseAnswer();
private:
	std::vector<int> m_powerUps;
};

