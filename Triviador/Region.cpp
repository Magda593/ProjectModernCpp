#include "Region.h"

Region::Region() :
	Region(Regions::None)
{
	//Empty
}
//
Region::Region(Regions region) :
	m_region(region)
{
	//Empty
}

Region::Region(const Region& other)
{
	*this = other;
}

Region::Region(Region&& other)
{
	*this = std::move(other);
}

Region::~Region()
{
	m_region = Regions::None;
}
//
Region& Region::operator=(const Region& other)
{
	m_region = other.m_region;

	return *this;
}

Region& Region::operator=(Region&& other)
{
	m_region = other.m_region;

	new(&other) Region;
	return*this;
}

Region::Regions Region::GetRegions() const
{
	return m_region;
}