#pragma once

#include "olc.h"
#include "ITexture.h"

class GameClient;

namespace entities {

	class WallEntity;

	class Entity
	{
	protected:
		olc::vf2d pos; //I can store these safely directly
		virtual render::ITexture& getTexture() = 0;

		virtual olc::vf2d getHitBoxSize() const = 0;
		virtual olc::vf2d getCollision(const Entity& other);
		bool is_initialized;
	public:
		
		Entity(const olc::vf2d& pos);

		virtual void init(GameClient& client){}
		virtual boolean isInitialized();

		//nodiscard???
		[[nodiscard]] virtual olc::vf2d getPos() const;
		[[nodiscard]] virtual olc::vf2d getSize() const;

		virtual void tick(GameClient& client, float deltaT){}

		//this shouldn't change it's state
		virtual void render(olc::TransformedView& scene);

		virtual ~Entity() = default;

		//TODO getAs*** stuff, all virtual
		//same purpose to dynamic_cast, but without using language server
		virtual WallEntity* getAsWallEntity()
		{
			return nullptr;
		}
		
	};


}

/**
 * I literally add entities to the scene :D
 */
olc::TransformedView& operator+=(olc::TransformedView&, entities::Entity&);