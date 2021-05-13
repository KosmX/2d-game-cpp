#pragma once
#include "olcPixelGameEngine.h"
#include "DynamicArray.hpp"
#include <memory>
#include "Entity.h"
#include "PlayerEntity.h"

/**
 * @brief The game main class itself. manages the entities, adjust the screen... 
*/
class GameClient :
    public olc::PixelGameEngine
{
private:
	static GameClient* instance;
	/**
	 * @brief create a new singleton instance
	 * @param debug debug enabled
	 * @return the created GameClient
	*/
	static GameClient& createInstance(bool debug);
	//I want it to me a singleton, but I don't want to let anything init this
	friend int main(int, char* []);
	olc::vf2d viewArea = {-2, -2};
	//olc::vf2d viewScale = {2, 2};
	bool debug;
	/**
	 * @brief The scene
	*/
	olc::TransformedView scene;
	/**
	 * @brief The main player. or a reference to the main player
	*/
	std::shared_ptr<entities::PlayerEntity>	player;
	void updateWorldOffset(float dTick);
	/**
	 * @brief Renders the status-bar
	 * @bug it renders the status behind other things. I should fix that
	*/
	void renderStatus();
	void renderStatusLine(int i, float f, const olc::Pixel& pixel);
public:
	static GameClient& getInstance();

// real class stuff
private:
	DynamicArray<std::shared_ptr<entities::Entity>> entities;

	
public:
	GameClient(bool debug = false);

	DynamicArray<std::shared_ptr<entities::Entity>>& getEntities();

	/**
	 * @brief Create a new game instance
	 * @return 
	*/
	bool OnUserCreate() override;
	/**
	 * @brief Update the game
	 * @param fElapsedTime the length of the last tick
	 * @return false, if the game can quit
	*/
	bool OnUserUpdate(float fElapsedTime) override;
	/**
	 * @brief turn on debug, caused by an exception
	 * @param bl true
	*/
	void setDebugMode(bool bl = true);
	/**
	 * @brief Add a new entity to the world. you can also use += 
	 * @param entity entity
	*/
	void addEntity(std::shared_ptr<entities::Entity>& entity);
	/**
	 * @brief Get the screen details. needed in fire direction calculation
	 * @return the scene
	*/
	const olc::TransformedView& getScene(); //for some reason
	/**
	 * @brief Add an entity to the world.
	 * @param entity the entity
	 * @return GameClient
	*/
	GameClient& operator+=(std::shared_ptr<entities::Entity> entity);

	/**
	 * @brief Get the main player
	 * @return the PlayerEntity
	*/
	std::shared_ptr<entities::PlayerEntity> getPlayerEntity();
	//for some reason, probably I won't need it
	//bool OnUserDestroy() override;
};

