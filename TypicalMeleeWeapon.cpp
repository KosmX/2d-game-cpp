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
	std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> TypicalMeleeWeapon::getPredicator(const olc::vf2d& direction)
	{
		predicateDistance p;
		p.maxDistance = this->maxRange;
		return [p, direction, this](std::shared_ptr<Entity> user, std::shared_ptr<Entity> entity)->bool
		{
			if (user == entity) return false;
			return p(user->getPos() + direction * this->getHitOffset(), entity);
		};
	}

	float TypicalMeleeWeapon::getHitOffset() const
	{
		return this->attackOffset;
	}

	TypicalMeleeWeapon::TypicalMeleeWeapon(render::ITexture& text, const std::string& name, float cooldownTime, int damage, float range, float hitOffset, const olc::vf2d& pos)
		: MeleeWeapon(text, name, cooldownTime, damage, pos), maxRange(range), attackOffset(hitOffset) {}

	TypicalMeleeWeapon TypicalMeleeWeapon::sword(textures::sword1, "Sharp stick", 1, 16, 1);
	TypicalMeleeWeapon TypicalMeleeWeapon::longSword(textures::sword1, "Long sharp stick", 3, 16, 3, 1);
	TypicalMeleeWeapon TypicalMeleeWeapon::spoon(textures::sword1, "Spoon", 3, 32, 0.7f, 0.4f);
}