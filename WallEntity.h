#pragma once

#include "Entity.h"

namespace entities {
	class WallEntity : public Entity
	{
	public:




		//This is a wall entity after all.
		WallEntity* getAsWallEntity() override
		{
			return this;
		}
	};

}
