#include "mainGame.h"
#include "ResourceManager.h"
#include <algorithm>
#include "GameException.h"
#include "TestGenerator.h"
#include "Weapon.h"

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

void GameClient::renderStatusLine(int i, float f, const olc::Pixel& pixel)
{
	DrawLine(vf2d(0, i + 0.f), vf2d( 128.f * f, i ), pixel);
	DrawLine(vf2d(0, i + 1.f), vf2d( 128.f * f, i + 1 ), pixel);
}

void GameClient::renderStatus()
{
	SetDrawTarget(1);

	float health = this->player->getHealthStatus();
	if (this->player->getWeapon()) {
		float weapon = 0;
		float weapon2 = 0;
		shared_ptr<weapons::Weapon> wep = this->player->getWeapon();
		weapon = wep->getCooldownBar();
		weapon2 = wep->getSecondaryBar();
		renderStatusLine(4, weapon, WHITE);
		renderStatusLine(6, weapon2, BLUE);
	}

	renderStatusLine(0, health, RED);
	
	
	SetDrawTarget(static_cast<uint8_t>(0));
}


bool GameClient::OnUserUpdate(float fElapsedTime)
{
	Clear(BLACK);
	
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
			return entity->canBeRemoved();
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

	renderStatus();
	
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

void GameClient::addEntity(std::shared_ptr<Entity>& entity)
{
	this->entities.operator+=(entity);
}

const olc::TransformedView& GameClient::getScene()
{
	return scene;
}

GameClient& GameClient::operator+=(std::shared_ptr<Entity> entity)
{
	this->addEntity(entity);
	return *this;
}

GameClient* GameClient::instance = nullptr;