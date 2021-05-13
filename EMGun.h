#pragma once
#include "Pistol.h"

namespace weapons
{

	/**
	 * @brief Weapon with energy level
	*/
	class EMGun : public Pistol
	{
	private:
		/**
		 * @brief How much energy it does have
		*/
		float energy = 128;
		/**
		 * @brief one shot always uses 10 energy, but recharge rate can be changed
		*/
		float energyRegenRate;
	public:
		EMGun(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 }, float energyRegen = 12);

		bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;

		/**
		 * @brief Shows the energy level in the secondary status-bar
		 * @return 0-1 float
		*/
		float getSecondaryBar() override;

		bool update(float dTick) override;
	};
}
