#include "WallEntity.h"

#include "mainGame.h"

using namespace olc;

void entities::WallEntity::updateNeighbours()
{
	this->neighbourID = 0;
	for (auto& entity : client.getEntities()) {
		if (entity->getAsWallEntity() != nullptr) {
			WallEntity& wallEntity = *entity->getAsWallEntity();
			vi2d distance = entity->getPos() - this->getPos();
			if (abs(distance.x) == 1 && abs(distance.y) == 0) {
				neighbourID |= distance.x == 1 ? 0b0100 : 0b1000;
			}
			else if (abs(distance.x) == 0 && abs(distance.y) == 1) {
				neighbourID |= distance.x == 1 ? 0b01 : 0b10;
			}
		}
	}
}

void entities::WallEntity::init(GameClient& client)
{
	this->updateNeighbours();
}

byte entities::WallEntity::getNeighbourID() const
{
	return neighbourID;
}
