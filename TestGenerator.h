#pragma once
#include "DungeonGenerator.h"
class TestGenerator :
    public DungeonGenerator
{
public:
	std::shared_ptr<entities::PlayerEntity> generate(GameClient& client) override;
};

