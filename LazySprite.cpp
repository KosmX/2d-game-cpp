#include "LazySprite.h"

namespace render {
	olc::Decal& LazySprite::getDecay()
	{
		if (sprite == nullptr) {
			//GET sprite from resource manager
		}
		return *this->sprite;
	}

	LazySprite::LazySprite(int u, int v, int scale, int sizeU, int sizeV)
		: u(u), v(v), scale(scale), sizeU(sizeU), sizeV(sizeV)
	{
		sprite = nullptr;
	}
}
