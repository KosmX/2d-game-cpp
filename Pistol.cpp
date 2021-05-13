#include "Pistol.h"

#include "mainGame.h"
#include "ProjectileEntity.h"

using namespace std;
using namespace olc;

namespace weapons {

	Pistol::Pistol(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed, const std::string& name, const olc::vf2d& pos)
		: RangedWeapon(texture, cooldownTime, damage, projectileSpeed, name, pos) {}

	
	void Pistol::spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage)
	{
		shared_ptr<ProjectileEntity> projectile(new ProjectileEntity(user, pos, ProjectileEntity::projectile, damage));
		projectile->setVelocity(v0);
		GameClient::getInstance() += projectile;
	}
}
