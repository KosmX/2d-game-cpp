#include "mainGame.h"
#include "ResourceManager.h"
#include <algorithm>
#include "GameException.h"
#include "TestGenerator.h"

const float maxTimeDelta = 0.05f;
using namespace std;
using namespace entities;
using namespace olc;

GameClient& GameClient::createInstance(bool debug)
{
	instance = new GameClient(debug);
	return *instance;
}

GameClient::GameClient(bool debug)
	: debug(debug)
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

	scene.Initialise(this->GetWindowSize(), {16, 16}); // uh. idk. maybe that's the best option
	
	TestGenerator generator;
	generator.generate(*this);

	
	return true;
}

bool GameClient::OnUserUpdate(float fElapsedTime)
{

	
	fElapsedTime = std::min(maxTimeDelta, fElapsedTime);
	//return false if it want to exit.

	for(std::shared_ptr<Entity>& entity : this->getEntities()){
		entity->tick(*this, fElapsedTime);
	}

	entities.finalizeAdd();
	for(auto &entity : entities){
		if(!entity->isInitialized()){
			entity->init(*this);
		}
	}

	//lambda remove condition. because why not?
	entities.removeIf([](const shared_ptr<Entity>& entity)->bool
		{
			return !entity->isAlive();
		});

	scene.SetWorldOffset(this->viewArea);
	
	for(auto& entity : entities){
		// I literally add entities to the scene :D
		try {
			scene += entity;
		}
		catch (GameException& exception){
			std::cout << "Exception has occur while rendering entity: " << exception.what();
		}
	}

	//debug section
	if (debug) {
		scene.DrawCircle({ 0, 0 }, 1);
		cout << entities.getSize() << " was ticked" << endl;
	}
	return true;
}

void GameClient::setDebugMode(bool bl)
{
	this->debug = bl;
}

void GameClient::addEntity(std::shared_ptr<entities::Entity>& entity)
{
	this->entities.operator+=(entity);
}

GameClient& GameClient::operator+=(std::shared_ptr<entities::Entity> entity)
{
	this->addEntity(entity);
	return *this;
}

GameClient* GameClient::instance = nullptr;