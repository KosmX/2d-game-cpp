#pragma once
#include "DungeonGenerator.h"

/**
 * @brief Used for testing, doesn't random
*/
class TestGenerator :
    public DungeonGenerator
{
public:
	std::shared_ptr<entities::PlayerEntity> generate(GameClient& client) override;
};

