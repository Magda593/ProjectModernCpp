#include "Region.h"

Region::Region(Base base, SimpleRegion simpleRegion, UpgradedRegion upgradedRegion) :
	m_base(base),
	m_simpleRegion(simpleRegion),
	m_upgradedRegion(upgradedRegion)
{
}
