#pragma once
#include "MeleeWeapon.h"
namespace weapons {
    class TypicalMeleeWeapon :
        public MeleeWeapon
    {
    public:
        static TypicalMeleeWeapon sword;
        static TypicalMeleeWeapon longSword;
        static TypicalMeleeWeapon spoon;

    protected:
    	olc::vf2d getHitBoxSize() const override;
        bool damage(int damage, Entity& attacker) override;
    	
        float maxRange;
        float attackOffset;
        std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator() override;
    	
    public:
        TypicalMeleeWeapon(render::ITexture& text, float cooldownTime, int damage, float range, const olc::vf2d& pos = {0, 0});
    };
}
