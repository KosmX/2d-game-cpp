#pragma once

#include "CharacterEntity.h"

namespace entities
{

	
	class EntityWithAI : public CharacterEntity
	{
	private:
		std::shared_ptr<weapons::Weapon> weapon;
		float attackCooldown = 0;
		const int damageAmount;
	public:
		void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;

		void addWeapon(std::shared_ptr<weapons::Weapon>& weapon);
		EntityWithAI(const olc::vf2d& pos, render::ITexture& skin, int damage = 20, const std::string& name = "Enemy");

		bool damage(int damage, Entity& attacker) override;

		std::shared_ptr<weapons::Weapon> getWeapon() override;
	};
}
