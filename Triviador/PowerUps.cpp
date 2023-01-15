#include "PowerUps.h"

PowerUps::PowerUps()
{
}

PowerUps::PowerUps(const std::vector<int> powerUps):
	m_powerUps(powerUps)
{
}

void PowerUps::AllPowers()
{
	for (int i = 0; i < 3; i++) 
	{
		m_powerUps.push_back(1);
	}
}

int PowerUps::UsedPowers(int& nr)
{
	if (m_powerUps[0] == 0 && m_powerUps[1] == 0 && m_powerUps[2] == 0)
	{
		//std::cout << "Sorry! You have no more powerups :(" << '\n';
		throw "Sorry! You have no more powerups :( \n";
		/*return 0;*/
	}
	else
	{
		std::cout << "Use a power:" << std::endl << "1. 50/50 (works only with grill questions)" << std::endl << "2. Close answer" << std::endl << "3. Suggestion (only for numeric question)\n";
		std::cin >> nr;
		if (m_powerUps[nr - 1] == 0)
		{
			throw "\nYou already used this power.\n" ;
			//std::cout << "Use a power:" << std::endl << "1. 50/50 (works only with grill questions)" << std::endl << "2. Close answer" << std::endl << "3. Suggestion (only for numeric question)\n";
			//std::cin >> nr;
		}
		m_powerUps[nr - 1] = 0;
		return nr;
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

