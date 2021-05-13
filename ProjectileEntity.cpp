#include "ProjectileEntity.h"

#include "LivingEntity.h"
#include "mainGame.h"

namespace entities {
	render::ITexture& ProjectileEntity::getTexture()
	{
		return texture;
	}
	int ProjectileEntity::getDamage()
	{
		return damageValue;
	}
	void ProjectileEntity::bounce(const olc::vf2d& collision)
	{
		this->pos += collision; //first resolve the collision
		if (collision.x) {
			this->velocity.x *= -1;
		}
		if (collision.y) {
			velocity.y *= -1;
		}
	}
	bool entities::ProjectileEntity::onCollide(const olc::vf2d& collisionVector, std::shared_ptr<Entity>& who)
	{
		if (std::dynamic_pointer_cast<ProjectileEntity>(who) == nullptr && who != this->user && collisionVector != olc::vf2d(0, 0)) {
			who->damage(this->getDamage(), *this->user);
			this->is_alive = false;
			return true;
		}
		return false;
	}
	olc::vf2d ProjectileEntity::getHitBoxSize() const
	{
		return olc::vf2d(0.2, 0.2);
	}
	ProjectileEntity::ProjectileEntity(std::shared_ptr<Entity>& user, const olc::vf2d& pos0, render::ITexture& texture, int damage)
		: Entity(pos0), user(user), texture(texture), damageValue(damage) {}
	
	void ProjectileEntity::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		this->pos += this->velocity * deltaT;
		for(auto& entity : client.getEntities()){
			if(entity != this->user && std::dynamic_pointer_cast<ProjectileEntity>(entity) == nullptr){ //we ignore the user and other projectiles
				olc::vf2d collision = getCollision(*entity);
				if(collision != olc::vf2d(0, 0)){
					if(this->onCollide(collision, entity)){
						this->is_alive = false;
						return;
					}
				}
			}
		}
	}
	void ProjectileEntity::setVelocity(const olc::vf2d& v)
	{
		this->velocity = v;
	}
	bool ProjectileEntity::damage(int damage, Entity& attacker)
	{
		return false;
	}

	render::SimpleSprite ProjectileEntity::projectile("status.png", { 0, 16 });
}
