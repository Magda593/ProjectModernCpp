#pragma once
#include <iostream>

class Region
{
public:
	enum class Regions : int
	{
		None = 0,
		SimpleRegionPlayerOne = 101,
		SimpleRegionPlayerTwo = 102,
		SimpleRegionPlayerThree = 103,
		SimpleRegionPlayerFour = 104,
		UpgradedRegionPlayerOne = 201,
		UpgradedRegionPlayerTwo = 202,
		UpgradedRegionPlayerThree = 203,
		UpgradedRegionPlayerFour = 204,
		BasePlayerOne = 301,
		BasePlayerTwo = 302,
		BasePlayerThree = 303,
		BasePlayerFour = 304
	};

public:
	Region();
	Region(Regions region);

	Region(const Region& other);
	Region(Region&& other);
	~Region();

	Region& operator = (const Region& other);
	Region& operator = (Region&& other);

	friend std::ostream& operator << (std::ostream& os, const Region& region);

	Regions GetRegions() const;

private:
	Regions m_region;
};