#pragma once
#include "Entity.h"

using namespace entities; //yes, I know, I'm using `using namespace` in a header

namespace weapons {
    /**
     * You can throw it to the ground, this is why it's an entity. But it will be possible to use it. and shoot enemies.
     * or projectiles.
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
    public:

        Weapon(render::ITexture& texture, float cooldownTime, int damage = 10, const std::string& name = "Weapon", const olc::vf2d& pos = { 0, 0 });

    	/**
    	 * @return true, if can use
    	 */
        virtual bool use(std::shared_ptr<LivingEntity> user, const olc::vf2d& direction) = 0;

        virtual bool update(float dTick);
    	
    	/**
    	 * 0 - 1 cooldown, 1 is ready to use, more than one makes sense,
    	 * like 2 charges
    	 */
        virtual float getCooldownBar();

    	/**
    	 * Secondary charge bar. for some purpose
    	 */
        virtual float getSecondaryBar() { return 0; }
    };
}