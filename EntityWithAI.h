#pragma once

#include "CharacterEntity.h"

namespace entities
{

	/**
	 * @brief The enemies. go after the player, and try to kill it
	*/
	class EntityWithAI : public CharacterEntity
	{
	private:
		/**
		 * @brief Its weapon, can be nullptr
		*/
		std::shared_ptr<weapons::Weapon> weapon;
		/**
		 * @brief the attack cooldown variable
		*/
		float attackCooldown = 0;
		/**
		 * @brief How strong is our foe.
		*/
		const int damageAmount;
	public:

		/**
		 * @brief Tick, from Entity
		 * @param client client
		 * @param deltaT fElapsedTime
		 * @param shared_this it as a shared_ptr
		*/
		void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
		/**
		 * @brief override it's weapon
		 * @param weapon the new weapon, can be nullptr
		*/
		void addWeapon(std::shared_ptr<weapons::Weapon>& weapon);
		EntityWithAI(const olc::vf2d& pos, render::ITexture& skin, int damage = 20, const std::string& name = "Enemy");

		bool damage(int damage, Entity& attacker) override;

		std::shared_ptr<weapons::Weapon> getWeapon() override;
	};
}
