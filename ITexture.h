#pragma once

#include "olcPGEX_TransformedView.h"
#include "LazySprite.h"

namespace entities {
	class Entity;
}

namespace render
{
	/**
	 * @brief Every texture, what can render an entity
	*/
	class ITexture
	{
	public:

		/**
		 * @brief Render the sprite, abstract function
		 * @param scene view description
		 * @param entity entity to render with this texture
		*/
		virtual void render(olc::TransformedView& scene, entities::Entity& entity) = 0;

		/**
		 * @brief mostly not needed, but I can never know it
		*/
		virtual ~ITexture() = default;
	};
}

