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

	public:
		SimpleSprite(const std::string name, olc::vi2d pos);

		void render(olc::TransformedView& scene, entities::Entity& entity) override;
	};
}

