#pragma once
#include "ITexture.h"
#include <string>
#include "LazySprite.h"

namespace render {

	/**
	 * @brief Simplest useable texture
	*/
	class SimpleSprite :
		public ITexture
	{
	private:
		/**
		 * @brief The sprite it is referring
		*/
		LazySprite sprite;
		/**
		 * @brief image in the sprite
		*/
		const olc::vf2d uv, size;
	
	public:
		SimpleSprite(const std::string& name, const olc::vi2d& pos = { 0, 0 }, const olc::vf2d& size = { 16, 16 });

		void render(olc::TransformedView& scene, entities::Entity& entity) override;
	};
}

