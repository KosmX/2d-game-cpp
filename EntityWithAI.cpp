#include "EntityWithAI.h"

#include "mainGame.h"
#include "Weapon.h"
#include "RangedWeapon.h"

using namespace std;
using namespace olc;

const float maxAttackCooldown = 1.2f;

namespace entities
{
	void EntityWithAI::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		vf2d dir = client.getPlayerEntity()->getPos() - getPos();
		speed = dir.norm() * 2;
		if(this->weapon){//Has a weapon
			weapon->update(deltaT);
			weapon->use(shared_this, dir.norm()); //Just try to use the weapon...
			if(dynamic_pointer_cast<weapons::RangedWeapon>(weapon)){
				if(dir.mag2() < 100){
					dir = { 0, 0 };
				}
			}
			else{
				if(dir.mag2() < 1){
					dir = { 0, 0 };
				}
			}
		}
		else{
			attackCooldown = std::max(attackCooldown - deltaT, 0.f);
			if (dir.mag2() < 1) {
				speed = { 0, 0 };
				if (attackCooldown == 0) {
					client.getPlayerEntity()->damage(damageAmount, *this);
					attackCooldown = maxAttackCooldown;
				}
			}
		}
		CharacterEntity::tick(client, deltaT, shared_this);
	}
	void EntityWithAI::addWeapon(std::shared_ptr<weapons::Weapon>& weapon)
	{
		this->weapon = weapon;
	}

	EntityWithAI::EntityWithAI(const olc::vf2d& pos, render::ITexture& skin, int damage, const std::string& name)
		: CharacterEntity(skin, pos), damageAmount(damage) {}

	bool EntityWithAI::damage(int damage, Entity& attacker)
	{
		bool bl = CharacterEntity::damage(damage, attacker);
		if (bl && !isAlive() && weapon && rand() % 4 == 0) { //it this died, and has a weapon, there is a little chance to it will drop its weapon
			GameClient::getInstance() += weapon;
		}
		this->weapon = nullptr;
		return false;
	}
	std::shared_ptr<weapons::Weapon> EntityWithAI::getWeapon()
	{
		return weapon;
	}
}