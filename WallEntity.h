#pragma once

#include "Entity.h"

#include "WallTexture.h"

namespace entities {
	class WallEntity : public Entity
	{
	protected:
		static render::WallTexture simpleWallTexture;
		
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
		
		virtual byte getNeighbourID() const;

		//This is a wall entity after all.
		WallEntity* getAsWallEntity() override
		{
			return this;
		}
	};
}
