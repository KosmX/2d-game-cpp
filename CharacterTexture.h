#pragma once
#include "ITexture.h"

namespace render {
    /**
     * @brief Texture for CharacterEntities.
    */
    class CharacterTexture :
        public ITexture
    {
    public:
        static CharacterTexture EngineerTexture;
        static CharacterTexture MageTexture;
        static CharacterTexture PaladinTexture;
        static CharacterTexture WarriorTexture;
        static CharacterTexture RougeTexture;
		//TODO add the others
    private:
        LazySprite sprite;
        const olc::vf2d uv, size;
    public:

        CharacterTexture(const std::string& name, olc::vf2d size = {16, 16});

    	/**
    	 * @brief Throws a GameException, if we try to render a non-character entity with it
    	 * @param scene scene
    	 * @param entity a CharacterEntity
    	*/
    	void render(olc::TransformedView& scene, entities::Entity& entity) override;
    };
}
