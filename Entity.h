#pragma once

#include "olc.h"
#include "ITexture.h"

class GameClient;

namespace entities {

	class WallEntity;
	class LivingEntity;

	/**
	 * @brief Every object, what can be on the map.
	*/
	class Entity
	{
	protected:
		/**
		 * @brief it's position
		*/
		olc::vf2d pos; //I can store these safely directly
		/**
		 * @brief the object's texture
		 * @return the texture
		*/
		virtual render::ITexture& getTexture() = 0;
		/**
		 * @brief half hitbox size
		 * @return hitbox size as a vector
		*/
		virtual olc::vf2d getHitBoxSize() const = 0;
		/**
		 * @brief Calculate collision with another Entity, how much should this entity move, to avoid the collision
		 * @param other the other entity
		 * @return collision vector, 0 if there is no collision
		*/
		virtual olc::vf2d getCollision(const Entity& other);
		/**
		 * @brief well, is initialized
		*/
		bool is_initialized;
		/**
		 * @brief true, if it is alive
		*/
		bool is_alive; //walls shouldn't have variables like this. But it will be an intended bug.
	public:

		explicit Entity(const olc::vf2d& pos);

		virtual void init(GameClient& client){}
		virtual bool isInitialized();

		//nodiscard???
		[[nodiscard]] virtual olc::vf2d getPos() const;
		/**
		 * @brief get it's size to render
		 */
		[[nodiscard]] virtual olc::vf2d getSize() const;
		[[nodiscard]] virtual bool isAlive() const;
		/**
		 * @return can be deleted from the entity list. mostly is dead
		 */
		[[nodiscard]] virtual bool canBeRemoved() const;

		/**
		 * @brief Entity tick multiple times per sec
		 * @param client the game client object
		 * @param deltaT how long take a tick
		 * @param shared_this this as a shared_ptr
		*/
		virtual void tick(GameClient& client, float deltaT, std::shared_ptr<Entity>& shared_this){}

		/**
		 * @brief something damage this
		 * @param damage how much damage should it take
		 * @param attacker who deal the damage. not the projectile, the entity
		 * @return did the entity take the damage or no (like a wall)
		 */
		virtual bool damage(int damage, Entity& attacker) = 0;
		//this shouldn't change it's state
		/**
		 * @brief render
		 */
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