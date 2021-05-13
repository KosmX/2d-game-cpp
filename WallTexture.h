#pragma once
#include "ITexture.h"
#include <map>


namespace render
{
	/**
	 * @brief Texture to render walls, with 16 possible states
	*/
	class WallTexture :
		public ITexture
	{
	private:
		LazySprite sprite;
		const olc::vf2d baseOffset, size;
	protected:
		/**
		 * @brief map, witch state means what coordinates in the sprite
		*/
		static const std::map<byte, olc::vi2d> offsetMap;
	public:
		WallTexture(const std::string& resName, const olc::vf2d& baseOffset, const olc::vf2d& size = olc::vf2d(16, 16));
		void render(olc::TransformedView& scene, entities::Entity& entity) override;
	};
}
