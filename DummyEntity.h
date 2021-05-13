#pragma once
#include "CharacterEntity.h"

namespace entities {
    /**
     * @brief A test/dummy entity. it can't do anything... no, it can die
    */
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
