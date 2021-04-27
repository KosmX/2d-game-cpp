#include "ResourceManager.h"

namespace render
{
	ResourceManager::ResourceManager(std::string* parent, olc::ResourcePack* pack) : parentFolder(parent != nullptr ? *parent : "./"), pack(pack)
	{}

	olc::Decal* ResourceManager::getDecal(const std::string& string)
	{
		if(resourceMap.count(string) == 0){
			std::string tmp(this->parentFolder + string);
			resourceMap[string] = new SpriteManager(tmp, pack);
		}
		return resourceMap[string]->getDecal();
	}

	ResourceManager::~ResourceManager()
	{
		for (auto &element : resourceMap){
			delete element.second;//these are pointers after all;
		}
	}
	
	ResourceManager& render::ResourceManager::getInstance()
	{
		return *instance;
	}

	olc::Decal* ResourceManager::operator[](const std::string& key)
	{
		return this->getDecal(key);
	}


	/**
	 * Todo add parameters
	 */
	void ResourceManager::createInstance(std::string* parent)
	{
		instance = std::make_unique<ResourceManager>(*new ResourceManager(parent));
	}

	olc::Decal* ResourceManager::getSprite(const std::string& key)
	{
		return getInstance()[key];
	}



	//---------------- sprite manager class ----------------
	
	SpriteManager::SpriteManager(std::string& resourceLocation, olc::ResourcePack *pack) : spriteData(resourceLocation, pack), decalData(&spriteData)
	{
		//decalData.Update(); it's unnecessary, as creating it will automatically push it to the GPU
	}

	olc::Decal* SpriteManager::getDecal()
	{
		return &this->decalData;
	}

	//std::unique_ptr<ResourceManager> ResourceManager::instance;
}