#pragma once
#include "ITexture.h"

namespace render {
    class CharacterTexture :
        public ITexture
    {
    public:
        static CharacterTexture EngineerTexture;
        static CharacterTexture MageTexture;
		//TODO add the others
    private:
        LazySprite sprite;
        const olc::vf2d uv, size;
    public:

        CharacterTexture(const std::string& name, olc::vf2d size = {16, 16});
    	
    	void render(olc::TransformedView& scene, entities::Entity& entity) override;
    };
}
