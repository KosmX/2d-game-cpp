#include "TypicalMeleeWeapon.h"

#include "WeaponTextures.h"

namespace weapons {
	olc::vf2d TypicalMeleeWeapon::getHitBoxSize() const
	{
		return olc::vf2d(0, 0);
	}
	bool TypicalMeleeWeapon::damage(int damage, Entity& attacker)
	{
		return false;
	}
	std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> TypicalMeleeWeapon::getPredicator()
	{
		predicateDistance p;
		p.maxDistance = this->maxRange;
		return p;
	}

	TypicalMeleeWeapon::TypicalMeleeWeapon(render::ITexture& text, float cooldownTime, int damage, float range, const olc::vf2d& pos)
		: MeleeWeapon(text, cooldownTime, damage, pos), maxRange(range) {}

	TypicalMeleeWeapon TypicalMeleeWeapon::sword(textures::sword1, 1, 16, 1);
	TypicalMeleeWeapon TypicalMeleeWeapon::longSword(textures::sword1, 3, 16, 3);
	TypicalMeleeWeapon TypicalMeleeWeapon::spoon(textures::sword1, 3, 16, 3);
}