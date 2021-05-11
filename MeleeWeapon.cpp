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

    MeleeWeapon::MeleeWeapon(render::ITexture& texture, float cooldownTime, int damage, const olc::vf2d& pos)
	    : Weapon(texture, cooldownTime, damage, pos) {}

    bool MeleeWeapon::use(std::shared_ptr<LivingEntity> user, const olc::vf2d& direction)
    {
        if (this->cooldown != 0) return false;
        this->cooldown = this->cooldownTime;
    }
    void MeleeWeapon::setPos(const olc::vf2d& newPos)
    {
        this->pos = newPos; //I should test its pos...
    }
    bool MeleeWeapon::predicateDistance::operator()(std::shared_ptr<Entity> entity, std::shared_ptr<Entity> other) const
    {
        float d = (entity->getPos() - other->getPos()).mag();
        return d > minDistance && d <= maxDistance;
    }
}