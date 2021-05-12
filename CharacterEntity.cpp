#include "CharacterEntity.h"

#include "Weapon.h"

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
	void CharacterEntity::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		LivingEntity::tick(client, deltaT, shared_this);
		if(this->getWeapon()){
			this->getWeapon()->update(deltaT);
			this->getWeapon()->setPos(this->getPos() + this->speed != olc::vf2d(0, 0) ? this->speed.norm()/2 : olc::vf2d(0, 0));
		}
	}

	void CharacterEntity::render(olc::TransformedView& scene)
	{
		LivingEntity::render(scene);
		if (this->getWeapon()) {
			this->getWeapon()->render(scene);
		}
	}
}
