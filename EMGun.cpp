#include "EMGun.h"
#include <random>

namespace weapons {
	EMGun::EMGun(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed, const std::string& name, const olc::vf2d& pos, float energyRegen)
		: Pistol(texture, cooldownTime, damage, projectileSpeed, name, pos), energyRegenRate(energyRegen) {}
	
	bool EMGun::use(std::shared_ptr<Entity> user, const olc::vf2d& direction)
	{
		if (energy < 10) return false;

		float r1 = (rand() % 1024 - 512) / 512.0;
		float r2 = (rand() % 1024 - 512) / 512.0;
		olc::vf2d randv(r1, r2);
		randv = randv.norm()*direction.mag();
		if(Pistol::use(user, direction + randv/8)){
			energy -= 10;
			return true;
		}
		return false;
	}
	float EMGun::getSecondaryBar()
	{
		return energy / 128.f;
	}
	bool EMGun::update(float dTick)
	{
		energy = std::min(energy + energyRegenRate * dTick, 128.f);
		return Pistol::update(dTick) && energy > 10;
	}
}
