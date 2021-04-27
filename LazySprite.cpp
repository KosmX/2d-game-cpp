#include "LazySprite.h"
#include "olcPGEX_TransformedView.h"
#include "ResourceManager.h"

namespace render {
	olc::Decal* LazySprite::getDecay()
	{
		if (sprite == nullptr) {
			this->sprite = render::ResourceManager::getSprite(this->resourceName);
		}
		return this->sprite;
	}

	LazySprite::LazySprite(int u, int v, int sizeU, int sizeV)
		: LazySprite(olc::vi2d(u, v), olc::vi2d(sizeU, sizeV))
	{}
	LazySprite::LazySprite(olc::vi2d pos, olc::vi2d size)
		: uv(pos), size(size)
	{
		sprite = nullptr;
	}

	
	void LazySprite::render(olc::TransformedView& scene, olc::vf2d pos, olc::vf2d scale)
	{
		scene.DrawPartialDecal(pos, this->getDecay(), uv, size, scale);
	}
	void LazySprite::renderCentered(olc::TransformedView& scene, olc::vf2d pos, olc::vf2d scale)
	{
		//probably modify the ints to doubles???
		render(scene, pos + size*2.0, scale);
	}
}
