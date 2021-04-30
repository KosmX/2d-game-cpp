#pragma once
#include "olcPixelGameEngine.h"
#include "DynamicArray.hpp"
#include <memory>
#include "Entity.h"


class GameClient :
    public olc::PixelGameEngine
{
private:
	DynamicArray<std::shared_ptr<entities::Entity>> basicEntities;
public:
	GameClient();

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

	~GameClient();
	
	//for some reason, probably I won't need it
	//bool OnUserDestroy() override;
};

