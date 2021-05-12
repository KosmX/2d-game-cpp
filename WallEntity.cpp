#include "WallEntity.h"

#include "mainGame.h"

using namespace olc;

namespace entities {
	void WallEntity::updateNeighbours(GameClient& client)
	{
		this->neighbourID = 0;
		for (auto& entity : client.getEntities()) {
			if (std::dynamic_pointer_cast<WallEntity>(entity) != nullptr) {
				auto& wallEntity = dynamic_cast<WallEntity&>(*entity);
				vi2d distance = entity->getPos() - this->getPos();
				if (abs(distance.x) == 1 && abs(distance.y) == 0) {
					neighbourID |= distance.x != 1 ? 0b0100 : 0b1000;
				}
				else if (abs(distance.x) == 0 && abs(distance.y) == 1) {
					neighbourID |= distance.y != 1 ? 0b01 : 0b10;
				}
			}
		}
	}

	render::ITexture& WallEntity::getTexture()
	{
		return this->usedTexture;
	}

	olc::vf2d WallEntity::getHitBoxSize() const
	{
		return olc::vf2d(0.5, 0.5);
	}

	void WallEntity::init(GameClient& client)
	{
		this->updateNeighbours(client);
	}

	WallEntity::WallEntity(const olc::vf2d& pos, render::WallTexture& texture)
		: Entity(pos), usedTexture(texture), neighbourID(0) {}

	bool WallEntity::damage(int damage, Entity& attacker)
	{
		return false;
	}

	byte WallEntity::getNeighbourID() const
	{
		return neighbourID;
	}

	render::WallTexture WallEntity::simpleWallTexture("Objects/Wall.png", { 0, 3 });
	render::WallTexture WallEntity::simpleGreenWallTexture("Objects/Wall.png", { 14, 30 });
}