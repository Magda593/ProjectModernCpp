#pragma once
class Region
{
public:
	enum class Base : int
	{
		Base
	};
	enum class SimpleRegion : int
	{
		SimpleRegion
	};
	enum class UpgradedRegion : int
	{
		UpgradedRegion
	};

public:
	Region(Base base, SimpleRegion simpleRegion, UpgradedRegion upgradedRegion);


private:
	Base m_base : 3;
	SimpleRegion m_simpleRegion : 1;
	UpgradedRegion m_upgradedRegion : 2;
};

