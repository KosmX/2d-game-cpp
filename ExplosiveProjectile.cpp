#include "ExplosiveProjectile.h"

#include "mainGame.h"


const float explosionRadius = 2.5;

namespace entities
{
	bool ExplosiveProjectile::onCollide(const olc::vf2d& collisionVector, std::shared_ptr<Entity>& who)
	{
		this->state = true;
		for (auto& entity : GameClient::getInstance().getEntities()) {
			if (entity != user && (entity->getPos() - this->getPos()).mag() < explosionRadius)
				entity->damage(this->damageValue, *user);
		}
		return true; //it exploded
	}
	ExplosiveProjectile::ExplosiveProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos0, render::ITexture& texture, int damage)
		: ProjectileEntity(user, pos0, texture) {}
	
	void ExplosiveProjectile::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		if(state){
			stateTime += deltaT;
		}
		else{
			ProjectileEntity::tick(client, deltaT, shared_this);
		}
	}
	
	bool ExplosiveProjectile::canBeRemoved() const
	{
		return stateTime > 1;
	}
	void ExplosiveProjectile::render(olc::TransformedView& scene)
	{
		if(state){
			explosion.render(scene, *this);
		}
		else{
			ProjectileEntity::render(scene);
		}
	}

	render::SimpleSprite ExplosiveProjectile::explosion("Objects/Effect0.png", { 0, 0 }, { 48, 48 });
}
