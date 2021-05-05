#pragma once

#include "olcPGEX_TransformedView.h"
#include "LazySprite.h"

namespace entities {
	class Entity;
}

namespace render
{

	class ITexture
	{
	public:

		//Giving the entity will reduce the variables needed, and will make it's use more dynamic
		virtual void render(olc::TransformedView& scene, entities::Entity& entity) = 0;
		
		virtual ~ITexture() = default;
	};
}

