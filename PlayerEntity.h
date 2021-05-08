#pragma once
#include "LivingEntity.h"

namespace entities {

    class PlayerEntity :
        public LivingEntity
    {
    private:
        std::string name;
    public:
        void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
        PlayerEntity(olc::vf2d pos, const std::string& name = "Player");
    };
}

entities::PlayerEntity* = new entities::PlayerEntity();