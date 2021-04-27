#pragma once

#include <string>
#include "olcPixelGameEngine.h"
#include "olcPGEX_TransformedView.h"

namespace render {

	/**
	 * Refer to one texture, not animated, not modifiable, just a simple image.
	 * Lazy loading means, it will load it only, when you're trying to use it.
	 */
	class LazySprite
	{
	private:
		olc::Decal* sprite = nullptr;

	protected:
		const std::string resourceName;
		//int const u, v, sizeU, sizeV;
		olc::vi2d const uv, size;
		olc::Decal* getDecay();
	public:
		/**
		 * u, v the texture coordinates on the image,
		 * sizeU, V are the size of that sprite
		 */
		LazySprite(int u, int v, int sizeU, int sizeV);

		/**
		 * Render the sprite in world-space
		 */
		void render(olc::TransformedView& scene, olc::vf2d, olc::vf2d scale);

		void renderCentered(olc::TransformedView& scene, olc::vf2d, olc::vf2d scale);

		//decal reference is not my stuff, I don't have to delete it.
	};
}
