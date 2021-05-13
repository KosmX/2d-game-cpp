#pragma once

#include "RangedWeapon.h"

namespace weapons
{
	/**
	 * @brief Just a pistol, nothing too dangerous
	*/
	class Pistol :
		public RangedWeapon
	{
	public:
		void spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage) override;
		Pistol(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 });
	};
}
