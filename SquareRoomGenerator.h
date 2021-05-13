#pragma once
#include "DungeonGenerator.h"
class SquareRoomGenerator :
    public DungeonGenerator
{
public:
	std::shared_ptr<entities::PlayerEntity> generate(GameClient& client) override;
};

