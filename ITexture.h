#pragma once
#include "Entity.h"
#include "olcPGEX_TransformedView.h"

namespace render
{

	class ITexture
	{
	public:

		//Giving the entity will reduce the variables needed, and will make it's use more dynamic
		virtual void render(olc::TransformedView& scene, Entity& entity) = 0;
		
		virtual ~ITexture() = default;
	};
}

