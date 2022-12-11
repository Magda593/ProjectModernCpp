#include "Region.h"

Region::Region() :
	Region(Base::None, SimpleRegion::None, UpgradedRegion::None)
{
	//Empty
}

Region::Region(Base base, SimpleRegion simpleRegion, UpgradedRegion upgradedRegion) :
	m_base(base),
	m_simpleRegion(simpleRegion),
	m_upgradedRegion(upgradedRegion)
{
	//Empty
}

Region& Region::operator=(const Region& other)
{
	m_base = other.m_base;
	m_simpleRegion = other.m_simpleRegion;
	m_upgradedRegion = other.m_upgradedRegion;

	return *this;
}

Region& Region::operator=(Region&& other)
{
	m_base = other.m_base;
	m_simpleRegion = other.m_simpleRegion;
	m_upgradedRegion = other.m_upgradedRegion;

	new(&other) Region;
	return*this;
}

Region::Base Region::GetBase() const
{
	return m_base;
}

Region::SimpleRegion Region::GetSimpleRegion()
{
	return m_simpleRegion;
}

Region::UpgradedRegion Region::GetUpgradedRegion()
{
	return m_upgradedRegion;
}
