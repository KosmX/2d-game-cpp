#include "LivingEntity.h"

#include "mainGame.h"

using namespace olc;

namespace entities {

	vf2d LivingEntity::getHitBoxSize() const
	{
		return olc::vf2d(0.8f, 0.8f)/2;
	}

	vf2d LivingEntity::collisionOffset(GameClient& client)
	{
		vf2d offset = { 0, 0 };
		for (auto& entity : client.getEntities()) {
			if(std::dynamic_pointer_cast<LivingEntity>(entity) != nullptr){
				continue;
			}
			vf2d current = this->getCollision(*entity);
			if (offset == vf2d(0, 0)) {
				offset = current;
			}
			else if (offset != current) {
				if (std::abs(offset.dot(current)) < 0.01) {
					offset += current;
				}
				else {
					if (offset.mag2() < current.mag2()) {
						offset = current;
					}
				}
			}
		}
		return offset;
	}

	LivingEntity::LivingEntity(olc::vf2d pos, int health)
		: Entity(pos), direction(0), health(health), anim_phase(0), timeUntilNextPhase(0) {}

	bool LivingEntity::damage(int damage, Entity& attacker)
	{
		if (isAlive()) {
			this->health = std::max(0, this->health - damage);
			if (health == 0) {
				this->is_alive = false;
				std::cout << attacker.getName() << " killed " << this->getName() << "." << std::endl;
			}
			return true;//basically you can do that
		}
		//you can't hurt dead creatures.
		return false;
	}

	char LivingEntity::getDirection()
	{
		if(speed.mag2() < 0.1 ){
			return direction;
		}
		else if(speed.x >= std::abs(speed.y)){
			direction = 2;
		}
		else if(speed.x <= -std::abs(speed.y)){
			direction = 1;
		}
		else if(speed.y >= std::abs(speed.x)){
			direction = 0;
		}
		else{
			direction = 3;
		}
		return direction;
	}

	char LivingEntity::getAnimPhase() const
	{
		return this->anim_phase;
	}

	void LivingEntity::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		timeUntilNextPhase += deltaT * speed.mag();
		if (speed == vf2d(0, 0))anim_phase = 0;
		if(timeUntilNextPhase > phaseLength){
			anim_phase = (anim_phase + 1) % 4;
			timeUntilNextPhase -= phaseLength;
		}
		
		Entity::tick(client, deltaT, shared_this);
		pos += speed * deltaT;
		vf2d offset = collisionOffset(client);
		pos += offset;
	}

	const float LivingEntity::phaseLength = 1;
}