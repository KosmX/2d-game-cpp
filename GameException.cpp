#include "GameException.h"

GameException::GameException(const std::string& description, entities::Entity& entity)
	: runtime_error(description), affectedEntity(entity) {}
