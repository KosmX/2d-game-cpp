#include "CharacterEntity.h"

namespace entities {
	std::shared_ptr<weapons::Weapon> CharacterEntity::getWeapon()
	{
		return std::shared_ptr<weapons::Weapon>();
	}
	render::ITexture& CharacterEntity::getTexture()
	{
		return texture;
	}
	CharacterEntity::CharacterEntity(render::ITexture& tex, const olc::vf2d& pos)
		: LivingEntity(pos), texture(tex) {}
}
