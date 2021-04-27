#pragma once

#include <string>
#include <map>
#include <memory>
#include "olcPixelGameEngine.h"

namespace render
{
	class SpriteManager;

	/**
	 * Load every sprite only once,
	 */
	class ResourceManager
	{
	private: //static
		static std::unique_ptr<ResourceManager> instance;
		static ResourceManager& getInstance(); //who needs that???
	
	public: //static
		
		/**
		 * Todo add parameters
		 */
		static void createInstance(std::string* parent = nullptr);

		static olc::Decal* getSprite(const std::string& key);

	private:

		const std::string parentFolder;
		ResourceManager(std::string* parent, olc::ResourcePack *pack = nullptr);
		ResourceManager(const ResourceManager& other) = default; //make it private... I won't copy it.
		std::map<std::string, SpriteManager*> resourceMap;
		olc::ResourcePack* pack;
	public:
		olc::Decal* getDecal(const std::string& string);
		//olc::Decal* operator[](std::string* key);
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
