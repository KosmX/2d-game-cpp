#include "Weapon.h"

namespace weapons
{
	render::ITexture& Weapon::getTexture()
	{
		return this->texture;
	}

	Weapon::Weapon(render::ITexture& texture, float cooldownTime, int damage, const olc::vf2d& pos)
		: Entity(pos), texture(texture), cooldown(0), cooldownTime(cooldownTime), baseDamage(damage) {}

	bool Weapon::update(float dTick)
	{
		this->cooldown = std::max(this->cooldown - dTick, 0.f);
		
		return this->cooldown == 0.f;
	}

	float Weapon::getCooldownBar()
	{
		return this->cooldown / this->cooldownTime;
	}
	
}