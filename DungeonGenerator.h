#pragma once

class GameClient;

/**
 * Generate random dungeons...
 */
class DungeonGenerator
{
public:
	virtual void generate(GameClient& client) = 0;
};

