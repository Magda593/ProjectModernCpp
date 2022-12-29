#pragma once
#include <iostream>

class Region
{
public:
	enum class Base : int
	{
		None,
		Base
	};
	enum class SimpleRegion : int
	{
		None,
		SimpleRegion
	};
	enum class UpgradedRegion : int
	{
		None,
		UpgradedRegion
	};

public:
	Region();
	Region(Base base, SimpleRegion simpleRegion, UpgradedRegion upgradedRegion);

	Region& operator = (const Region& other);
	Region& operator = (Region&& other);

	Base GetBase() const;
	SimpleRegion GetSimpleRegion();
	UpgradedRegion GetUpgradedRegion();

private:
	Base m_base : 3;
	SimpleRegion m_simpleRegion : 1;
	UpgradedRegion m_upgradedRegion : 2;
};