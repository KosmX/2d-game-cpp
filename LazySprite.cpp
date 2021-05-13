#include "LazySprite.h"
#include "olcPGEX_TransformedView.h"
#include "ResourceManager.h"

namespace render {
	olc::Decal* LazySprite::getDecay()
	{
		if (sprite == nullptr) {
			this->sprite = ResourceManager::getSprite(this->resourceName);
		}
		return this->sprite;
	}


	LazySprite::LazySprite(const std::string& resName)
		: sprite(nullptr), resourceName(resName)
	{}

	void LazySprite::render(olc::TransformedView& scene, const olc::vf2d& pos, const olc::vf2d& uv, const olc::vf2d& size, olc::vf2d scale)
	{
		scene.DrawPartialDecal(pos, this->getDecay(), uv, size, scale);
	}
	

	void LazySprite::renderCentered(olc::TransformedView& scene, const olc::vf2d& pos, const olc::vf2d& uv, const olc::vf2d& size, olc::vf2d scale)
	{
		this->render(scene, pos - scale / 2.0f, uv, size, scale);
	}
}
