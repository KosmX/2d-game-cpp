#pragma once
#include "ProjectileEntity.h"

namespace entities {
	/**
	 * @brief A projectile, that explodes
	*/
	class ExplosiveProjectile :
		public ProjectileEntity
	{
	private:
		/**
		 * @brief After exploding, it will expire
		*/
		float stateTime = 0;
		/**
		 * @brief Is still a projectile, or a fireball
		*/
		bool state = false;
		static render::SimpleSprite explosion;
	protected:
		bool onCollide(const olc::vf2d& collisionVector, std::shared_ptr<Entity>& who) override;
	public:
		ExplosiveProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos0, render::ITexture& texture, int damage = 40);

		void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;

		bool canBeRemoved() const override;

		void render(olc::TransformedView& scene) override;
	};
}
