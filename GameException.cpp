#include "GameException.h"

#include <iostream>
#include "mainGame.h"

GameException::GameException(const std::string& description, entities::Entity& entity)
	: runtime_error(description), affectedEntity(entity)
{
	std::cout << "An exception was thrown, turning on debug mode" << std::endl;
	GameClient::getInstance().setDebugMode(true);
}
