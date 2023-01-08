#pragma once
#include <iostream>

class Region
{
public:
	enum class Regions : int
	{
		SimpleRegion,
		UpgradedRegion,
		Base,
		None
	};

public:
	Region();
	Region(Regions region);

	Region(const Region& other);
	Region(Region&& other);
	~Region();

	Region& operator = (const Region& other);
	Region& operator = (Region&& other);

	Regions GetRegions() const;

private:
	Regions m_region : 2;
};