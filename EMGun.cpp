#include "EMGun.h"


namespace weapons {
	weapons::EMGun::EMGun(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed, const std::string& name, const olc::vf2d& pos)
		: Pistol(texture, cooldownTime, damage, projectileSpeed, name, pos) {}
	bool EMGun::use(std::shared_ptr<Entity> user, const olc::vf2d& direction)
	{
		if (cooldown != 0) return false;
		if (energy < 10) return false;
		cooldown = cooldownTime;
		energy -= 10;

		this->spawnProjectile(user, this->pos, direction.norm() * projectileSpeed, this->baseDamage);

		return true;
	}
	float EMGun::getSecondaryBar()
	{
		return energy / 128;
	}
	bool EMGun::update(float dTick)
	{
		energy = std::min(energy + 6 * dTick, 128.f);
		return Pistol::update(dTick) && energy > 10;
	}
}
