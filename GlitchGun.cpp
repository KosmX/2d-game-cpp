#include "GlitchGun.h"

#include "ExplosiveProjectile.h"
#include "mainGame.h"

using namespace std;
using namespace entities;
using namespace olc;

namespace weapons {

	weapons::GlitchGun::GlitchGun(float cooldownTime, int damage, float projectileSpeed, const std::string& name, const olc::vf2d& pos, float energyRegen)
		: EMGun(GlitchGun::GlitchTexture, cooldownTime, damage, projectileSpeed, name, pos, energyRegen) {}

	void weapons::GlitchGun::spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage)
	{
		if (rand() % 8 == 0) {
			shared_ptr<ExplosiveProjectile> projectile(new ExplosiveProjectile(user, pos, ProjectileEntity::projectile, damage));
			projectile->setVelocity(v0);
			GameClient::getInstance() += projectile;
		}
		else {
			EMGun::spawnProjectile(user, pos, v0, damage);
		}
	}

	bool weapons::GlitchGun::update(float dTick)
	{
		timeState += dTick;
		if (timeState > 2) {
			timeState -= 2;
		}
		return EMGun::update(dTick);
	}

	weapons::GlitchTexture::GlitchTexture(const std::string& name)
		: sprite(name) {}

	void weapons::GlitchTexture::render(olc::TransformedView& scene, Entity& entity)
	{
		GlitchGun& gun = dynamic_cast<GlitchGun&>(entity);
		vi2d pos = { 0, 0 };
		if (gun.timeState > 1) {
			pos += {0, 16};
		}
		if (gun.timeState > 0.5f && gun.timeState < 1 || gun.timeState > 1.5) {
			pos += {16, 0};
		}
		sprite.renderCentered(scene, gun.getPos(), pos, { 16, 16 });
	}
	GlitchTexture GlitchGun::GlitchTexture;
}