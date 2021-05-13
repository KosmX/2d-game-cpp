#pragma once
#include "Weapon.h"
#include <functional>

namespace weapons {
    /**
     * @brief A melee weapon, like a spoon
    */
    class MeleeWeapon :
        public Weapon
    {
    protected:
        virtual int getDamage() const;
        /**
         * @brief Damage the victim
         * @param user user
         * @param victim victim
         * @return true, if it could damage. false for a wall...
        */
        virtual bool damageEntity(std::shared_ptr<Entity> user, std::shared_ptr<Entity>& victim);
        /**
         * @brief Tries to damage every entity in a range.
         * @param user user
         * @param predicate range selector predicate
         * @return true, if it could damage at least one entity
        */
        virtual bool damageIf(std::shared_ptr<Entity>& user, std::function<bool(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other)> predicate);
        /**
         * @brief The predicate function getter for the damageIf
         * @param direction users direction
         * @return the predicate
        */
        virtual std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator(const olc::vf2d& direction) = 0;

        /**
         * @brief the hit's center distance from the user
         * @return float
        */
        virtual float getHitOffset() const;
    	/**
    	 * @brief Functor to predicate entity distance. You can also use lambda, if you want
    	 */
        class predicateDistance
        {
        public:
            float minDistance = 0;
            float maxDistance = 5;
            /**
             * @brief A functor
             * @param usePos :D
             * @param other :)
             * @return is the potential victim in the range
            */
            bool operator()(const olc::vf2d& usePos, std::shared_ptr<Entity> other) const;
        };
    
    public:
        MeleeWeapon(render::ITexture& texture, const std::string& name, float cooldownTime, int damage = 10, const olc::vf2d& pos = { 0, 0 });
    	
        bool use(std::shared_ptr<Entity> user, const olc::vf2d& direction) override;
    };
}
