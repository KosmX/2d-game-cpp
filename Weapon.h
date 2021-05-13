#pragma once
#include "Entity.h"

using namespace entities; //yes, I know, I'm using `using namespace` in a header

namespace weapons {
    /**
     * @brief You can throw it to the ground, this is why it's an entity. But it will be possible to use it. and shoot enemies, or projectiles.
     */
    class Weapon :
        public Entity
    {
    private:
        render::ITexture& texture;
		render::ITexture& getTexture() override;
    protected:
        float cooldown;
        float cooldownTime;
        int baseDamage;
        std::string name;
        /**
         * @brief Is on the ground, or in an entity's inventory
        */
        bool isPickedUp = false;
		olc::vf2d getHitBoxSize() const override;
    public:

        Weapon(render::ITexture& texture, float cooldownTime, int damage = 10, const std::string& name = "Weapon", const olc::vf2d& pos = { 0, 0 });

    	/**
    	 * @return true, if you did something with it. false otherwise
    	 */
        virtual bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) = 0;

    	/**
    	 * @brief tick, if on the ground. It does charge energy, or whatever.
    	 * @param client see
    	 * @param deltaT the
    	 * @param shared_this Entity class
    	*/
    	void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override
    	{
            update(deltaT); //weapons on the ground can charge...
    	}

        /**
         * @brief Update the weapon in a Character's inventory
         * @param dTick a.k.a. deltaT, or fElapsedTime
         * @return is the user can use it
        */
        virtual bool update(float dTick);
    	
    	/**
    	 * @brief 0 - 1 cooldown, 1 is ready to use, more than one makes sense, like 2 charges
    	 * @return cooldown time
    	 */
        virtual float getCooldownBar();

    	/**
    	 * @brief Can be removed form the ground. 
    	 * @return true if someone picked it up
    	*/
    	bool canBeRemoved() const override;

        /**
         * @brief Mutator to isPickedUp
         * @param bl bool
        */
        virtual void setPickUp(bool bl);

    	/**
    	 * @brief Secondary charge bar. for some purpose
    	 */
        virtual float getSecondaryBar() { return 0; }
        virtual void setPos(const olc::vf2d& newPos);

    	bool damage(int damage, Entity& attacker) override;
    };
}