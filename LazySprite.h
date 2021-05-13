#pragma once

#include <string>
#include "olcPixelGameEngine.h"
#include "olcPGEX_TransformedView.h"

namespace render {

	/**
	 * @brief Refer to one texture, not animated, not modifiable, just a simple image.
	 * Lazy loading means, it will load it only, when you're trying to use it.
	 */
	class LazySprite
	{
	private:
		olc::Decal* sprite;

	protected:
		const std::string resourceName;
		//int const u, v, sizeU, sizeV;
		//olc::vi2d const uv, size;
		/**
		 * @brief get an old::Decal
		 */
		olc::Decal* getDecal();
	public:
		/**
		 * u, v the texture coordinates on the image,
		 * sizeU, V are the size of that sprite
		 */
		explicit LazySprite(const std::string& resName);

		/**
		 * @brief Renders the sprite into the world
		 * @param scene olc::TransformedView scene
		 * @param pos the in-world pos
		 * @param uv texture uv pos
		 * @param size texture size
		 * @param scale scale, 1 by default
		*/
		void render(olc::TransformedView& scene, const olc::vf2d& pos, const olc::vf2d& uv, const olc::vf2d& size, olc::vf2d scale = olc::vf2d(1, 1));

		/**
		 * @brief Render, but pos in the center
		 * @param scene olc::TransformedView scene
		 * @param pos the in-world pos
		 * @param uv texture uv pos
		 * @param size texture size
		 * @param scale scale, 1 by default
		*/
		void renderCentered(olc::TransformedView& scene, const olc::vf2d& pos, const olc::vf2d& uv, const olc::vf2d& size, olc::vf2d scale = olc::vf2d(1, 1));

		//decal reference is not my stuff, I don't have to delete it.
	};
}
