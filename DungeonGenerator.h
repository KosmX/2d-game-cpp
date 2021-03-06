#pragma once
#include <memory>

namespace entities {
	class PlayerEntity;
}

class GameClient;

/**
 * @brief Generate random dungeons...
 */
class DungeonGenerator
{
public:
	virtual std::shared_ptr<entities::PlayerEntity> generate(GameClient& client) = 0;
};

