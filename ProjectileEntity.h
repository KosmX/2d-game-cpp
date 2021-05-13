#pragma once
#include "Entity.h"
#include "SimpleSprite.h"

namespace entities {
    /**
     * @brief A projectile, a bullet
    */
    class ProjectileEntity :
        public Entity
    {
    public:
        static render::SimpleSprite projectile;
    private:
        render::ITexture& texture;
        /**
         * @brief It will be deleted if it doesn't hit anything in a time
        */
        float age = 0;
    protected:
        olc::vf2d velocity;
        /**
         * @brief Who is the owner of this bullet. needed to not damage the user
        */
        std::shared_ptr<Entity> user;
    	render::ITexture& getTexture() override;

        int damageValue;
        virtual int getDamage();
        /**
         * @brief not used, do a bounce function
         * @param collision collision vector
        */
        virtual void bounce(const olc::vf2d& collision);
		/**
		 * @brief Determines, what will the projectile do, if it hit something.
		 * @param collisionVector the collision vector
		 * @param who who is the affected entity
		 * @return is the projectile destroyed.
		 */
        virtual bool onCollide(const olc::vf2d& collisionVector, std::shared_ptr<Entity>& who);

		olc::vf2d getHitBoxSize() const override;
		
    public:
        ProjectileEntity(std::shared_ptr<Entity>& user, const olc::vf2d& pos0, render::ITexture& texture, int damage = 20);

    	void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;

        /**
         * @brief Set its velocity
         * @param v velocity vector
        */
        virtual void setVelocity(const olc::vf2d& v);
    	bool damage(int damage, Entity& attacker) override;
    };
}
