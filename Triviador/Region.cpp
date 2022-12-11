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

