#include "RangedWeapon.h"
#include "Pistol.h"
#include "WeaponTextures.h"
#include "EMGun.h"

namespace weapons {
	RangedWeapon::RangedWeapon(render::ITexture& texture, float cooldownTime, int damage, float projectileSpeed, const std::string& name, const olc::vf2d& pos)
		: Weapon(texture, cooldownTime, damage, name, pos), projectileSpeed(projectileSpeed) {}
	
	bool RangedWeapon::use(std::shared_ptr<Entity> user, const olc::vf2d& direction)
	{
		if (cooldown != 0) return false;
		cooldown = cooldownTime;

		this->spawnProjectile(user, this->pos, direction.norm() * projectileSpeed, this->baseDamage);

		return true;
	}

	const Pistol RangedWeapon::pistol(textures::rifle, .3f, 10, 10, "Pistol");
	const EMGun RangedWeapon::emgun(textures::rifle, .08f, 14, 10, "Pistol");
}
