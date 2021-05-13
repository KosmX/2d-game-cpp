#pragma once
#include "CharacterEntity.h"
#include <vector>

namespace entities {

    /**
     * @brief You, or the player
    */
    class PlayerEntity :
        public CharacterEntity
    {
    private:
        /**
         * @brief It can hold maximum n weapons
        */
        static const int maxWeapons = 3;
        std::string name;
        /**
         * @brief internal variable
        */
        std::shared_ptr<weapons::Weapon> weaponToPickUp;
        /**
         * @brief array, storing the weapons
        */
        std::shared_ptr<weapons::Weapon> weapons[maxWeapons];
        /**
         * @brief Selected weapon slot. circular, 0->1->2->0...
        */
        int selectedSlot = 0;
        /**
         * @brief max health, for HP regen upper limit and status bar
        */
        float maxHealth = 200;
        /**
         * @brief HP regen cooldown
        */
        float lastDamage = 0;
    public:
        /**
         * @brief Get selected weapon
         * @return nullptr if has no selected weapon
        */
        std::shared_ptr<weapons::Weapon> getWeapon() override;
        /**
         * @brief Tick the entity, read the control keys, HP regen logic, etc...
         * @param client client
         * @param deltaT fElapsedTime
         * @param shared_this this
        */
        void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this) override;
        PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name = "Player");

        /**
         * @brief Constant weapon getter
         * @return idk
        */
        const std::shared_ptr<weapons::Weapon>& getWeapon() const;
    	/**
    	 * @brief Ouch
    	 * @param damage that hurt
    	 * @param attacker the bad guy
    	 * @return :D
    	*/
    	bool damage(int damage, Entity& attacker) override;
        /**
         * @brief Sorry for these very meaningless descriptions
         * @return 0-1 float, hp in percents.
        */
        float getHealthStatus();
    };
}
