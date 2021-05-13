#pragma once
#include "Weapon.h"

namespace weapons {

    class Pistol;
    class EMGun;

    /**
     * @brief Any weapon, what does shoot. not melee
    */
    class RangedWeapon :
        public Weapon
    {
    public:
        const static Pistol pistol;
        const static EMGun emgun;
    	
    protected:
        float projectileSpeed;

        /**
         * @brief Spawn a projectile entity
         * @param user the user of the weapon
         * @param pos where to
         * @param v0 what speed
         * @param damage what damage
        */
        virtual void spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage) = 0;

    public:

        RangedWeapon(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 });
    	
    	bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;

    	
    };
}
