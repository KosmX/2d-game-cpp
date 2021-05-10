#include "MeleeWeapon.h"
#include "mainGame.h"

namespace weapons {
    int MeleeWeapon::getDamage() const
    {
        return this->baseDamage;
    }
    bool MeleeWeapon::damageEntity(std::shared_ptr<LivingEntity> user, std::shared_ptr<Entity>& victim)
    {
        return victim->damage(this->getDamage(), *victim);
    }
    bool MeleeWeapon::damageIf(std::shared_ptr<LivingEntity>& user, bool(*predicate)(std::shared_ptr<Entity> self, std::shared_ptr<Entity> other))
    {
        bool bl = false;
        for(auto& entity : GameClient::getInstance().getEntities()){
	        if(entity != user && predicate(user, entity)){
                bl = damageEntity(user, entity) || bl;
	        }
        }
        return bl;
    }

    bool MeleeWeapon::use(std::shared_ptr<LivingEntity> user)
    {
        if (this->cooldown != 0) return false;
        this->cooldown = this->cooldownTime;
    	
    }
    bool MeleeWeapon::predicateDistance::operator()(std::shared_ptr<Entity> entity, std::shared_ptr<Entity> other) const
    {
        float d = (entity->getPos() - other->getPos()).mag();
        return d > minDistance && d <= maxDistance;
    }
}