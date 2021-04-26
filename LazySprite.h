#pragma once

#include <string>
#include "olcPixelGameEngine.h"

namespace render {

	/**
	 * Handle resource loading, only when it's in use
	 * also upload sprites to the GPU directly.
	 */
	class LazySprite
	{
	private:
		olc::Decal* sprite = nullptr;

	protected:
		const std::string resourceName;
		int u, v, scale, sizeU, sizeV;
		olc::Decal& getDecay();
	public:
		LazySprite(int u, int v, int scale, int sizeU, int sizeV);

		void render(int x, int y);

		void renderCentered(int x, int y);

		//decal reference is not my stuff, I don't have to delete it.
	};
}
