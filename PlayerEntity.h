#pragma once
#include "CharacterEntity.h"

namespace entities {

    class PlayerEntity :
        public CharacterEntity
    {
    private:
        std::string name;
        std::shared_ptr<weapons::Weapon> weaponToPickUp;
    public:
        void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
        PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name = "Player");
    };
}
