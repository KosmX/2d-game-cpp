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
	static GameClient& createInstance(bool debug);
	//I want it to me a singleton, but I don't want to let anything init this
	friend int main(int, char* []);
	olc::vf2d viewArea = {-2, -2};
	//olc::vf2d viewScale = {2, 2};
	bool debug;
	olc::TransformedView scene;
public:
	static GameClient& getInstance();

// real class stuff
private:
	DynamicArray<std::shared_ptr<entities::Entity>> entities;

	
public:
	GameClient(bool debug = false);

	DynamicArray<std::shared_ptr<entities::Entity>>& getEntities();
	
	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	void setDebugMode(bool bl = true);
	
	void addEntity(std::shared_ptr<entities::Entity>& entity);

	GameClient& operator+=(std::shared_ptr<entities::Entity> entity);
 
	//for some reason, probably I won't need it
	//bool OnUserDestroy() override;
};

