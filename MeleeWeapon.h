#pragma once
#include "Weapon.h"
#include <functional>

namespace weapons {
    class MeleeWeapon :
        public Weapon
    {
    protected:
        virtual int getDamage() const;
        virtual bool damageEntity(std::shared_ptr<Entity> user, std::shared_ptr<Entity>& victim);
        virtual bool damageIf(std::shared_ptr<Entity>& user, std::function<bool(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other)> predicate);
        //virtual bool(*getPredicator())(std::shared_ptr<Entity>, std::shared_ptr<Entity>) = 0;
        virtual std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator(const olc::vf2d& direction) = 0;

        virtual float getHitOffset() const;
    	/**
    	 * Functor to predicate entity distance.
    	 * You can also use lambda, if you want
    	 */
        class predicateDistance
        {
        public:
            float minDistance = 0;
            float maxDistance = 5;
            bool operator()(const olc::vf2d& usePos, std::shared_ptr<Entity> other) const;
        };
    
    public:
        MeleeWeapon(render::ITexture& texture, const std::string& name, float cooldownTime, int damage = 10, const olc::vf2d& pos = { 0, 0 });
    	
        bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;
        virtual void setPos(const olc::vf2d& newPos);
    };
}
