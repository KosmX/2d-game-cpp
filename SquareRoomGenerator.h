#pragma once
#include "DungeonGenerator.h"
/**
 * @brief Generates a weird square dungeon, filled with stupid enemies and weapons
*/
class SquareRoomGenerator :
    public DungeonGenerator
{
public:
	std::shared_ptr<entities::PlayerEntity> generate(GameClient& client) override;
};

