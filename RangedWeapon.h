#pragma once
#include "Weapon.h"

namespace weapons {

    class Pistol;
    class EMGun;
	
    class RangedWeapon :
        public Weapon
    {
    public:
        const static Pistol pistol;
        const static EMGun emgun;
    	
    protected:
        float projectileSpeed;
    	
        virtual void spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage) = 0;

    public:

        RangedWeapon(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 });
    	
    	bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;

    	
    };
}
