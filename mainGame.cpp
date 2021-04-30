#include "mainGame.h"
#include "ResourceManager.h"

GameClient::GameClient()
{
	this->sAppName = "KosmX's game";
}

bool GameClient::OnUserCreate()
{

	//Set resource parent!
	render::ResourceManager::createInstance();

	
	
	return true;
}

bool GameClient::OnUserUpdate(float fElapsedTime)
{

	//return false if it want to exit.
	return true;
}

GameClient::~GameClient()
{
	//TODO free anything
}
