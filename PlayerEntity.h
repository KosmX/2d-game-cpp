#pragma once
#include "CharacterEntity.h"
#include <vector>

namespace entities {

    class PlayerEntity :
        public CharacterEntity
    {
    private:
        static const int maxWeapons = 3;
        std::string name;
        std::shared_ptr<weapons::Weapon> weaponToPickUp;
        std::shared_ptr<weapons::Weapon> weapons[maxWeapons];
        int selectedSlot = 0;

    protected:
        std::shared_ptr<weapons::Weapon> getWeapon() override;
    public:
        void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
        PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name = "Player");

        const std::shared_ptr<weapons::Weapon>& getWeapon() const;
    };
}
