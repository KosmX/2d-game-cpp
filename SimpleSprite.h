#pragma once
#include "ITexture.h"
#include <string>
#include "LazySprite.h"

namespace render {

	class SimpleSprite :
		public ITexture
	{
	private:
		LazySprite sprite;
		const olc::vf2d uv, size;
	
	public:
		SimpleSprite(const std::string& name, const olc::vi2d& pos, const olc::vf2d& size = {16, 16});

		void render(olc::TransformedView& scene, entities::Entity& entity) override;
	};
}

