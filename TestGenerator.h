#pragma once
#include "DungeonGenerator.h"
class TestGenerator :
    public DungeonGenerator
{
public:
	void generate(GameClient& client) override;
};

