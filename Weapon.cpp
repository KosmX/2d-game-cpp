#include "Weapon.h"

namespace weapons
{
	render::ITexture& Weapon::getTexture()
	{
		return this->texture;
	}

	olc::vf2d Weapon::getHitBoxSize() const
	{
		return olc::vf2d(0, 0);
	}

	Weapon::Weapon(render::ITexture& texture, float cooldownTime, int damage, const std::string& name, const olc::vf2d& pos)
		: Entity(pos), texture(texture), cooldown(0), cooldownTime(cooldownTime), baseDamage(damage), name(name) {}

	bool Weapon::update(float dTick)
	{
		this->cooldown = std::max(this->cooldown - dTick, 0.f);
		
		return this->cooldown == 0.f;
	}

	float Weapon::getCooldownBar()
	{
		return 1 - this->cooldown / this->cooldownTime;
	}

	bool Weapon::canBeRemoved() const
	{
		return isPickedUp;
	}

	void Weapon::setPickUp(bool bl)
	{
		isPickedUp = bl;
	}

	void Weapon::setPos(const olc::vf2d& newPos)
	{
		this->pos = newPos;
	}

	bool Weapon::damage(int damage, Entity& attacker)
	{
		return false;
	}

	
}