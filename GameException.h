#pragma once
#include <stdexcept>

namespace entities
{
	class Entity;
}

class GameException :
    public std::runtime_error
{
private:
	entities::Entity& affectedEntity;
public:
	GameException(const std::string& description, entities::Entity& entity);
};

