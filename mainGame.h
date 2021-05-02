#pragma once
#include "olcPixelGameEngine.h"
#include "DynamicArray.hpp"
#include <memory>
#include "Entity.h"


class GameClient :
    public olc::PixelGameEngine
{
private:
	static GameClient* instance;
	static GameClient& createInstance();
	//I want it to me a singleton, but I don't want to let anything init this
	friend int main(int, char* []);
public:
	static GameClient& getInstance();

// real class stuff
private:
	DynamicArray<std::shared_ptr<entities::Entity>> entities;

	
public:
	GameClient();

	DynamicArray<std::shared_ptr<entities::Entity>>& getEntities();
	
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	
	//for some reason, probably I won't need it
	//bool OnUserDestroy() override;
};

