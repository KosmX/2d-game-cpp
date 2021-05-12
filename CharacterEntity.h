#pragma once
#include "LivingEntity.h"

namespace weapons
{
    class Weapon;
}

namespace entities {
    class CharacterEntity :
        public LivingEntity
    {
    protected:
    	/**
    	 * Return null if not available
    	 */
        virtual std::shared_ptr<weapons::Weapon> getWeapon();

        render::ITexture& texture;
		render::ITexture& getTexture() override;
    public:
        CharacterEntity(render::ITexture& skin, const olc::vf2d& pos);
    	void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
    	void render(olc::TransformedView& scene) override;
    };
}
