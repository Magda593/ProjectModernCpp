#pragma once
#include <vector>
class PowerUps
{
public:
	PowerUps();
	PowerUps(const std::vector<int> powerUps);
private:
	std::vector<int> m_powerUps;
};

