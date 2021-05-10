#include "mainGame.h"
#include "ResourceManager.h"
#include <algorithm>
#include "GameException.h"
#include "TestGenerator.h"

const float maxTimeDelta = 0.05f;
using namespace std;
using namespace entities;
using namespace olc;

const float screenMoveScale = 8;
const int worldToScreenScale = 16;

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

void GameClient::updateWorldOffset(float dTick)
{
	vf2d delta = scene.GetWorldOffset() + this->GetScreenPixelSize()/2.f + vf2d(4, 0);
	scene.MoveWorldOffset((player->getPos() - delta) * dTick * screenMoveScale);
}

GameClient& GameClient::getInstance()
{
	return *instance;
}

bool GameClient::OnUserCreate()
{

	//Set resource parent!
	render::ResourceManager::createInstance();

	scene.Initialise(this->GetScreenPixelSize(), {worldToScreenScale, worldToScreenScale}); // uh. idk. maybe that's the best option
	
	TestGenerator generator;
	player = generator.generate(*this);

	
	return true;
}

bool GameClient::OnUserUpdate(float fElapsedTime)
{

	
	fElapsedTime = std::min(maxTimeDelta, fElapsedTime);
	//return false if it want to exit.

	for(std::shared_ptr<Entity>& entity : this->getEntities()){
		entity->tick(*this, fElapsedTime, entity);
	}

	auto iterator = entities.finalizeAdd();
	
	while (iterator != entities.end()){
		iterator++->get()->init(*this);
	}

	//lambda remove condition. because why not?
	entities.removeIf([](const shared_ptr<Entity>& entity)->bool
		{
			return !entity->isAlive();
		});

	this->updateWorldOffset(fElapsedTime);
	
	
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
		//scene.DrawCircle({ 0, 0 }, 1);
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