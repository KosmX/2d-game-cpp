#include "PlayerEntity.h"

#include "mainGame.h"
#include "Weapon.h"

using namespace olc;

namespace entities {
	
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

		for(auto& entity : client.getEntities()){
			if(std::dynamic_pointer_cast<weapons::Weapon>(entity)){
				
			}
		}
		
		LivingEntity::tick(client, deltaT, shared_this);
	}

	PlayerEntity::PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name)
		: CharacterEntity(skin, pos), name(name)
	{

	}
}