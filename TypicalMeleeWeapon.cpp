#include "TypicalMeleeWeapon.h"

std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> weapons::TypicalMeleeWeapon::getPredicator()
{
	predicateDistance p;
	p.maxDistance = this->maxRange;
	return p;
}
