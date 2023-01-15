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
	std::cout << "Use a power:" << std::endl << "1. 50/50" << std::endl << "2. Close answer" << std::endl << "3.";
	std::cin >> nr;
	powerUps[nr] = 0;
	for (int i = 0; i < powerUps.size(); i++) 
	{
		std::cout<<powerUps[i]<<" ";
	}
}

void PowerUps::CloseAnswer(int answer)
{
	if (answer % 2 == 0)
	{
		std::cout << answer - 10 << '\n';
		std::cout << answer + 12 << '\n';
		std::cout << answer - 25 << '\n';
		std::cout << answer << '\n';
	}
	else
	{
		std::cout << answer << '\n';
		std::cout << answer - 2 << '\n';
		std::cout << answer + 5 << '\n';
		std::cout << answer - 31 << '\n';
	}
}

void PowerUps::Suggestion(int answer)
{
	if (answer % 2 == 0)
		std::cout << answer + 10<<'\n';
	else
		std::cout << answer - 10<<'\n';
}

void PowerUps::FiftyFifty(std::string answer)
{
	//m_question.ShowTwoOptions();
	if (answer=="a")
	{
		std::cout << "Please choose between a and c" << '\n';
	}
	if (answer=="b")
	{
		std::cout << "Please choose between b and d" << '\n';
	}
	if (answer=="c")
	{
		std::cout << "Please choose between a and c" << '\n';
	}
	if (answer=="d")
	{
		std::cout << "Please choose between a and d" << '\n';
	}
}

