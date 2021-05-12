#pragma once

#include "olc.h"
#include "ITexture.h"

class GameClient;

namespace entities {

	class WallEntity;
	class LivingEntity;

	class Entity
	{
	protected:
		olc::vf2d pos; //I can store these safely directly
		virtual render::ITexture& getTexture() = 0;

		virtual olc::vf2d getHitBoxSize() const = 0;
		virtual olc::vf2d getCollision(const Entity& other);
		bool is_initialized;
		bool is_alive; //walls shouldn't have variables like this. But it will be an intended bug.
	public:

		explicit Entity(const olc::vf2d& pos);

		virtual void init(GameClient& client){}
		virtual bool isInitialized();

		//nodiscard???
		[[nodiscard]] virtual olc::vf2d getPos() const;
		[[nodiscard]] virtual olc::vf2d getSize() const;
		[[nodiscard]] virtual bool isAlive() const;
		[[nodiscard]] virtual bool canBeRemoved() const;

		virtual void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this){}

		/**
		 * @param damage how much damage should it take
		 * @param attacker who deal the damage. not the projectile, the entity
		 * @return did the entity take the damage or no (like a wall)
		 */
		virtual bool damage(int damage, Entity& attacker) = 0;
		//this shouldn't change it's state
		virtual void render(olc::TransformedView& scene);

		virtual std::string getName() const;
		
		virtual ~Entity() = default;


		

		virtual operator WallEntity* (){
			return nullptr;
		}
	};


}

/**
 * I literally add entities to the scene :D
 */
olc::TransformedView& operator+=(olc::TransformedView&, entities::Entity&);
olc::TransformedView& operator+=(olc::TransformedView&, std::shared_ptr<entities::Entity>&);