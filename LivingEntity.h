#pragma once
#include "Entity.h"
namespace entities {
	/**
	 * @brief Any moving animal or player
	*/
	class LivingEntity :
		public Entity
	{
	private:
		/**
		 * @brief It is moving to that direction
		*/
		char direction;
		/**
		 * @brief it is animated
		*/
		char anim_phase;
		/**
		 * @brief animation internal variable
		*/
		float timeUntilNextPhase;
		/**
		 * @brief animation internal constant
		*/
		const static float phaseLength;
	protected:
		olc::vf2d getHitBoxSize() const override;
		/**
		 * @brief Its speed and moving direction
		*/
		olc::vf2d speed;
		virtual olc::vf2d collisionOffset(GameClient& client);
		/**
		 * @brief It has a health
		*/
		int health;
	public:
		LivingEntity(olc::vf2d pos, int health = 100);
		bool damage(int damage, Entity& attacker) override;
		/**
		 * @brief Animation related getter
		 * @return its direction
		*/
		char getDirection();
		/**
		 * @brief Animation phase
		 * @return phase
		*/
		char getAnimPhase() const;


		void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override; //TODO
	};
}
