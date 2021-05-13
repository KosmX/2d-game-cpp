#pragma once

#include <string>
#include "olcPixelGameEngine.h"

namespace render
{
	
	class SpriteManager;

	/**
	 * @brief Load every sprite only once, act as a set for loaded textures
	 */
	class ResourceManager
	{
	private: //static
		static ResourceManager* instance;
		static ResourceManager& getInstance(); //who needs that???
	
	public: //static
		
		/**
		 * Todo add parameters
		 */
		static void createInstance(std::string* parent = nullptr);

		/**
		 * @brief get a sprite, it it's already loaded, doesn't load it again
		 * @param key string sprite key
		 * @return the sprite
		*/
		static olc::Decal* getSprite(const std::string& key);

	private:

		const std::string parentFolder;
		ResourceManager(std::string* parent, olc::ResourcePack *pack = nullptr);
		ResourceManager(const ResourceManager& other) = default; //make it private... I won't copy it.
		/**
		 * @brief The map of the sprites
		*/
		std::map<std::string, SpriteManager*> resourceMap;
		olc::ResourcePack* pack;
	public:
		/**
		 * @brief used by GetSprite
		 * @param string asd
		 * @return the sprite
		*/
		olc::Decal* getDecal(const std::string& string);
		//olc::Decal* operator[](std::string* key);
		/**
		 * @brief indexing operator :D
		 */
		olc::Decal* operator[](const std::string& key);
		
		~ResourceManager();
	};



	
	//I won't update sprites or decals (probably)
	class SpriteManager
	{
	private: //First I have to create the sprite then I can use a decal linking to a sprite --PGE docs
		olc::Sprite spriteData;
		olc::Decal decalData;
	public:
		SpriteManager(std::string& resourceLocation, olc::ResourcePack* pack);
		olc::Decal* getDecal();
	};
}
