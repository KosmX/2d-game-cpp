#include "MeleeWeapon.h"
#include "mainGame.h"

namespace weapons {
    int MeleeWeapon::getDamage() const
    {
        return this->baseDamage;
    }
    bool MeleeWeapon::damageEntity(std::shared_ptr<Entity> user, std::shared_ptr<Entity>& victim)
    {
        return victim->damage(this->getDamage(), *victim);
    }
    bool MeleeWeapon::damageIf(std::shared_ptr<Entity>& user, std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> predicate)
    {
        bool bl = false;
        for(auto& entity : GameClient::getInstance().getEntities()){
	        if(entity != user && predicate(user, entity)){
                bl = damageEntity(user, entity) || bl;
	        }
        }
        return bl;
    }

    MeleeWeapon::MeleeWeapon(render::ITexture& texture, const std::string& name, float cooldownTime, int damage, const olc::vf2d& pos)
	    : Weapon(texture, cooldownTime, damage, name, pos) {}

    bool MeleeWeapon::use(std::shared_ptr<Entity> user, const olc::vf2d& direction)
    {
        if (this->cooldown != 0) return false;
        this->cooldown = this->cooldownTime;
        return damageIf(user, this->getPredicator(direction));
    }

	float MeleeWeapon::getHitOffset() const
	{
        return 0;
	}

	
    void MeleeWeapon::setPos(const olc::vf2d& newPos)
    {
        this->pos = newPos; //I should test its pos...
    }
    bool MeleeWeapon::predicateDistance::operator()(const olc::vf2d& usePos, std::shared_ptr<Entity> other) const
    {
        float d = (usePos - other->getPos()).mag();
        return d > minDistance && d <= maxDistance;
    }
}