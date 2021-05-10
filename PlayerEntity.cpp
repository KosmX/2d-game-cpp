#include "PlayerEntity.h"

#include "mainGame.h"

using namespace olc;

namespace entities {

	render::ITexture& PlayerEntity::getTexture()
	{
		return this->texture;
	}

	void PlayerEntity::tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this)
	{
		vf2d newSpeed = { 0, 0 };
		if (client.GetKey(olc::Key::A).bHeld) newSpeed += {-1, 0};
		if (client.GetKey(olc::Key::S).bHeld) newSpeed += {0, 1};
		if (client.GetKey(olc::Key::D).bHeld) newSpeed += {1, 0};
		if (client.GetKey(olc::Key::W).bHeld) newSpeed += {0, -1};
		this->speed = newSpeed == vf2d(0, 0) ? newSpeed : newSpeed.norm() * 6;
		LivingEntity::tick(client, deltaT, shared_this);
	}

	PlayerEntity::PlayerEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name)
		: LivingEntity(pos), name(name), texture(skin)
	{

	}
}