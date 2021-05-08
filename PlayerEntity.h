#pragma once
#include "LivingEntity.h"

namespace entities {

    class PlayerEntity :
        public LivingEntity
    {
    private:
        std::string name;
        render::ITexture& texture;
		render::ITexture& getTexture() override;
    public:
        void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
        PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name = "Player");
    };
}
