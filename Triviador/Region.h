#pragma once
#include <iostream>

class Region
{
public:
	enum class Regions : int
	{
		None = 0,
		SimpleRegion = 100,
		UpgradedRegion = 200,
		Base = 300
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