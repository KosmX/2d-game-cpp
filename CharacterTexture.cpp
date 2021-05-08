#include "CharacterTexture.h"

#include "Entity.h"
#include "GameException.h"
#include "LivingEntity.h"

using namespace olc;

namespace render {

	CharacterTexture::CharacterTexture(const std::string& name, vf2d size)
		: sprite(name), size(size) {}

	void CharacterTexture::render(TransformedView& scene, entities::Entity& entity)
	{
		if (entity.getAsLivingEntity() == nullptr) {
			throw GameException("Can't render character texture for a not-living entity...", entity);
		}
		entities::LivingEntity& livingEntity = *entity.getAsLivingEntity();
		vf2d pos = this->uv + vf2d(livingEntity.getAnimPhase() * this->size.x, livingEntity.getDirection() * size.y);
		this->sprite.renderCentered(scene, entity.getPos(), pos, size, entity.getSize());
	}

	CharacterTexture CharacterTexture::EngineerTexture("Commissions/Engineer.png");
	CharacterTexture CharacterTexture::MageTexture("Commissions/Mage.png");
}