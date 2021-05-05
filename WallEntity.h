#pragma once

#include "Entity.h"

namespace entities {
	class WallEntity : public Entity
	{
	private:
		byte neighbourID;

	protected:
		virtual void updateNeighbours();
	public:

		void init(GameClient& client) override;
		
		virtual byte getNeighbourID() const;

		//This is a wall entity after all.
		WallEntity* getAsWallEntity() override
		{
			return this;
		}
	};

}
