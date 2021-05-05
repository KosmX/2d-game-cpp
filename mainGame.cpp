#include "mainGame.h"
#include "ResourceManager.h"
#include <algorithm>

const float maxTimeDelta = 0.05f;
using namespace std;
using namespace entities;

GameClient& GameClient::createInstance()
{
	instance = new GameClient();
	return *instance;
}

GameClient::GameClient()
{
	this->sAppName = "KosmX's game";
}

DynamicArray<std::shared_ptr<entities::Entity>>& GameClient::getEntities()
{
	return this->entities;
}

GameClient& GameClient::getInstance()
{
	return *instance;
}

bool GameClient::OnUserCreate()
{

	//Set resource parent!
	render::ResourceManager::createInstance();

	
	
	return true;
}

bool GameClient::OnUserUpdate(float fElapsedTime)
{
	fElapsedTime = std::min(maxTimeDelta, fElapsedTime);
	//return false if it want to exit.

	for(std::shared_ptr<Entity> entity : this->getEntities()){
		entity->tick(*this, fElapsedTime);
	}

	entities.finalizeAdd();
	for(auto &entity : entities){
		if(!entity->isInitialized()){
			entity->init(*this);
		}
	}
	return true;
}

GameClient* GameClient::instance = nullptr;