#pragma once
#include "MeleeWeapon.h"
namespace weapons {
    /**
     * @brief A typical melee weapon. I want to do not typical melee weapons too
    */
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
		std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator(const olc::vf2d& direction) override;

    	float getHitOffset() const override;
    	
    public:
        TypicalMeleeWeapon(render::ITexture& text, const std::string& name, float cooldownTime, int damage, float range, float hitOffset = .5f, const olc::vf2d& pos = { 0, 0 });
    };
}
