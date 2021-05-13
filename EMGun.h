#pragma once
#include "Pistol.h"

namespace weapons
{


	class EMGun : public Pistol
	{
	private:
		float energy = 128;
	public:
		EMGun(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 });

		bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;

		float getSecondaryBar() override;

		bool update(float dTick) override;
	};
}
