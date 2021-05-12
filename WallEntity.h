#pragma once

#include "Entity.h"

#include "WallTexture.h"

namespace entities {
	class WallEntity : public Entity
	{
	public:
		static render::WallTexture simpleWallTexture;
		static render::WallTexture simpleGreenWallTexture;
		
	private:
		byte neighbourID;
		render::WallTexture& usedTexture;

	protected:
		virtual void updateNeighbours(GameClient& client);
		render::ITexture& getTexture() override;
		olc::vf2d getHitBoxSize() const override;
	public:

		explicit WallEntity(const olc::vf2d& pos, render::WallTexture& texture = simpleWallTexture);
		
		void init(GameClient& client) override;

		bool damage(int damage, Entity& attacker) override;
		
		virtual byte getNeighbourID() const;

		//This is a wall entity after all.
	};
}
