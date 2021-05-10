#pragma once
#include "Entity.h"
namespace entities {
	class LivingEntity :
		public Entity
	{
	private:
		int health;
		char direction;
		char anim_phase;
		float timeUntilNextPhase;
		const static float phaseLength;
	protected:
		olc::vf2d getHitBoxSize() const override;
		olc::vf2d speed;
		virtual olc::vf2d collisionOffset(GameClient& client);
		
	public:
		LivingEntity(olc::vf2d pos, int health = 512);
		bool damage(int damage, Entity& attacker) override;
		char getDirection();
		char getAnimPhase() const;


		void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override; //TODO

		LivingEntity* getAsLivingEntity() override;
	};
}
