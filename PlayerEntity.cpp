#include "PlayerEntity.h"

#include "mainGame.h"
#include "Weapon.h"

using namespace olc;

const float maxWeaponPickupRange = 1;

namespace entities {
	std::shared_ptr<weapons::Weapon> PlayerEntity::getWeapon()
	{
		return this->weapons[selectedSlot];
	}
	void PlayerEntity::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		vf2d newSpeed = { 0, 0 };
		if (client.GetKey(olc::Key::A).bHeld) newSpeed += {-1, 0};
		if (client.GetKey(olc::Key::S).bHeld) newSpeed += {0, 1};
		if (client.GetKey(olc::Key::D).bHeld) newSpeed += {1, 0};
		if (client.GetKey(olc::Key::W).bHeld) newSpeed += {0, -1};
		this->speed = newSpeed == vf2d(0, 0) ? newSpeed : newSpeed.norm() * 6;

		if(client.GetKey(SPACE).bHeld && this->getWeapon()) // TODO mouse button ?!
		{
			vf2d mouse = client.getScene().ScreenToWorld(client.GetMousePos());
			mouse -= this->getPos();
			mouse = mouse.norm();
			this->getWeapon()->use(shared_this, mouse);
		}

		this->weaponToPickUp = nullptr;
		for(int i = 0; i < maxWeapons; i++){
			if(weapons[i]){
				weapons[i]->update(deltaT);
			}
		}
		
		for(auto& entity : client.getEntities()){
			if(std::dynamic_pointer_cast<weapons::Weapon>(entity) && (entity->getPos() - getPos()).mag() < maxWeaponPickupRange){
				weaponToPickUp = std::dynamic_pointer_cast<weapons::Weapon>(entity);
				break;
			}
		}

		if(client.GetKey(TAB).bPressed){
			if (weaponToPickUp != nullptr) {
				weaponToPickUp->setPickUp(true);
				if (this->getWeapon() != nullptr) {
					this->getWeapon()->setPickUp(false);
					std::shared_ptr<Entity> tmp = this->getWeapon();
					client.addEntity(tmp);
				}
				this->weapons[selectedSlot] = weaponToPickUp;
				weaponToPickUp = nullptr;
			}
		}

		int mouseWheel = client.GetMouseWheel();
		if(mouseWheel != 0){
			if(mouseWheel > 0){
				this->selectedSlot = (selectedSlot + 1)%maxWeapons;
			}
			else{
				if(--this->selectedSlot < 0){
					selectedSlot = maxWeapons - 1;
				}
			}
		}
		
		CharacterEntity::tick(client, deltaT, shared_this); //super.tick();
	}

	PlayerEntity::PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name)
		: CharacterEntity(skin, pos), name(name)
	{
		this->health = maxHealth;
	}
	const std::shared_ptr<weapons::Weapon>& PlayerEntity::getWeapon() const
	{
		return this->weapons[selectedSlot];
	}
	float PlayerEntity::getHealthStatus()
	{
		return health/maxHealth;
	}
}