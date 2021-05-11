#pragma once
#include "Weapon.h"
#include <functional>

namespace weapons {
    class MeleeWeapon :
        public Weapon
    {
    protected:
        virtual int getDamage() const;
        virtual bool damageEntity(std::shared_ptr<LivingEntity> user, std::shared_ptr<Entity>& victim);
        virtual bool damageIf(std::shared_ptr<LivingEntity>& user, bool(*predicate)(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other));
        //virtual bool(*getPredicator())(std::shared_ptr<Entity>, std::shared_ptr<Entity>) = 0;
        virtual std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator() = 0;
    	
    	/**
    	 * Functor to predicate entity distance.
    	 * You can also use lambda, if you want
    	 */
        class predicateDistance
        {
        public:
            float minDistance = 0;
            float maxDistance = 5;
            bool operator()(std::shared_ptr<Entity> entity, std::shared_ptr<Entity> other) const;
        };
    
    public:
        MeleeWeapon(render::ITexture& texture, float cooldownTime, int damage = 10, const olc::vf2d& pos = { 0, 0 });
    	
        bool use(std::shared_ptr<LivingEntity> user, const olc::vf2d& direction) override;
        virtual void setPos(const olc::vf2d& newPos);
    };
}
