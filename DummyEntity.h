#pragma once
#include "CharacterEntity.h"

namespace entities {
    class DummyEntity :
        public CharacterEntity
    {
    private:
        std::string name;
        std::shared_ptr<weapons::Weapon> weaponToPickUp;
    public:

        DummyEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name = "DummyEntity");
    };
    ;
}
