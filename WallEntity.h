#pragma once

#include "Entity.h"

#include "WallTexture.h"

namespace entities {
	/**
	 * @brief Just a stupid wall, it doesn't do much, can't be killed...
	*/
	class WallEntity : public Entity
	{
	public:
		static render::WallTexture simpleWallTexture;
		static render::WallTexture simpleGreenWallTexture;
		
	private:
		/**
		 * @brief How much neighbours does it have
		 * 16 possible states
		*/
		char neighbourID;
		render::WallTexture& usedTexture;

	protected:
		/**
		 * @brief Calculate the neighbour id
		 * @param client the cliet
		*/
		virtual void updateNeighbours(GameClient& client);
		render::ITexture& getTexture() override;
		olc::vf2d getHitBoxSize() const override;
	public:

		explicit WallEntity(const olc::vf2d& pos, render::WallTexture& texture = simpleWallTexture);
		/**
		 * @brief Init, before tick, used to calculate neighbours
		 * @param client 
		*/
		void init(GameClient& client) override;

		bool damage(int damage, Entity& attacker) override;

		/**
		 * @brief Accessor for neighbourID
		 * @return 42
		*/
		virtual char getNeighbourID() const;

		//This is a wall entity after all.
	};
}
